<%-- 
    Document   : index
    Created on : 06/06/2019, 21:13:54
    Author     : Lucas Barbosa
--%>

<%@page import="modelo.Usuario"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>

<%
 Usuario usuLogado = null;
 if (session.getAttribute("usuLogado") != null) {
 usuLogado = (Usuario) session.getAttribute("usuLogado");
 } else {
 response.sendRedirect("logar.jsp?pagina=index.jsp");
 return;
 }
%>
<!DOCTYPE html>
<html>
 <head>
 <meta http-equiv="Content-Type" content="text/html;
charset=UTF-8">
 <title>Página inicial</title>
 </head>
 <body>
 <h1>Olá! <%=usuLogado.getLogin()%></h1>
 </body>
</html>
<%

%>