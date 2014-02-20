// Save the base title for manipulation
var baseTitle =  document.title;

//setup handler for browser popstate events
window.onhashchange = loadDocumentationFromLocation;


function resetDiscuss(section_name){
    console.log(window.location.protocol + "://" + window.location.host + window.location.pathname + "#!show_" + section_name);
    DISQUS.reset({
      reload: true,
      config: function () {  
        if(section_name!=''){
            this.page.identifier = window.location.pathname + "#!show_" + section_name;  
            this.page.url = window.location.protocol + "//" + window.location.host + window.location.pathname + "#!show_" + section_name;
        }else{
            this.page.identifier = window.location.pathname;  
            this.page.url = window.location.protocol + "//" + window.location.host + window.location.pathname;
        }
        this.page.title = document.title;
    }
  });
}

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
      SyntaxHighlighter.all()
      
      // Handle loading a page with a named anchor in the hash.
      // Chrome and Safari don't need this, Firefox does.
      loadDocumentationFromLocation();
      
     
     // Handle browsers that don't implement the HTML5 history state API.
     if (typeof window.history.replaceState != 'function') {
        $(".functionslist a").click(function(e){
          showFunctionDocumentation($(this).data('lookup'));
        });
     }
     
     // handle clicking the header containing the class name
     $("#docstitle h1").click(showClassDocumentation);
    });


// Handle loading documentation from the location hash
function loadDocumentationFromLocation() {
  var currentFunctionName = location.hash.split("_")[1];
  if(currentFunctionName!=undefined && currentFunctionName.length){  
    showFunctionDocumentation(currentFunctionName);
  }else{
    showClassDocumentation();
  }
}

// Reset the documentation to a neutral state
function resetDocumentation() {
  $(".documentation_detail").hide();
  $(".functionslist a").removeClass('selected');
}

// show documentation for a particular method, function, or variable.
function showFunctionDocumentation(functionName) {
  resetDocumentation();
  var item = $(".documentation_detail[data-lookup='" + functionName +"']").show();
  $(".functionslist a[data-lookup='" + functionName +"']").addClass('selected');
  $('html, body').animate({scrollTop:0}, 200);
  switch(item.data("item-type")) {
    case "method":
      document.title = baseTitle + "::" + functionName + "()";
      break;
    case "var":
      document.title = baseTitle + "." + functionName;
      break;
    case "function":
      document.title = baseTitle + "::" + functionName;
      break;
    default:
      document.title = baseTitle;
  }
  if (typeof DISQUS === "object") resetDiscuss(functionName)
}

// show documentation for the entire class.
function showClassDocumentation() {
  resetDocumentation();
  $(".class_documentation").show();
  $("#docstitle h1").addClass('selected');
  document.title = baseTitle
  
  // Remove hash
  if (window.location.hash.length) {
    if (typeof window.history.replaceState == 'function') {
      history.replaceState({}, '', window.location.pathname);
    }
    else {
      window.location.hash = "";
    }
  }
  if (typeof DISQUS === "object") resetDiscuss("")
}
