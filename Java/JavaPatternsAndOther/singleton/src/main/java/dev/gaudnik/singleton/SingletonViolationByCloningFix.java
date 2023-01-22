package dev.gaudnik.singleton;

class SingletonViolationByCloningFix implements Cloneable{

	public static SingletonViolationByCloningFix instance = new SingletonViolationByCloningFix();

	private SingletonViolationByCloningFix() {
		System.out.println("Creating instance ...");
	}

	public static SingletonViolationByCloningFix getInstance() {
		return instance;
	}

	protected Object clone() throws CloneNotSupportedException{
		if (instance != null) {
			throw new CloneNotSupportedException("can't create instance. Please use getInstance() to create it.");
		}
		return super.clone();
	}

	public static void main(String[] args) throws CloneNotSupportedException {
		var s1 = SingletonViolationByCloningFix.getInstance();
		var s2 = SingletonViolationByCloningFix.getInstance();
		System.out.println("hash code of s1: " + s1.hashCode());
		System.out.println("hash code of s2: " + s2.hashCode());

		var s3 = (SingletonViolationByCloningFix) s2.clone();
		System.out.println("hash code of s3: " + s3.hashCode());
	}
}
