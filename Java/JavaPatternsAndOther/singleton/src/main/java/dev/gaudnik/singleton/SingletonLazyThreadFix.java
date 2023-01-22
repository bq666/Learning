package dev.gaudnik.singleton;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

class SingletonLazyThreadFix {

//	private static volatile SingletonLazyThreadFix instance = null; //lazy initialization all threads will se the same instance
	private static SingletonLazyThreadFix instance = null; //lazy initialization

	private SingletonLazyThreadFix() {
		System.out.println("creating....");
	}

//	public static synchronized SingletonLazyThreadFix getInstance() {
//		if (instance == null) {
//			instance = new SingletonLazyThreadFix();
//		}
//		return instance;
//	}

	public static SingletonLazyThreadFix getInstance() {
		if (instance == null) {
			synchronized (SingletonLazyThreadFix.class){
				if (instance == null) { // double-checked locking In rare cases, double-checked locking also breaks the Principle of Singleton.
					instance = new SingletonLazyThreadFix();
				}
			}
		}
		return instance;
	}

	static void useSingleton() {
		var singleton = SingletonLazyThreadFix.getInstance();
		System.out.println("hash code of singleton: " + singleton.hashCode());
	}

	public static void main(String[] args) {
		ExecutorService service = Executors.newFixedThreadPool(2);
		service.submit(SingletonLazyThreadFix::useSingleton);
		service.submit(SingletonLazyThreadFix::useSingleton);
		service.shutdown();
	}
}
