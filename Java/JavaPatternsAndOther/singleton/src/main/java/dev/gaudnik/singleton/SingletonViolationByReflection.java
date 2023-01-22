package dev.gaudnik.singleton;

import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationTargetException;

class SingletonViolationByReflection {
	public static SingletonViolationByReflection instance = new SingletonViolationByReflection();

	private SingletonViolationByReflection() {
		System.out.println("creating instance.....");
	}

	public static SingletonViolationByReflection getInstance(){
		return instance;
	}

	public static void main(String[] args) throws ClassNotFoundException, NoSuchMethodException, InvocationTargetException, InstantiationException, IllegalAccessException {
		var s1 = SingletonViolationByReflection.getInstance();
		var s2 = SingletonViolationByReflection.getInstance();
		System.out.println("Hashcode of s1: " + s1.hashCode());
		System.out.println("Hashcode of s2: " + s2.hashCode());

		var clazz = Class.forName("dev.gaudnik.singleton.SingletonViolationByReflection");
		Constructor<?> constructor = clazz.getDeclaredConstructor();
		var s3 = (SingletonViolationByReflection) constructor.newInstance();
		System.out.println("Hashcode of s3: " + s3.hashCode());
	}
}
