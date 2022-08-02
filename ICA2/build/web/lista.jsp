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
    <body>
        <a href="cadastro.jsp">Inserir nova pessoa</a>
        <br>
        <br>
        <table>
            <%                List<Pessoa> lista = new PessoaDAO().lista();
                for (Pessoa p : lista) {
            %>
            <tr>
                <td><%=p.getId()%> - &nbsp;&nbsp;</td>
                <td><%=p.getNome()%></td>
                <td><a href="Controle?acao=excluir&id=<%=p.getId()%>">Excluir</a></td>
                <td><a href="Controle?acao=visualizar&id=<%=p.getId()%>">Alterar</a></td>
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
