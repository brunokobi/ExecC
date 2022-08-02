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
    <body style="background-image:url('img/imagem.png'); background-size: cover; ">
        <a href="index.jsp" style="background-color:white;border-style: solid;">&nbsp;&nbsp;Listar pessoas&nbsp;&nbsp;</a>
        <br>
        <br>
        <form action="Controle">
            <input type="hidden" name="acao" value="alterar" />
            <input type="hidden" name="id" value="<%=((Pessoa)request.getAttribute("pessoa")).getId()%>" />
            <input style="border-style: solid;" type="text" name="nome" value="<%=((Pessoa)request.getAttribute("pessoa")).getNome()%>" />
            <input type="submit" value="Alterar" />
        </form>   
    </body>
</html>
