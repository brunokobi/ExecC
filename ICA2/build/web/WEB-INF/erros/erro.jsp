<%--
 Document : erro500
--%>
<%@page isErrorPage="true" contentType="text/html" pageEncoding="UTF8"%>
<!DOCTYPE html>
<html>
<head>
 <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
 <title>ERRO</title>
</head>
<body>
    <h3>Arrá! Usuário esperto gerou um erro né</h3>
 O erro é: <%= exception%> <br/>
</body>
</html>