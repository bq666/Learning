import java.util.ArrayList;
import java.util.List;

public class ArrayList_1 {
	public static void main(String[] args){
		ArrayList<Integer> numbers = new ArrayList<>();


		numbers.add(10);
		numbers.add(100);
		numbers.add(40);
//		System.out.println(numbers.get(2));

		for(Integer item : numbers){
			item += 1;
			System.out.println(item);
		}

		numbers.removeIf(i -> i % 2 == 0);

		for(Integer item : numbers){
//			item += 1;
			System.out.println(item);
		}

		// List interface ...
		List<String> values = new ArrayList<>();

	}
}
