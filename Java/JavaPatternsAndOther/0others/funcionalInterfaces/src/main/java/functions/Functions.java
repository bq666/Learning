package functions;

import java.util.Random;
import java.util.function.BiConsumer;
import java.util.function.BiPredicate;
import java.util.function.Consumer;
import java.util.function.IntBinaryOperator;
import java.util.function.IntPredicate;
import java.util.function.IntSupplier;
import java.util.function.ToIntFunction;
import java.util.logging.ConsoleHandler;
import java.util.logging.Level;
import java.util.logging.Logger;

class Functions implements A{

	private static final Logger LOGGER = Logger.getLogger(Functions.class.getName());

	public static void main(String[] args) {
		ConsoleHandler consoleHandler = new ConsoleHandler();
		consoleHandler.setLevel(Level.INFO);
		LOGGER.setLevel(Level.INFO);
		IntPredicate predicate = i -> (i > -10) && (i < 10);

		int randomInt = new Random().ints(-10, 10).findFirst().orElse(0);
		LOGGER.log(Level.INFO, "{0}", predicate.test(randomInt));

		ToIntFunction<String> toIntFunction = String::length;
		LOGGER.log(Level.INFO, "{0}", toIntFunction.applyAsInt("how long is this string ?"));

		Consumer<String> consumer = s -> LOGGER.log(Level.INFO, "{0}", s);
		consumer.accept("test 2");

		IntSupplier supplier = () -> (new Random().nextInt(50));
		LOGGER.log(Level.INFO, "{0}", supplier.getAsInt());

		BiPredicate<Integer, Integer> biPredicate = (i, j) -> (i + j) % 2 == 0;
		LOGGER.log(Level.INFO, "{0}", biPredicate.test(1, 2));

		IntBinaryOperator biFunction = (i, j) -> (i + j) % 2;
		LOGGER.log(Level.INFO, "{0}", biFunction.applyAsInt(1, 2));

		BiConsumer<Integer, Integer> biConsumer = (i, j) -> LOGGER.log(Level.INFO, "{0}", (i + j) % 2);
		biConsumer.accept(1, 2);

		A.m1();
	}
}

interface A {
	public static void m1() {
		System.out.println("interface static method");
	}
}
