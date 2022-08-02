<%--
 Document : lista
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
        <a href="cadastro.jsp" style="background-color:white;border-style: solid;">&nbsp;&nbsp;Inserir nova pessoa&nbsp;&nbsp;   </a>
        <br>
        <br>
        <table style="background-color:lightgray;border-style: solid;">
            <th style="background-color:lightcoral;border-style: solid;">ID</th>
            <th style="background-color:lightcoral;border-style: solid;">NOME</th>
             <th colspan="3" style="background-color:lightcoral;border-style: solid;">OPCÕES</th>
          
            <%                List<Pessoa> lista = new PessoaDAO().lista();
                for (Pessoa p : lista) {
            %>
            <tr>
                <td style="background-color:lightgoldenrodyellow;border-style: solid;"><B>[<%=p.getId()%>]</B></td>
                <td style="background-color:lightgoldenrodyellow;border-style: solid;"><b>&nbsp;&nbsp;<%=p.getNome()%>&nbsp;&nbsp;&nbsp;&nbsp;</b></td>
                <td style="background-color:red;border-style: solid;"><a href="Controle?acao=excluir&id=<%=p.getId()%>">[Excluir]</a></td>
                <td style="background-color:BLACK;border-style: solid;">&nbsp;&nbsp;</td>
                <td style="background-color:cyan;border-style: solid;"><a href="Controle?acao=visualizar&id=<%=p.getId()%>">[Alterar]</a></td>
            </tr>
            <%}%>
        </table>
        <%
            if (request.getAttribute("mensagem") != null) {
        %>
        <script>
            alert("<%=request.getAttribute("mensagem")%>");
        </script>
        <s
            <%
                }
            %>
</body>
</html>
