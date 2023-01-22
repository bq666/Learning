package dev.gaudnik.singleton;

class SingletonHolderClass {

	private SingletonHolderClass() {
		System.out.println("creating ....");
	}

	static class Holder{
		static final SingletonHolderClass INSTANCE = new SingletonHolderClass(); // lazy
	}

	public static SingletonHolderClass getInstance() {
		return Holder.INSTANCE;
	}

	public static void main(String[] args) {
		var s1 = SingletonHolderClass.getInstance();
		var s2 = SingletonHolderClass.getInstance();
		var s3 = SingletonHolderClass.getInstance();

		System.out.println("hash code s1: " + s1.hashCode());
		System.out.println("hash code s2: " + s2.hashCode());
		System.out.println("hash code s3: " + s3.hashCode());
	}

}
