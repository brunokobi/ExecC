<%--
 Document : alterar
--%>
<%@page import="modelo.PessoaDAO"%>
<%@page import="java.util.List"%>
<%@page import="java.sql.ResultSet"%>
<%@page import="java.sql.DriverManager"%>
<%@page import="java.sql.PreparedStatement"%>
<%@page import="java.sql.Connection"%>
<%@page import="modelo.Pessoa"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%

%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html;
              charset=UTF-8">
        <title>Pessoas</title>
    </head>
    <body>
        <a href="lista.jsp">Listar Pessoas</a>
        <br>
        <form action="Controle">
            <input type="hidden" name="acao" value="alterar" />
            <input type="text" name="id" value="<%=((Pessoa)request.getAttribute("pessoa")).getId()%>" />
            <input type="text" name="nome" value="<%=((Pessoa)request.getAttribute("pessoa")).getNome()%>" />
            <input type="submit" value="Alterar" />
        </form>   
    </body>
</html>
