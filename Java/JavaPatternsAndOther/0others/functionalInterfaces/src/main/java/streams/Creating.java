package streams;

import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Arrays;
import java.util.List;
import java.util.Random;
import java.util.stream.DoubleStream;
import java.util.stream.IntStream;
import java.util.stream.LongStream;
import java.util.stream.Stream;

class Creating {
	public static void main(String[] args) throws IOException {
		System.out.println("java");
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

//	    Stream from an Array using Arrays.stream()
		String[] arr = new String[]{"a", "b", "c"};
		Stream<String> streamOfArrays = Arrays.stream(arr);

//		Stream using Stream.builder()
		Stream.Builder<String> builder = Stream.<String>builder();
		builder.add("a").add("b").add("c");
		Stream<String> s = builder.build();

		Stream<String> ss = Stream.<String>builder().add("a").add("b").add("c").build();

//		Creating an Empty Stream using Stream.empty()
		Stream<String> emptyStream = Stream.empty();

//		Creating an infinite Stream using Stream.generate() method
		Random random = new Random();
		Stream<Integer> streamInteger = Stream.generate(() ->  random.nextInt(100)).limit(5);

//		Creating an infinite Stream using Stream.iterate() method
		Stream<Integer> streamIterate = Stream.iterate(1, n -> n + 2);

//		Creating Stream of a File
//		Stream<String> streamOfStringsFromFile = Files.lines(Paths.get("/test"));

//		Crating Stream of primitives
		IntStream intStream = IntStream.range(1, 100);
		LongStream longStream = LongStream.range(1, 100);
		DoubleStream doubleStream = DoubleStream.builder().add(1.1).build();

	}
}
