package dev.gaudnik.singleton;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;

class SingletonViolationBySerializationFix implements Serializable {

	public static SingletonViolationBySerializationFix instance = new SingletonViolationBySerializationFix();

	private SingletonViolationBySerializationFix() {
		System.out.println("crating instance....");
	}

	public static SingletonViolationBySerializationFix getInstance() {
		return instance;
	}

	private Object readResolve(){
		System.out.println("new readResolve() ...");
		return SingletonViolationBySerializationFix.getInstance();
	}

	public static void main(String[] args) throws IOException, ClassNotFoundException {
		var s1 = SingletonViolationBySerializationFix.getInstance();
		var s2 = SingletonViolationBySerializationFix.getInstance();
		System.out.println("hash code s1: " + s1.hashCode());
		System.out.println("hash code s2: " + s2.hashCode());

		var oos = new ObjectOutputStream(new FileOutputStream("./s2.ser"));
		oos.writeObject(s2);

		var ois = new ObjectInputStream(new FileInputStream("./s2.ser"));
		var s3 = (SingletonViolationBySerializationFix) ois.readObject();
		System.out.println("hash code s3: " + s3.hashCode());
	}

}
