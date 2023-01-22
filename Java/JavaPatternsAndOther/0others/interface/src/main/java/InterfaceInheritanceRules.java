class InterfaceInheritanceRules implements InterfaceA, InterfaceB{

	@Override
	public String getName() {
		return InterfaceA.super.getName();
	}

	public static void main(String[] args) {
		var obj1 = new InterfaceInheritanceRules();
		InterfaceA.getSurname();
	}
}
