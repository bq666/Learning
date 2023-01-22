package test.sealed.JDK15;

public class TestSealedJDK15 {

}

// classes or interfaces started from modifier sealed or non-sealed should have annotation @SuppressWarnings("preview")

@SuppressWarnings("preview")
sealed interface Animal
		permits Dog, Cat, Tiger { }

@SuppressWarnings("preview")
non-sealed class Dog implements Animal{} // allowed , The class testSealedJDK15.Dog with a sealed direct superclass or a sealed direct superinterface testSealedJDK15.Animal should be declared either final, sealed, or non-sealed

@SuppressWarnings("preview")
//non-sealed interface Dog1 extends Animal{} // not allowed, The type testSealedJDK15.Dog1 extending a sealed interface testSealedJDK15.Animal should be a permitted subtype of testSealedJDK15.Animal

//class testSealedJDK15.Dog implements testSealedJDK15.Animal{}

class Dog2 extends Dog{}

@SuppressWarnings("preview")
sealed interface Cat extends Animal permits Cat1{}

final class Cat1 implements Cat{}

//@SuppressWarnings("preview")
//non-sealed class Tiger implements Animal{} // not allowed , The class testSealedJDK15.Tiger with a sealed direct superclass or a sealed direct superinterface testSealedJDK15.Animal should be declared either final, sealed, or non-sealed

final class Tiger1 extends Tiger{}

//@SuppressWarnings("preview")
//sealed abstract class Parent permits Child1, Child2 {}

//@SuppressWarnings("preview")
//non-sealed class Child1 extends Parent{}

//@SuppressWarnings("preview")
//sealed class Child2 extends Parent{}

//class Child3 extends Child2{}  // not allowed, The class testSealedJDK15.Child3 with a sealed direct superclass or a sealed direct superinterface testSealedJDK15.Child2 should be declared either final, sealed, or non-sealed

//class Child4 extends Child1{}  // allowed

//@SuppressWarnings("preview")
//non-sealed class Child5 extends Child1{}  // not allowed, A class testSealedJDK15.Child5 declared as non-sealed should have either a sealed direct superclass or a sealed direct superinterface

//@SuppressWarnings("preview")
//sealed class MyClass{}  // not allowed , Sealed class lacks the permits clause and no top level or nested class from the same compilation unit declares testSealedJDK15.MyClass as its direct superclass.
