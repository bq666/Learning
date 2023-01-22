public interface InterfaceA {

	default String getName() {
		return "ElaA";
	}

	static String getSurname() {
		return "DoeA";
	}

}
