import java.util.*;

class Person_8 implements Comparable<Person_8>{
	private String name;

	public Person_8(String name){
		this.name = name;
	}

	public String toString(){
		return name;
	}

	@Override
	public boolean equals(Object o) {
		if (this == o) return true;
		if (o == null || getClass() != o.getClass()) return false;
		Person_8 person_8 = (Person_8) o;
		return Objects.equals(name, person_8.name);
	}

	@Override
	public int hashCode() {
		return Objects.hash(name);
	}

	@Override
	public int compareTo(Person_8 person) {
		int len1 = name.length();
		int len2 = person.name.length();

		if(len1 > len2){
			return 1;
		} else if (len1 < len2){
			return -1;
		}
//		return 1;
		return name.compareTo(person.name);
	}
}


public class Natural_ordering_and_the_Comparable_Interface_8 {
	public static void main(String[] args) {
		List<Person_8> list = new ArrayList<>();
		SortedSet<Person_8> set = new TreeSet<>();

		addElements(list);
		addElements(set);

		Collections.sort(list);
//		Collections.sort(set);  <---źle !!! ? TODO bo set korzysta z tych metod ktore są w person dlatego to działą ?



		showElements(list);
		System.out.println();
		showElements(set);
	}


	private static void addElements(Collection<Person_8> col){
		col.add(new Person_8("Joe"));
		col.add(new Person_8("Sue"));
		col.add(new Person_8("Juliet"));
		col.add(new Person_8("Clare"));
		col.add(new Person_8("Mike"));
	}

	private static void showElements(Collection<Person_8> col){
		for(Person_8 item : col){
			System.out.println(item);
		}
	}
}
