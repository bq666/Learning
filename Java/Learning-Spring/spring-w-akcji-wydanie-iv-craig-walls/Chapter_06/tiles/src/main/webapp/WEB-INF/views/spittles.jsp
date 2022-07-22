<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>
<%@ taglib prefix="s" uri="http://www.springframework.org/tags"%>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %>
<%@ page session="false" contentType="text/html; charset=UTF-8" %>

<div class="spittleForm">
  <h1>Wyrzuć to z siebie...</h1>
  <form method="POST" name="spittleForm">
    <input type="hidden" name="latitude">
    <input type="hidden" name="longitude">
    <textarea name="message" cols="80" rows="5"></textarea><br/>
    <input type="submit" value="Dodaj" />
  </form>
</div>
<div class="listTitle">
  <h1>Ostatnie spittle'e</h1>
  <ul class="spittleList">
    <c:forEach items="${spittleList}" var="spittle" >
      <li id="spittle_<c:out value="spittle.id"/>">
        <div class="spittleMessage"><c:out value="${spittle.message}" /></div>
        <div>
          <span class="spittleTime"><c:out value="${spittle.time}" /></span>
          <span class="spittleLocation">(<c:out value="${spittle.latitude}" />, <c:out value="${spittle.longitude}" />)</span>
        </div>
      </li>
    </c:forEach>
  </ul>
  <c:if test="${fn:length(spittleList) gt 20}">
    <hr />
    <s:url value="/spittles?count=${nextCount}" var="more_url" />
    <a href="${more_url}">Pokaż więcej</a>
  </c:if>
</div>
