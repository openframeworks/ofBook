// Save the base title for manipulation
var baseTitle =  document.title;

$(document).ready(

    function(){
      
      // Setup Syntax handler
      $("pre").each(function(){
        children = $(this).children("code");
        if(children.length>0){
            $(this).text($(children[0]).text());
            this.className="brush: " + children[0].className;
        }    
      });      
      SyntaxHighlighter.defaults['toolbar'] = false;
      SyntaxHighlighter.defaults['gutter'] = false;
      SyntaxHighlighter.all()
    }
);
