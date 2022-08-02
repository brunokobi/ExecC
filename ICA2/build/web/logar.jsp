<%--
 Document : logar
--%>
<%@page import="modelo.Usuario" contentType="text/html"
pageEncoding="UTF-8"%>

<%
 Usuario usuLogado = null;
 if(request.getParameter("login")!=null &&
         !request.getParameter("login").equals("")){
 usuLogado = new Usuario();
 usuLogado.setLogin(request.getParameter("login"));
 session.setAttribute("usuLogado", usuLogado);
 response.sendRedirect(request.getParameter("pagina"));
 return;
 }
%>
<!DOCTYPE html>
<html>
 <head>
 <meta http-equiv="Content-Type" content="text/html;
charset=UTF-8"><title>JSP Page</title>
 </head>
 <body>
 <form>
 <input type="hidden" name="pagina"
 value="<%=(request.getParameter("pagina")!=null
&& !request.getParameter("pagina").equals(""))
 ?request.getParameter("pagina")
 :"index.jsp"%>" />
 <input type="text" name="login" />
 <input type="submit" value="Logar" />
 </form>
 </body>
</html>
