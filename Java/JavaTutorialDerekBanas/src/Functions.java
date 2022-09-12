import java.util.function.Consumer;
import java.util.function.Function;
import java.util.function.Predicate;

class Functions {

    public static void main(String[] args) {
        Predicate<Integer> predicate = (i) -> (i > -10) && (i < 10);
        System.out.println(predicate.test(10));

        Function<String, Integer> function = String::length;
        System.out.println(function.apply("test 1"));

        Consumer<String> consumer = s -> System.out.println(s);
        consumer.accept("test 2");
    }
}
