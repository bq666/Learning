<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<%@ taglib uri="http://www.springframework.org/tags" prefix="s" %>
<%@ page session="false" contentType="text/html; charset=UTF-8" %>

<html>
  <head>
    <title>Spittr</title>
    <link rel="stylesheet" 
          type="text/css" 
          href="<c:url value="/resources/style.css" />" >
  </head>
  <body>
    <h1><s:message code="spitter.welcome" text="Witamy" /></h1>

    <s:url value="/spitter/register" var="registerUrl" />

    <a href="<s:url value="/spittles" />">Spittle'e</a> | 
    <a href="${registerUrl}">Rejestracja</a>

  </body>
</html>
