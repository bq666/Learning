package dev.gaudnik;

class StaticExmaple {

	//method call from static variable as it's assignment statement
	private static int i = m3();

	static{
		m1(); //method call from static block
		System.out.println("Static block");
	}

	public static void m1(){
		m2(); //method call from another static method
		// accessing static variable directly without class name
		System.out.println(AllAboutSatic.i);
		System.out.println("Static method m1()");
	}

	private static void m2(){
		System.out.println("Static method m2()");
		//accessing static variable with class name from static method
		System.out.println(AllAboutSatic.i);
	}

	private static int m3() {
		return 6;
	}

	public void m4() {
		// accessing static variable with class name from non-static method
		System.out.println(AllAboutSatic.i);
		m3(); //method call from another non-static method
	}

	public static void main(String[] args) {
		m1(); m2(); //method call from main method
		System.out.println("main() method");
	}

	private static class AllAboutSatic {
		public static int i = 7;
	}
}
