var currentHidding=null;
var coreFunctionsHidden=false;
var addonsFunctionsHidden=false;
var coreCollapsed=false;
var addonsCollapsed = false;

$(function(){
    $('.documentation_index_group').masonry({
        itemSelector: '.box',
        columnWidth: function( containerWidth ) {
            return containerWidth / 3;
          }
    });
});

$(document).ready(
    function(){
        // collapse one
        $('div.documentation_group_head').click(function () {
        if(currentHidding!=null) return;
        currentHidding = $(this);
            if($(this).hasClass('show')){
                $(this).next('.documentation_index_group').hide("blind", { direction: "vertical" }, 500, function(){
                    currentHidding.removeClass('show');
                    currentHidding.addClass('hide');
                    currentHidding = null;
                    });
            }else{
                $(this).next('.documentation_index_group').show("blind", { direction: "vertical" }, 500, function(){
                    currentHidding.removeClass('hide');
                    currentHidding.addClass('show');
                    currentHidding = null;
                    $(this).masonry( 'reload' );
                    });
            }
        });
        
        
        // hide show functions
        $('a.hide_core_functions').click(function(){
            if(coreFunctionsHidden){
                $('.core ul.documentation_class li.method').show();
                $('.core .documentation_index_group').masonry( 'reload' );
                coreFunctionsHidden = false;
                $(this).text('hide functions');
            }else{
                $('.core ul.documentation_class li.method').hide();
                coreFunctionsHidden = true;
                $(this).text('show functions');
                $('.core .documentation_index_group').masonry( 'reload' );
            }
        });
        $('a.hide_addons_functions').click(function(){
            if(addonsFunctionsHidden){
                $('.addons ul.documentation_class li.method').show();
                $('.addons .documentation_index_group').masonry( 'reload' );
                addonsFunctionsHidden = false;
                $(this).text('hide functions');
            }else{
                $('.addons ul.documentation_class li.method').hide();
                addonsFunctionsHidden = true;
                $(this).text('show functions');
                $('.addons .documentation_index_group').masonry( 'reload' );
            }
        });
        
        // collapse all
        $('a.collapse_core').click(function(){
            if(coreCollapsed){
                $('.core .documentation_index_group').show();
                $('.core .documentation_index_group').masonry( 'reload' );
                $('.core .documentation_group_head').addClass('show');
                $('.core .documentation_group_head').removeClass('hide');
                coreCollapsed = false;
                $(this).text('collapse all');
            }else{
                $('.core div.documentation_index_group').hide();
                $('.core .documentation_group_head').addClass('hide');
                $('.core .documentation_group_head').removeClass('show');
                coreCollapsed = true;
                $(this).text('open all');
            }
        });
        $('a.collapse_addons').click(function(){
            if(addonsCollapsed){
                $('.addons .documentation_index_group').show();
                $('.addons .documentation_index_group').masonry( 'reload' );
                $('.addons .documentation_group_head').addClass('show');
                $('.addons .documentation_group_head').removeClass('hide');
                addonsCollapsed = false;
                $(this).text('collapse all');
            }else{
                $('.addons .documentation_index_group').hide();
                $('.addons .documentation_group_head').addClass('hide');
                $('.addons .documentation_group_head').removeClass('show');
                addonsCollapsed = true;
                $(this).text('open all');
            }
        });
});
