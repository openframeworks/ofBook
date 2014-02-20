## -*- coding: utf-8 -*-
<%inherit file="base.mako" />
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" 
    "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html>
  <head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8"/>
    ${self.head()}
    <script src="${bf.config.site.url}/js/jquery.columnizer.min.js"></script>
    <script src="${bf.config.site.url}/js/documentation.js"></script>
  </head>
  <body>
    <div id="content">
      ${self.header()}
      <div id="body-wrap">	
	    <div class="page-wide-tutorial">
    	    <div class="article">
    	    % if article.type == 'markdown':
    	    <%self:filter chain="markdown_template">
${article.body}
    		</%self:filter>
    		% else:
        		${article.body}
    		% endif
    		</div>
            
        </div><!-- End Page Wide -->      
      </div><!-- End Body Wrap -->
      
      <div id="footer">
        ${self.footer()}
      </div> <!-- End Footer -->
    </div> <!-- End Content -->
  </body>
</html>

<%def name="header()">
  <%include file="header.mako" args="active='tutorials'" />
</%def>


