var hasFlickr = false;
var hasVimeo = false;

function getUrlVars(){
    var location = window.location.href;
    if(location.lastIndexOf("/")==location.length-1)
        location = location.substr(0,location.length-1)
    var vars = [], hash;
    var hashes = location.slice(location.indexOf('?') + 1).split('&');
    for(var i = 0; i < hashes.length; i++){
        hash = hashes[i].split('=');
        vars.push(hash[0]);
        vars[hash[0]] = hash[1];
    }
    return vars;
}

function parseVimeo(xml){
    if (!xml.error) {
        /*console.log($(xml).find("rss"));
        console.log("parse vimeo, channel: " + $(xml).find("rss").length + " items " + $(xml).find("item").length);
        $(xml).find("item").each(function(){
            console.log("item");
            var url = $(this).find("link").text();
            var id = url.substr(url.lastIndexOf("/")+1);
            var vimHTML = $(document.createElement('iframe')).attr({src:vidURL, width:w, height:h, frameborder:0});
            $("vimeo").append(vimHTML);
        });*/
        
        for(var i = 0; i < xml.xmlDocument.getElementsByTagName('item').length; i++){
            var entry = xml.xmlDocument.getElementsByTagName('item')[i];
            var url = entry.getElementsByTagName("link")[0].textContent;
            var id = url.substr(url.lastIndexOf("/")+1);
            var vidURL = 'http://player.vimeo.com/video/' + id + '?title=1&amp;byline=0&amp;portrait=0';

            var w=440;
            var h=300;
            var vimHTML = $(document.createElement('iframe')).attr({src:vidURL, width:w, height:h, frameborder:0});
            $("#vimeo").append(vimHTML);
        }
        
        $("#vimeo iframe").css( "margin-left", function(index, value){ 
                if(hasFlickr){
                    if(index%2==0){
                        return "20px";
                    }else{
                        return "0px";
                    }
                }else{
                    if((index+1)%2==0){
                        return "20px";
                    }else{
                        return "0px";
                    }
                }
            })
    }
}

function parseFlickr(data) {
    var added=0;
    $.each(data.photos, function(i,photo){
        if(i=="photo"){
            $(photo).each(function(){
                if($(this)[0].tags.indexOf("openframeworks")==-1){
                    return;
                }
                /*$("#flickr").append('<img src="http://farm' + $(this)[0].farm + '.staticflickr.com/' + 	$(this)[0].server + "/" + $(this)[0].id + "_" + $(this)[0].secret + '_z.jpg"/>');*/
                var h3 = document.createElement("h3");
                var a = document.createElement("a");
                var aText = document.createElement("a");
                var div = document.createElement("div");
                var img = document.createElement("img");
                var url = 'http://flickr.com/photos/' + $(this)[0].owner + '/' + $(this)[0].id;
                img.src = 'http://farm' + $(this)[0].farm + '.staticflickr.com/' + 	$(this)[0].server + "/" + $(this)[0].id + "_" + $(this)[0].secret + '_z.jpg'
                a.href = url;
                aText.href = url;
                aText.className="flickrTitle";
                h3.appendChild(document.createTextNode(Encoder.htmlDecode($(this)[0].title)));
                a.appendChild(img);
                a.className  = "img";
                aText.appendChild(h3)
                div.appendChild(a);
                div.appendChild(aText);
                div.className="imgContainer";
                $("#flickr").append(div);
                added++;
                if(added==20) return false;
            });
        }
    });
    $('#flickr').cycle({
        fx: 'fade' // choose your transition type, ex: fade, scrollUp, shuffle, etc...
    });
  }
  

function parseXML(xml){
    member = $(xml).find("member");
    $("#user").append("<h1>"+$(member).find("name").text());
    $("#user").append('<img src="'+$(member).find("image").text()+'"/>');
    $("#user").append('<p><a href="'+$(member).find("website").text()+'">'+$(member).find("website").text()+'</a></p>');
    
    
    if($(member).find("github").text() != ""){
        var feedGithub = new google.feeds.Feed("https://github.com/" + $(member).find("github").text() + ".atom");
        feedGithub.setNumEntries(10);
        feedGithub.setResultFormat(google.feeds.Feed.XML_FORMAT);
        // Calling load sends the request off.  It requires a callback function.
        feedGithub.load(feedGithubLoaded);
    }

    if($(member).find("flickr").text() != ""){ 
        hasFlickr = true;   
        $("#flickr").show();
        /*var feedFlickr = new google.feeds.Feed("http://api.flickr.com/services/feeds/photos_public.gne?id="+$(member).find("flickr").text()+"&lang=es-us&format=rss_200");
        feedFlickr.setNumEntries(20);
        feedFlickr.load(feedFlickrLoaded);*/
        $.getJSON('http://api.flickr.com/services/rest/?method=flickr.people.getPublicPhotos&api_key=a5c91e7359870a3f328f7fb8b2ae1337&user_id='+$(member).find("flickr").text()+'&extras=tags&format=json&jsoncallback=?', parseFlickr);
    }
    
    if($(member).find("vimeo").text() != ""){
        hasVimeo = true;
        var feedVimeo = new google.feeds.Feed("http://vimeo.com/" + $(member).find("vimeo").text() + "/videos/rss");
        feedVimeo.setNumEntries(5);
        feedVimeo.setResultFormat(google.feeds.Feed.XML_FORMAT);
        feedVimeo.load(parseVimeo);
    }
    
    if(hasVimeo || hasFlickr){
        $("#media").show();
    }
}

$(document).ready(
    function(){
      $("#flickr").hide();
      $("#media").hide();
      $.ajax({
        type: "GET",
        url: "http://forum.openframeworks.cc/chris_test/getUser.php?user="+getUrlVars()["user"],
        //dataType: "xml",
        success: parseXML
      });
    });
