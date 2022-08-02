<%--    Document   : computaValores--%>


<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <%@page errorPage="/WEB-INF/erros/erro.jsp" %> 
        <title>JSP Page</title>
    </head>
    <body>
        <%
            String num1 = request.getParameter("n1");
            String num2 = request.getParameter("n2");
            
            if(num1 != null && num2 != null){
                int a= Integer.parseInt(num1);
                int b = Integer.parseInt(num2);
                int c = a/b;
                out.print("A divisão é igual a a: "+c);
                
            }
        %>
        <h1>Hello World!</h1>
    </body>
</html>
