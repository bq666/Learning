import java.util.*;

class Person{
	private int id;
	private String name;

	public Person(int id, String name){
		this.id = id;
		this.name = name;
	}

	public String toString(){
		return id + ": " + name;
	}

	@Override
	public boolean equals(Object o) {
		if (this == o) return true;
		if (o == null || getClass() != o.getClass()) return false;
		Person person = (Person) o;
		return id == person.id &&
				Objects.equals(name, person.name);
	}

	@Override
	public int hashCode() {
		return Objects.hash(id, name);
	}
}

public class Using_Own_Obj_in_set_and_map_6 {
	public static void main(String[] args) {

		Person p1 = new Person(0, "Bob");
		Person p2 = new Person(1, "Sue");
		Person p3 = new Person(2, "Mike");
		Person p4 = new Person(1, "Sue");

		Map<Person, Integer> map = new LinkedHashMap<>();
		map.put(p1, 1);
		map.put(p2, 2);
		map.put(p3, 3);
		map.put(p4, 1);
		for(Person item: map.keySet()){
			System.out.println(item);// + ": " + map.get(key));
		}



		Set<Person> set = new LinkedHashSet<>();
		set.add(p1);
		set.add(p2);
		set.add(p3);
		set.add(p4);
		System.out.println(set);
		//		for(Person item: set.)







//		Map<String, Integer> map = new LinkedHashMap<>();
//		map.put("one", 1);
//		map.put("two", 2);
//		map.put("three", 3);
//		map.put("one", 1);
//
//		for (String key: map.keySet()) {
//			System.out.println(key + ": " + map.get(key));
//		}
//		Set<String> set = new LinkedHashSet<>();
//		set.add("dog");
//		set.add("cat");
//		set.add("mouse");
//		set.add("cat");
//
//		System.out.println(set);

	}
}
