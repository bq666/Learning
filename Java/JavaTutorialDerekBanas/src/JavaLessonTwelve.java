import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

public class JavaLessonTwelve {
	public static void main(String[] args){

		LinkedList linkedListOne = new LinkedList();
		LinkedList<String> names = new LinkedList<>();

		linkedListOne.add(10);
		linkedListOne.add("Jaś fasola");

//		names.add(10);
		names.add("Ahmed Bennani");
		names.add("Ali Syed");

		for(String item : names){
			System.out.println(item);
		}

		names.addLast("mama mija");
		System.out.println(names.size());
		names.set(2, "alan");
//		names.remove(0);
//		names.remove("alan");
		System.out.println("\nFirst index " + names.get(0));
		System.out.println("\nLast index " + names.getLast());

		System.out.println("---------");
		for(String item : names){
			System.out.println(item);
		}

		System.out.println("------------");
		LinkedList<String> copyList = new LinkedList<>(names);
		System.out.println(names);
		for(String item : copyList){
			System.out.println(item);
		}
		if(names.contains("alan")){
			System.out.println("\nNoahs Here");
		}
		if(names.containsAll(copyList)){
			System.out.println("copy list has");
		}
		System.out.println(names.indexOf("alan"));
//		names.clear();
		System.out.println(names.peek());

		names.add(0, "milen");
		System.out.println(names);
//		names.poll();
//		names.pollLast();
		names.push("maenda");
		names.pop();
//		System.out.println(names);
		System.out.println(names);
		//		System.out.println(Arrays.toString(linkedListOne));
		System.out.println("-----------------");

		Object[] nameArray = new Object[4];
//		System.out.println(Arrays.toString(nameArray));
		nameArray = names.toArray();
		System.out.println(Arrays.toString(nameArray));


	}
}
