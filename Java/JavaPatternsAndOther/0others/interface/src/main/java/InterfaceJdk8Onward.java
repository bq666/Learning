public interface InterfaceJdk8Onward {
	double Pi = 3.1415;

	void getName(String name);

	default void print() {
		System.out.println("bleble1");
	}

//	static void print() {
//		System.out.println("bleble2");
//	}
}
