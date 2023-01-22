package dev.gaudnik;

import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;

/**
 * Hello world!
 */
public class App {

	private static ObjectMapper objectMapper;

	public static void main(String[] args) throws JsonProcessingException {
		objectMapper = new ObjectMapper();
		var person = new Person();
		person.setName("ala");
		person.setAge(35);
		person.setProfession("dev");
		var personAsJson = convertJavaToJson(person);
		System.out.println(personAsJson);
		var personObject = convertJsonToJava(personAsJson, Person.class);
		System.out.println(personObject);
	}

	public static String convertJavaToJson(Object object) throws JsonProcessingException {
		var personAsJson = "";
		personAsJson = objectMapper.writeValueAsString(object);
		return personAsJson;
	}

	public static <T> T convertJsonToJava(String jsonString, Class<T> class_scope) throws JsonProcessingException {
		T object = null;
		object = objectMapper.readValue(jsonString, class_scope);
		return object;
	}




}
