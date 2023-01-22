package streams;

import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.Setter;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.Optional;
import java.util.function.Predicate;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.util.stream.Stream;

class Converting {
	public static void main(String[] args) {
//		Converting a Stream of strings to a List
		List<String> strings = Stream.of("this", "is", "a", "list", "of", "strings").collect(Collectors.toList());

//		Converting a Stream of int to a List of Integer
		List<Integer> ints = IntStream.of(1, 2, 3, 4, 5, 6).boxed().collect(Collectors.toList());
		List<Integer> ints2 = IntStream.of(1, 2, 3, 4, 5, 6).mapToObj(Integer::valueOf).collect(Collectors.toList());

//		Converting an IntStream to an int array
		int[] intArray1 = IntStream.of(1, 2, 3, 4, 5, 6).toArray();

//		Printing streams
		Stream<String> stringStream = Stream.of("this", "is", "a", "list", "of", "strings");
		stringStream.forEach(System.out::print);
		System.out.println(strings.stream().collect(Collectors.toList()));
		stringStream.limit(4).forEach(System.out::print);  // <--- works for infinite stream
		stringStream.peek(System.out::print).count(); // <---  you can use stream after printing

//		Intermediate Operations
//		filter()
		Stream<String> s = Stream.of("lion", "cat", "monkey", "cow", "horse");
		s.filter(x -> x.startsWith("c")).forEach(System.out::print);
//		distinct()
		Stream<String> s1 = Stream.of("cat", "cat", "monkey", "cow", "cat");
		s.distinct().forEach(System.out::print);
//		limit() and skip()
		Stream<Integer> s2 = Stream.iterate(1, n -> n + 1);
		s.skip(9).limit(6).forEach(System.out::print);
//      sorted()
		Stream<String> streamOfStrings = Stream.of("Sunday", "Monday", "Wednesday", "Friday");
		streamOfStrings.sorted().forEach(System.out::print);
		streamOfStrings.sorted(Comparator.reverseOrder()).forEach(System.out::print);
//		peek()
		IntStream.rangeClosed(10, 20)
				.peek(n -> System.out.println("original element : " +n))         //prints value before multiplying by 3
				.map(n -> n * 3)
				.peek(n -> System.out.println("Tripled element : " +n))          //prints value before filtering
				.filter(n -> n % 2 == 0)
				.peek(n -> System.out.println("Divisible By 2 element : " +n))   //prints value after filtering but before summing
				.sum();

//		Terminal Operations
//		count()
		Stream<String> s3 = Stream.of("Cow", "Tiger", "Elephant");
		System.out.println(s.count());

//		min() and max()
		Stream<String> s4 = Stream.of("Java", "Python", "Scala");
		Optional min = s4.min((s5, s6) -> s5.length() - s6.length());
		min.ifPresent(System.out::println);

//		findAny() and findFirst()
		Optional firstEvenNumber = Stream.of(9, 5, 8, 7, 4, 9, 2, 11, 3)
				.filter(n -> n % 2 == 0)
				.findFirst();
		System.out.println(firstEvenNumber);
		Optional firstNumberDivisibleBy5 = Stream.of(9, 5, 8, 7, 4, 9, 2, 11, 10, 3)
				.filter(n -> n > 10)
				.filter(n -> n % 5 == 0)    //empty stream in this line
				.findFirst();
		System.out.println(firstNumberDivisibleBy5);

//      anyMatch( ), allMatch( ), and noneMatch( )
		List<String> listOfSkills = Arrays.asList("Core Java", "Spring Boot", "Hibernate", "Angular");

		Predicate<String> pred = x -> x.startsWith("S");
		System.out.println(listOfSkills.stream().anyMatch(pred));         // true
		System.out.println(listOfSkills.stream().allMatch(pred));         // false
		System.out.println(listOfSkills.stream().noneMatch(pred));        // false

//		forEach()
		Stream<String> streamofSkills = Stream.of("Java", "Python", "Angular");
		streamofSkills.forEach(System.out::println);

//		collect()
		Stream<String> streamOfSkills = Stream.of("Java", "Scala", "Python", "Spring");
		streamOfSkills
				.filter(x -> x.startsWith("S"))
				.collect(Collectors.toList())     //Collecting the result of a stream into a List
				.forEach(System.out::println);
		streamOfSkills
				.filter(x -> x.length() > 3)
				.collect(Collectors.toCollection(ArrayList::new))    //Collecting the result of a stream into a List of our choice
				.forEach(System.out::println);

//		reduce()
		List<String> letters = Arrays.asList("j", "a", "v", "a", "t", "e", "c", "h", "o", "n", "l", "i", "n", "e");
		String result = letters .stream()
				.reduce(" ", (partialString, element) -> partialString + element);
		System.out.println(result);
		String result2 = letters.stream().reduce(" ", String::concat);
	}
}

@Getter
@Setter
@AllArgsConstructor
class Programmer {
	private String name;
	private List<String> skills;

	public static void main(String[] args) {
		List<Programmer> listOfProgrammers = List.of(
				new Programmer("Programmer1", List.of("Java", "Python", "Angular")),
				new Programmer("Programmer2", List.of("Ruby", "Angular", "Java")),
				new Programmer("Programmer3", List.of("React", "Spring", "Angular"))
		);
//		map() vs flatMap()
		listOfProgrammers.stream()
				.map(Programmer::getName)
				.collect(Collectors.toList())
				.forEach(System.out::print);

		listOfProgrammers.stream()
				.flatMap(p -> p.getSkills().stream())
				.collect(Collectors.toList())
				.forEach(System.out::print);


	}
	//getters, setters, AllArgsConstructor
}

