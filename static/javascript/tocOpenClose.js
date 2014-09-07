$( document ).ready(function() {	
  $(".btn-open").on("click", function () {
    $(".tocify").animate({"left": "0px"}, 400);
  });
  $(".btn-close").on("click", function () {
    $(".tocify").animate({"left": "-450px"}, 400);
  });
});
