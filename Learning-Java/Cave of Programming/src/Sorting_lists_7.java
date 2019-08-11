import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;


class StringLengthComparator implements Comparator<String>{
	 @Override
	public int compare(String s1, String s2){
	 	int len1 = s1.length();
	 	int len2 = s2.length();
	 	if (len1 == len2){return 0;}
	    return (len1 > len2)? 1: -1;
	 }
}

class AlphabeticalComparator implements Comparator<String>{
	@Override
	public int compare(String s1, String s2){
		return s1.compareTo(s2);
	}
}

class ReverseAlphabeticalComparator implements Comparator<String>{
	@Override
	public int compare(String s1, String s2){
		return -s1.compareTo(s2);
	}
}

class Person_here{
	private int id;
	private String name;
	public Person_here(int id, String name){
		this.id = id;
		this.name = name;
	}

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String toString(){
		return id + ": " + name;
	}
}

public class Sorting_lists_7 {
	public static void main(String[] args) {


		/////////// Sorting strings
		List<String> animals = new ArrayList<String>();
		animals.add("cat");
		animals.add("tiger");
		animals.add("lion");
		animals.add("snake");
		animals.add("mongoose");
		animals.add("dog");
		animals.add("mice");

		Collections.sort(animals, new ReverseAlphabeticalComparator());
//		Collections.sort(animals);
		System.out.println(animals);
		for(String animal : animals){
			System.out.println(animal);
		}


		//////////// Sorting numbers
		List<Integer> numbers = new ArrayList<>();
		numbers.add(3);
		numbers.add(36);
		numbers.add(37);
		numbers.add(34);
		numbers.add(39);
		numbers.add(1);

		Collections.sort(numbers, new Comparator<Integer>(){
			public int compare(Integer num1, Integer num2){
				return -num1.compareTo(num2);
			}
		});
		System.out.println(numbers);


		/////////////Sort arbitrary objects
		List<Person_here> people = new ArrayList<>();
		people.add(new Person_here(1, "Joe"));
		people.add(new Person_here(2, "Bob"));
		people.add(new Person_here(4, "John"));
		people.add(new Person_here(3, "Ali"));
		people.add(new Person_here(5, "Sue"));

		Collections.sort(people, new Comparator<Person_here>() {
			@Override
			public int compare(Person_here o1, Person_here o2) {
				if(o1.getName() == o2.getName()){return 0;}
				return o1.getName().compareTo(o2.getName());
				//				if(o1.getId() == o2.getId()){return 0;}
//				return (o1.getId() > o2.getId()? 1 : -1);
			}
		});
		System.out.println(people);
		for (Person_here item : people){
			System.out.println(item);
		}

	}

}
