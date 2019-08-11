import java.lang.reflect.Array;
import java.util.*;

public class Sets_5 {
	public static void main(String[] args) {
		Set<String> set1 = new HashSet<>();
		Set<String> set2 = new LinkedHashSet<>();
		Set<String> set3 = new TreeSet<>();

//		System.out.println(System.console());
//		System.

		testSet(set1);
		testSet(set2);
		testSet(set3);
//		for(String element : set1){
//			System.out.println(element);
//		}
//		if(set1.contains("cat")){
//			System.out.println("Ther is cat");
//		}
		set2.add("ant");

		testSet(set1);
		set1.add("ant");
		System.out.println(set1);
		Set<String> intersection = new HashSet<>(set1);
		System.out.println(intersection);
//		intersection.retainAll(set2);
		System.out.println(intersection + "<-------");
		intersection.containsAll(set2);
		System.out.println(intersection);
		intersection.retainAll(set2);
		System.out.println(intersection);
//		System.out.println(set1);





	}
	public static void testSet(Set set){
		set.add("dog");
		set.add("cat");
		set.add("mouse");
		set.add("snake");
		set.add("bear");

		set.add("mouse");
//		System.out.println(set);
//		for(String element : set){
//			System.out.println(element);
//		}

		//		for ( ArrayList element: set.toArray()) {
//			System.out.println(element);
//		}

	}
}
