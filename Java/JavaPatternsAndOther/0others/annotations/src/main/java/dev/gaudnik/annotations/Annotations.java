package dev.gaudnik.annotations;

import java.util.ArrayList;
import java.util.List;

class Annotations<T> extends Object {

	@Deprecated
	static void doSomething() {

	}

	@Override
	public int hashCode() {
		return 1;
	}

	@SuppressWarnings("unchecked")
	public void uncheckedCheck() {

	}

	public static <T> T[] unsafe(T... elements) {
		return elements;
	}

	public static <T> T[] broken(T seed) {
		T[] plant = unsafe(seed, seed, seed);
		return plant;
	}

	private List<T> versions = new ArrayList();

	@SafeVarargs
	public final void safe(T... toAdd) {
		for (T version : toAdd) {
			versions.add(version);
		}
	}

	public void plant() {
//		String[] plants = broken("seed");
//		this.safe("test", "test");
	}

	public static void main(String[] args) {
		var test = new Annotations<String>();
		test.plant();
	}


}

