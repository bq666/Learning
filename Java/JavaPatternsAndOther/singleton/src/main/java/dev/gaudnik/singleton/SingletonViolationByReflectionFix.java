package dev.gaudnik.singleton;

import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationTargetException;

class SingletonViolationByReflectionFix {
	public static SingletonViolationByReflectionFix instance = new SingletonViolationByReflectionFix();

	private SingletonViolationByReflectionFix() {
		System.out.println("creating instance.....");
		if (instance != null) {
			throw new RuntimeException("Can't create instance. Please use getInstance()");
		}
	}

	public static SingletonViolationByReflectionFix getInstance(){
		return instance;
	}

	public static void main(String[] args) throws ClassNotFoundException, NoSuchMethodException, InvocationTargetException, InstantiationException, IllegalAccessException {
		var s1 = SingletonViolationByReflectionFix.getInstance();
		var s2 = SingletonViolationByReflectionFix.getInstance();
		System.out.println("Hashcode of s1: " + s1.hashCode());
		System.out.println("Hashcode of s2: " + s2.hashCode());

		var clazz = Class.forName("dev.gaudnik.singleton.SingletonViolationByReflectionFix");
		Constructor<?> constructor = clazz.getDeclaredConstructor();
		var s3 = (SingletonViolationByReflectionFix) constructor.newInstance();
		System.out.println("Hashcode of s3: " + s3.hashCode());
	}
}
