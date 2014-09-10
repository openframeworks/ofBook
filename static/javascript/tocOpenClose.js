$( document ).ready(function() {	
  $(".chapterBtn").on("click", function () {
    $("#chapters").animate({"left": "0px"}, 400);

    $("#toc").animate({"left": "-450px"}, 400);
    $("#bookInfo").animate({"left": "-450px"}, 400);

  });
  $(".navBtn").on("click", function () {
    $("#toc").animate({"left": "0px"}, 400);

    $("#chapters").animate({"left": "-450px"}, 400);
    $("#bookInfo").animate({"left": "-450px"}, 400);
    

  });
  $(".infoBtn").on("click", function () {
    $("#bookInfo").animate({"left": "0px"}, 400);

    $("#toc").animate({"left": "-450px"}, 400);
    $("#chapters").animate({"left": "-450px"}, 400);
    
  });

  $(".closeBtn").on("click", function () {
  	// maybe should be smarter here
    $("#toc").animate({"left": "-450px"}, 400);
    $("#chapters").animate({"left": "-450px"}, 400);
    $("#bookInfo").animate({"left": "-450px"}, 400);
  });
});
