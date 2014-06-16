## -*- coding: utf-8 -*-
<%def name="filter(chain)">
  ${bf.filter.run_chain(chain, capture(caller.body))}
</%def>

<%def name="header()">
  <% 
    template_name = bf.template_context['template_name']
    active = template_name[:template_name.find("/")]
  %>
  <%include file="header.mako"  args="active=active" />
</%def>

<%def name="head(subtitle='')">
	<% 
		subtitle = ('' if subtitle == '' else " - " + subtitle)
	%>
  <%include file="head.mako" args="subtitle=subtitle"/>
</%def>

<%def name="footer()">
  <%include file="footer.mako" />
</%def>

${next.body()}


