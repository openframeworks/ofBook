$(document).ready(function() {

  // Handle selecting & unselecting chapter groups in the sidebar
  var $selectedGroup = $('.group.selected');
  $(".group").click(function(event) {
    // Pull out the element that to which the click event is bound (li.group)
    var newSelected = event.currentTarget;

    if ($selectedGroup.length && ($selectedGroup.get(0) === newSelected)) {
      // Clicked on already selected group, but only unselect the current group
      // if the click happened over the title div. This helps prevents
      // accidentally closing the group, e.g. if click happened in-between
      // chapter links.
      if ($(event.target).hasClass('groupTitle')) {
        $selectedGroup.removeClass('selected');
        $selectedGroup = $(); // Empty selection
      }
    } else {
      // Clicked on a new group
      $selectedGroup.removeClass('selected');
      $selectedGroup = $(newSelected);
      $selectedGroup.addClass('selected');
    }
  });


  // Cache selectors
  var menu = $(".chapter.selected ul");

  // All list items
  var offset = 250;
  var menuItems = menu.find("a");

  // Anchors corresponding to menu items
  var scrollItems = menuItems.map(function() {
    var item = $($(this).attr("href"));
    if (item.length) {
      return item;
    }
  });


  // Bind to scroll
  $(window).scroll(function() {
    // Get container scroll position
    var fromTop = $(this).scrollTop() + offset;

    // Get id of current scroll item
    var cur = scrollItems.map(function() {
      if ($(this).offset().top < fromTop)
        return this;
    });

    if (cur.length == 0) {
      cur = [scrollItems[0]]
    }
    // Get the id of the current element
    cur = cur[cur.length - 1];
    var id = cur && cur.length ? cur[0].id : "";
    // Set/remove active class
    menuItems
      .parent().removeClass("selected")
      .end().filter("[href=#" + id + "]").parent().addClass("selected");


    var scrollTop = $(window).scrollTop();
    var height = $(window).height();
    $('.banner').css({
      'opacity': ((height - scrollTop * 3.4) / height)
    });
  });



});