package method.reference;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

class Numbers {

	public static void main(String[] args) {
		List<Integer> numbers = Arrays.asList(15, 33, 24, 40, 2, 19, 25, 60);

//		Using Anonymous Inner class
		Collections.sort(numbers, new Comparator<Integer>() {
			public int compare(Integer o1, Integer o2) {
				return o1.compareTo(o2);
			}
		});

//		Using Lambda Expression
		Collections.sort(numbers, (o1, o2) -> o1.compareTo(o2));

//		Using Method Reference
		Collections.sort(numbers, Integer::compareTo);

	}
}
