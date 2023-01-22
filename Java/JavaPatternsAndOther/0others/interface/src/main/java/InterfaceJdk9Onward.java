public interface InterfaceJdk9Onward {
	double Pi = 3.1415;

	void getName(String name);

	private void print1() {
		System.out.println("bleble1");
	}

	private static void print2() {
		System.out.println("bleble2");
	}


	default void dm() {
		System.out.println("I am a default method");
		// calling private methods inside interface
		pm();
		psm();
	}
	private void pm() {
		System.out.println("I am a private method");
	}
	private static void psm() {
		System.out.println("I am a private static method");
	}


	public abstract void am();

	public default void dm2() {
		pm2();   //private method inside default method
		psm2();  //private static method inside other non-static method
	}

	public static void sm() {
		psm2(); //private static method inside other static method
	}

	private void pm2(){
		System.out.println("private method");
	}

	private static void psm2(){
		System.out.println("private static method");
	}
}
