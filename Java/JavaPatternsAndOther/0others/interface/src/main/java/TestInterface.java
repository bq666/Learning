class TestInterface implements OuterInterface.NestedInterface{
	public static void main(String[] args) {
		OuterInterface.NestedInterface nestedInterface = new TestInterface();
		nestedInterface.nam();
	}

	@Override
	public void nam() {
		System.out.println("hello from nested interface");
	}

}
