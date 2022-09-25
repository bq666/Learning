package method.reference;

import method.reference.interfaces.B;

class Addition {
	public int sum(int a, int b) {
		return a + b;
	}

	public static void main(String[] args) {
//		Method references to an Instance method of a class :
		Addition addition = new Addition();

//		Lambda
		B b1 = (a, b) -> a + b;
		var test1 = b1.add(10, 14);
		System.out.println(test1);

//	    Method Reference
		B b2 = addition::sum;
		var test2 = b2.add(100, 140);
		System.out.println(test2);

	}
}
