public interface InterfaceB {

	default String getName() {
		return "ElaB";
	}

	static String getSurname() {
		return "DoeA";
	}

}
