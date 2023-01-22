package dev.gaudnik.singleton;

class SingletonEagerInitialization {
	private static SingletonEagerInitialization unique = new SingletonEagerInitialization();

	private SingletonEagerInitialization(){}

	public static SingletonEagerInitialization getInstance(){
		return unique;
	}
}
