package streams;

import java.util.Arrays;
import java.util.List;
import java.util.stream.Stream;

class Creating {
	public static void main(String[] args) {

//		Stream.of()
		Stream<String> stringStream = Stream.of("a", "b", "c", "d");
		Stream<Integer> integerStream = Stream.of(1, 2, 3, 4, 5);
		Integer[] array = {1, 2, 3, 4, 5, 5, 6};
		Stream<Integer> arrayStream = Stream.of(array);

//		Stream from a Collection using stream() & parallelStream() methods
		List<String> list = Arrays.asList("a", "b", "c");
		List<String> list1 = List.of("a", "b", "c");

		Stream<String> streamOfStrings = list.stream();
		Stream<String> streamOfStrings1 = list.parallelStream();

	}
}
