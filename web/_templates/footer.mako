## -*- coding: utf-8 -*-
<p id="credits">

Last updated ${self.getTime()}&nbsp;&nbsp;&nbsp;&nbsp;-&nbsp;&nbsp;&nbsp;&nbsp;<a href="https://github.com/openframeworks/ofSite/commit/${self.getLastCommitHash()}">${self.getLastCommitHash()}</a>

<!--br/>RSS feeds for <a href="${bf.util.site_path_helper(bf.config.blog.path,'feed')}">Entries</a-->

% if bf.config.blog.disqus.enabled:
 and <a
href="http://${bf.config.blog.disqus.name}.disqus.com/latest.rss">Comments</a>.
% endif
<br/>

</p>

% if bf.config.blog.disqus.enabled:
<script type="text/javascript">
//<![CDATA[
(function() {
		var links = document.getElementsByTagName('a');
		var query = '?';
		for(var i = 0; i < links.length; i++) {
			if(links[i].href.indexOf('#disqus_thread') >= 0) {
				query += 'url' + i + '=' + encodeURIComponent(links[i].href) + '&';
			}
		}
		document.write('<script charset="utf-8" type="text/javascript" src="http://disqus.com/forums/${bf.config.blog.disqus.name}/get_num_replies.js' + query + '"></' + 'script>');
	})();
//]]>
</script>
% endif



<!--tracking -->
<script type="text/javascript">
var gaJsHost = (("https:" == document.location.protocol) ? "https://ssl." : "http://www.");
document.write(unescape("%3Cscript src='" + gaJsHost + "google-analytics.com/ga.js' type='text/javascript'%3E%3C/script%3E"));
</script>
<script type="text/javascript">
try {
var pageTracker = _gat._getTracker("UA-9614675-1");
pageTracker._trackPageview();
} catch(err) {}</script>

<%def name="getTime()">
  <% 
    from time import gmtime, strftime
    currentTime = strftime("%A, %d %B %Y %H:%M:%S UTC", gmtime())
  %>
${currentTime}
</%def>

<%def name="getLastCommitHash()">
<% 
    import subprocess
    p1 = subprocess.Popen(["git", "log", "-1"], stdout=subprocess.PIPE)
    out = p1.communicate()
    hash = out[0][len("commit "):out[0].find('\n')].strip()
%>
${hash}
</%def>
