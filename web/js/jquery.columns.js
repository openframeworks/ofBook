/**
 * jquery.columns extends the native jQuery css method
 * to be able parse viewport relative units (vh & vw only)
 * and provides a method to quickly create reponsive layouts.
 *
 * Author: Cedric Ruiz
 * Docs: https://github.com/elclanrs/jquery.columns
 * License: MIT
 */
 /*jshint asi:true */
;(function( $, window ) {

  'use strict';

  $.columns = {} // global object

  var $win = $(window)
    , _css = $.fn.css // cache original css method

    // Default options
    , defaults = {
        colsPerRow: 3,
        breakPoints: [ [1024, 95], [2560, 45] ],
        fontSize: [14, 16],
        height: 'auto',
        center: true
      }

// ----------------------------------------------------

  function typeOf( obj ) {
    return {}.toString.call( obj ).match(/\s(\w+)/)[1].toLowerCase()
  }

  function hasViewportUnits( obj ) {
    var has = false
    for ( var o in obj ) {
      if ( /\d[vwh]+/.test( obj[o] ) ) {
        has = true
        break
      }
    }
    return has
  }

  function viewportToPixel( val ) {
    var percent = val.match(/[\d.]+/)[0] / 100
      , unit = val.match(/[vwh]+/)[0]
    return ( unit == 'vh' ? $win.height() : $win.width() ) * percent + 'px'
  }

  function parseProps( props ) {
    var p, prop
    for ( p in props ) {
      prop = props[ p ]
      if ( /\d[vwh]+$/.test( prop ) ) {
        props[ p ] = viewportToPixel( prop )
      }
    }
    return props
  }

// ----------------------------------------------------

  function Columns( el, opts ) {

    var self = this

    this.opts = $.extend( {}, defaults, opts )

    this.$wrap = $(el).addClass('clear')
    this.$cols = null
    this.$firstRowCol = null

    $win.on('resize.columns', function() { self.init() })

    this.init()

  }

  Columns.prototype = {

    init: function() {

      var width = this.getViewportWidth()

      this.$cols = this.$wrap.find('.col').removeAttr('style')
      this.$firstRowCol = this.$cols
        .filter(':first, :nth-child('+ this.getNthCol( this.opts.colsPerRow ) +')')

      this.$cols.css({
        height: this.opts.height,
      })

      this.$firstRowCol.css('clear', 'both')

      this.setColWidth( width )
      this.setMargin( width )
      this.pushCols( width )
      this.$cols.css({
        fontSize: this.getFontRatio() +'vw'
      })

    },

    getNthCol: function( colsPerRow ) {
      return colsPerRow == 1 ? '1n' : colsPerRow == 2 ? 'odd' : colsPerRow + 1 +'n'
    },

    getViewportWidth: function() {

      var bp = this.opts.breakPoints
        , minRes = bp[0][0]
        , maxRes = bp[1][0]
        , minWidth = bp[1][1]
        , maxWidth = bp[0][1]
        , increment = (maxWidth - minWidth) / (maxRes - minRes)
        , curWidth = minWidth + Math.abs( $win.width() - maxRes ) * increment

      return $win.width() > maxRes ? minWidth
        : $win.width() < minRes ? maxWidth
        : curWidth

    },

    getFontRatio: function() {

      var winWidth = $win.width()
        , minFont = this.opts.fontSize[0]
        , maxFont = this.opts.fontSize[1]
        , minFontRatio = (minFont * 100) / winWidth
        , maxFontRatio = (maxFont * 100) / winWidth
        , curFont = (maxFont - minFont) / (maxFontRatio - minFontRatio)

      return curFont > maxFont || minFont == maxFont ? maxFontRatio
        : curFont < minFont ? minFontRatio
        : 1

    },

    getColWidth: function( width ) {
      return ( $win.width() * (width / 100) ) / this.opts.colsPerRow
    },

    setColWidth: function( width ) {
      this.$cols.css({ width: width / this.opts.colsPerRow +'vw' })
    },

    getMarginToLimits: function( width ) {
      return ( $win.width() - ( $win.width() * (width / 100) ) ) / 2
    },

    setMargin: function( width ) {
      if ( this.opts.center ) {
        this.$firstRowCol.css({ marginLeft: (100 - width) / 2 +'vw' })
      }
    },

    pushCols: function( width ) {

      var self = this

      this.$cols.each(function() {

        var $this = $(this)
          , push = ( /push\-(\d)/.exec( this.className ) || [,0] )[1]
          , margin = self.getColWidth( width ) * push
          , totalMargin = self.getMarginToLimits( width ) + margin
          , isFirstCol = self.$firstRowCol.filter( $this ).length

        if ( push ) {
          $this.css({
            marginLeft: ( isFirstCol && self.opts.center ? totalMargin : margin ) +'px'
          })
        }

      })

    }

  }

  $.fn.columns = function( opts ) {
    return this.each(function () {
      if ( !$.data( this, 'columns' ) ) {
        $.data( this, 'columns', new Columns( this, opts ) )
      }
    })
  }

// ----------------------------------------------------

  // Override css method to parse viewport units
  $.fn.css = function() {

    var self = this
      , uniqId = new Date().getTime()
      , args = [].slice.call( arguments )
      , hasUnits = typeOf( args[0] ) == 'object' && hasViewportUnits( args[0] )
      , update = function() {
          return _css.apply( self, hasUnits ? [ parseProps( $.extend( {}, args[0] ) ) ] : args )
        }

    if ( hasUnits ) {
      $win.on('resize.'+ uniqId, update )
    }

    $win.off('resize.'+ $(this).data('viewport-css') )
    $(this).data('viewport-css', uniqId )

    return update()

  }

  $.columns.setDefaults = function( opts ) {
    $.extend( defaults, opts )
  }

  $.columns.quickSetup = function( opts ) {
    $.columns.setDefaults( opts )
    $('body').find('[class*="row"]').each(function() {
      var colsPerRow = +this.className.match(/row\-(\d+)/)[1]
      $(this).columns({ colsPerRow: colsPerRow })
    })
  }

  $.columns.setCols = function( els ) {

    $.each( els, function( el, props ) {

      var $el = $('#'+ el)
        , columns = $el.data('columns')
        , update = function() {
            $.each( props, function( i, prop ) {
              var res = prop[0]
                , cols = prop[1]
              if ( $win.width() < res ) {
                columns.opts.colsPerRow = cols
                return false
              } else {
                columns.opts.colsPerRow = $el.data('colsPerRow')
              }
            })
          }

      $el.data('colsPerRow', columns.opts.colsPerRow )
      $win.on('resize.columns', update )
      update()
      columns.init()

    })

  }

  $.columns.refresh = function() {
    $('body').find('[class*="row"]').each(function() {
      $(this).data('columns').init()
    })
  }

}( jQuery, window ))
