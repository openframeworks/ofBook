## -*- coding: utf-8 -*-
<%inherit file="base.mako" />
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" 
    "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html>
  <head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8"/>
    ${self.head()}
  </head>
  <body>
    <div id="content" class="tutorial">
      ${self.header()}
      <div id="body-wrap">	
	    <div class="page-wide">        
	        <h1>ofBook</h1>
        </div><!-- End Page Wide -->  
		    
        <div class="page-wide">  
            <ul class="articles">
            % for category in categories:
                % if len(category["articles"]) > 0:
                     <li><a href="${category["category"]}/index.html">${category["category"]}</a></li>
                % endif
            % endfor
            </ul>
        </div><!-- End Page Wide --> 
		    
        <div class="page-wide">  
            <a href="ofBook.pdf">download as pdf</a></li>
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


