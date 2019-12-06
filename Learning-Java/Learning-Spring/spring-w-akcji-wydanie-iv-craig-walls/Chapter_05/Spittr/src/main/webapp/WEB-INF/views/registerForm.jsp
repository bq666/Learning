<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<%@ page session="false" contentType="text/html; charset=UTF-8" %>

<html>
  <head>
    <title>Spittr</title>
    <link rel="stylesheet" type="text/css" 
          href="<c:url value="/resources/style.css" />" >
  </head>
  <body>
    <h1>Rejestracja</h1>

    <form method="POST">
      Imię: <input type="text" name="firstName" /><br/>
      Nazwisko: <input type="text" name="lastName" /><br/>
      Adres e-mail: <input type="email" name="email" /><br/>
      Nazwa użytkownika: <input type="text" name="username" /><br/>
      Hasło: <input type="password" name="password" /><br/>
      <input type="submit" value="Zarejestruj" />
    </form>
  </body>
</html>
