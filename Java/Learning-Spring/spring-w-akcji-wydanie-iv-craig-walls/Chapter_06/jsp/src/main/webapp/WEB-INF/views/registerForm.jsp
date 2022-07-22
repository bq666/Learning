<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<%@ taglib uri="http://www.springframework.org/tags/form" prefix="sf" %>
<%@ page session="false" contentType="text/html; charset=UTF-8" %>
<html>
  <head>
    <title>Spittr</title>
    <link rel="stylesheet" type="text/css" 
          href="<c:url value="/resources/style.css" />" >
  </head>
  <body>
    <h1>Rejestracja</h1>

    <sf:form method="POST" commandName="spitter" >
      <sf:errors path="*" element="div" cssClass="errors" />
      <sf:label path="firstName" 
          cssErrorClass="error">Imię</sf:label>: 
        <sf:input path="firstName" cssErrorClass="error" /><br/>
      <sf:label path="lastName" 
          cssErrorClass="error">Nazwisko</sf:label>: 
        <sf:input path="lastName" cssErrorClass="error" /><br/>
      <sf:label path="email" 
          cssErrorClass="error">Adres e-mail</sf:label>: 
        <sf:input path="email" cssErrorClass="error" /><br/>
      <sf:label path="username" 
          cssErrorClass="error">Nazwa użytkownika</sf:label>: 
        <sf:input path="username" cssErrorClass="error" /><br/>
      <sf:label path="password" 
          cssErrorClass="error">Hasło</sf:label>: 
        <sf:password path="password" cssErrorClass="error" /><br/>
      <input type="submit" value="Zarejestruj" />
    </sf:form>
  </body>
</html>
