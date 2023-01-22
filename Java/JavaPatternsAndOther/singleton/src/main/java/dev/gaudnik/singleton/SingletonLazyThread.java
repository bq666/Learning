package dev.gaudnik.singleton;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

class SingletonLazyThread {

	private static SingletonLazyThread instance = null;

	private SingletonLazyThread() {
		System.out.println("creating....");
	}

	public static SingletonLazyThread getInstance() {
		if (instance == null) {
			instance = new SingletonLazyThread();
		}
		return instance;
	}

	static void useSingleton() {
		var singleton = SingletonLazyThread.getInstance();
		System.out.println("hash code of singleton: " + singleton.hashCode());
	}

	public static void main(String[] args) {
		ExecutorService service = Executors.newFixedThreadPool(2);
		service.submit(SingletonLazyThread::useSingleton);
		service.submit(SingletonLazyThread::useSingleton);
		service.shutdown();
	}
}
