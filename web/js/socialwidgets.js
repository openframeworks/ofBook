google.load("feeds", "1");

 // Our callback function, for when a feed is loaded.
function feedGithubLoaded(result) {
  if (!result.error) {
    // Grab the container we will put the results into
    var container = document.getElementById("github");
    container.innerHTML = '<h3>github</h3>';

    // Loop through the feeds, putting the titles onto the page.
    // Check out the result object for a list of properties returned in each entry.
    // http://code.google.com/apis/ajaxfeeds/documentation/reference.html#JSON
    var ul = document.createElement("ul");
    var totalElements = 0;
    for (var i = 0; i < result.xmlDocument.getElementsByTagName('entry').length && totalElements<6; i++) {
      var entry = result.xmlDocument.getElementsByTagName('entry')[i];
      var li = document.createElement("li");
      var a = document.createElement("a");
      var img = document.createElement("img");
      var div = document.createElement("div");
      div.className="github_avatar";
      img.src = entry.getElementsByTagNameNS("*","thumbnail")[0].getAttribute("url");
      a.href = entry.getElementsByTagName("link")[0].getAttribute("href");
      var title = entry.getElementsByTagName("title")[0].textContent;
      if(title.indexOf("Merge") == 0){
        continue
      }
			var date = entry.getElementsByTagName("updated")[0].textContent;
			// <abbr class="timeago" title="2008-07-17T09:24:17Z">July 17, 2008</abbr>
			var dateTag = document.createElement("span");
			dateTag.className = "github_time";
			dateTag.title = date;
			dateTag.appendChild(document.createTextNode(jQuery.timeago(date)));
      a.appendChild(document.createTextNode(title));
			//a.appendChild(dateTag);
      //a.appendChild(document.createTextNode(entry.getElementsByTagNameNS("*","thumbnail")[0].getAttribute("url")));
      /*for( p in entry.getElementsByTagName("link")){
         a.appendChild(document.createTextNode(p.tagName));
         a.appendChild(document.createElement("br"));
      }*/
      //a.appendChild(document.createTextNode(entry.textContent));
      div.appendChild(img);
      li.appendChild(div);
      li.appendChild(a);
      li.appendChild(dateTag);
      li.appendChild(document.createElement("br"));
      //li.appendChild(document.createTextNode(entry.getElementsByTagName("updated")[0].textContent));
      ul.appendChild(li);
      totalElements++;
    }
    container.appendChild(ul);
  }
}

    // Our callback function, for when a feed is loaded.
function feedForumLoaded(result) {
  if (!result.error) {
    // Grab the container we will put the results into
    var container = document.getElementById("forum");
    container.innerHTML = '<h3>forum</h3>';
    
    

    // Loop through the feeds, putting the titles onto the page.
    // Check out the result object for a list of properties returned in each entry.
    // http://code.google.com/apis/ajaxfeeds/documentation/reference.html#JSON
    var ul = document.createElement("ul");
    for (var i = 0; i < result.feed.entries.length; i++) {
      var entry = result.feed.entries[i];
      var li = document.createElement("li");
      var a = document.createElement("a");
      a.href = entry.link;
      a.appendChild(document.createTextNode(Encoder.htmlDecode(entry.title)));
      li.appendChild(a);
      li.appendChild(document.createElement("br"));
      var span = document.createElement("span")
      span.innerHTML = entry.content.substr(0,150) + "...</p>"
      li.appendChild(span);
      ul.appendChild(li);
    }
    container.appendChild(ul);
  }
}

// Our callback function, for when a feed is loaded.
function feedFlickrLoaded(result) {
  if (!result.error) {
    // Grab the container we will put the results into
    var container = document.getElementById("flickr");
    container.innerHTML = '';

    // Loop through the feeds, putting the titles onto the page.
    // Check out the result object for a list of properties returned in each entry.
    // http://code.google.com/apis/ajaxfeeds/documentation/reference.html#JSON
    for (var i = 0; i < result.feed.entries.length; i++) {
      var entry = result.feed.entries[i];
      if(entry["mediaGroups"]==undefined || entry.mediaGroups.length<1 || entry.mediaGroups[0].length < 1 || ("" + entry.mediaGroups[0].contents[0].type).indexOf("image")!=0){
        console.log("entry with no media " + entry.mediaGroups[0].contents[0].type);
        continue;
      }
      var h3 = document.createElement("h3");
      var a = document.createElement("a");
      var aText = document.createElement("a");
      var div = document.createElement("div");
      var img = document.createElement("img");
      a.href = entry.link;
      aText.href = entry.link;
      aText.className="flickrTitle";
      h3.appendChild(document.createTextNode(Encoder.htmlDecode(entry.title + " by " + entry.author.substr(entry.author.indexOf('(')+1, entry.author.indexOf(')')-entry.author.indexOf('(')-1))))
      a.appendChild(img);
      a.className  = "img";
      aText.appendChild(h3)
      div.appendChild(a);
      div.appendChild(aText);
      div.className="imgContainer";
      img.src = entry.mediaGroups[0].contents[0].url;

      container.appendChild(div);
    }
  }
    $('#flickr').cycle({
        fx: 'fade' // choose your transition type, ex: fade, scrollUp, shuffle, etc...
    });
}

// Our callback function, for when a feed is loaded.
function feedVimeoLoaded(result) {
  if (!result.error && result.xmlDocument.getElementsByTagName('item').length>0) {
    // Grab the container we will put the results into
    var container = document.getElementById("vimeo");
    container.innerHTML = '';
    var numEntry = Math.floor(Math.random()*result.xmlDocument.getElementsByTagName('item').length)
    var entry = result.xmlDocument.getElementsByTagName('item')[numEntry];
    var url = entry.getElementsByTagName("link")[0].textContent;
    var id = url.substr(url.lastIndexOf("/")+1);
    var vidURL = 'http://player.vimeo.com/video/' + id + '?title=1&amp;byline=0&amp;portrait=0';

    var w=440;
    var h=300;

    var vimHTML = $(document.createElement('iframe')).attr({src:vidURL, width:w, height:h, frameborder:0});
    $('#vimeo').append(vimHTML);
  }
}
