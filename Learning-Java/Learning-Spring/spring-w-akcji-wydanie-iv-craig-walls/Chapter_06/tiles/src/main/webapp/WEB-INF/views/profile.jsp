<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<%@ page session="false" contentType="text/html; charset=UTF-8" %>
<h1>Twój profil</h1>
<c:out value="${spitter.username}" /><br/>
<c:out value="${spitter.firstName}" /> <c:out value="${spitter.lastName}" /><br/>
<c:out value="${spitter.email}" />
