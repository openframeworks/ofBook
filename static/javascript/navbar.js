$( document ).ready(function() {

  $(".group").click(function () {
    $('.group.selected').removeClass('selected');

    $(this).addClass('selected');
  })

});
