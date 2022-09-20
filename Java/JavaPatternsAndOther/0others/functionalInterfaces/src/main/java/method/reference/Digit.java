package method.reference;

class Digit {
	public static boolean isSingleDigit(int value) {
		return value >= -10 && value <= 10;
	}

	public static void main(String[] args) {
//		Method references to a static method of a class :
//		Lambda
		A a1 = (x) -> { return x > -10 && x < 10; };
		System.out.println(a1.checkSingleDigit(10));

//		Method Reference
		A a2 = Digit::isSingleDigit;
		System.out.println(a2.checkSingleDigit(10));
	}
}
