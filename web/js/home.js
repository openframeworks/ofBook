

    
function OnLoad() {
    var feedGithub = new google.feeds.Feed("https://github.com/openframeworks/openFrameworks/commits/master.atom");
    feedGithub.setNumEntries(10);
    feedGithub.setResultFormat(google.feeds.Feed.XML_FORMAT);
    // Calling load sends the request off.  It requires a callback function.
    feedGithub.load(feedGithubLoaded);

    var feedForum = new google.feeds.Feed("http://forum.openframeworks.cc/latest.rss");
    feedForum.setNumEntries(4);
    // Calling load sends the request off.  It requires a callback function.
    feedForum.load(feedForumLoaded);

    var feedFlickr = new google.feeds.Feed("http://api.flickr.com/services/feeds/groups_pool.gne?id=476246@N23&lang=es-us&format=rss_200");
    feedFlickr.setNumEntries(20);
    feedFlickr.load(feedFlickrLoaded);
    
    var feedVimeo = new google.feeds.Feed("http://vimeo.com/tag:openframeworks/rss");
    feedVimeo.setNumEntries(20);
    feedVimeo.setResultFormat(google.feeds.Feed.XML_FORMAT);
    feedVimeo.load(feedVimeoLoaded);
}

google.setOnLoadCallback(OnLoad);


