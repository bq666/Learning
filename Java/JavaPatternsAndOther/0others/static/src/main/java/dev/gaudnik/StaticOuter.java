package dev.gaudnik;

class StaticOuter {
	static int i = 66;
	private static int n = 77;

	static class Inner {
		void m1(){
			System.out.println("i is " + i + n);
		}
	}

	public static void main(String[] args) {
		StaticOuter.Inner inner = new StaticOuter.Inner();
		inner.m1();
	}
}
