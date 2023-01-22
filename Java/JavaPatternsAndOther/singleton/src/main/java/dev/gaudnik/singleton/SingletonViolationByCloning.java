package dev.gaudnik.singleton;

class SingletonViolationByCloning implements Cloneable{

	public static SingletonViolationByCloning instance = new SingletonViolationByCloning();

	private SingletonViolationByCloning() {
		System.out.println("Creating instance ...");
	}

	public static SingletonViolationByCloning getInstance() {
		return instance;
	}

	protected Object clone() throws CloneNotSupportedException{
		return super.clone();
	}

	public static void main(String[] args) throws CloneNotSupportedException {
		var s1 = SingletonViolationByCloning.getInstance();
		var s2 = SingletonViolationByCloning.getInstance();
		System.out.println("hash code of s1: " + s1.hashCode());
		System.out.println("hash code of s2: " + s2.hashCode());

		var s3 = (SingletonViolationByCloning) s2.clone();
		System.out.println("hash code of s3: " + s3.hashCode());
	}
}
