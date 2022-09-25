package method.reference;

import method.reference.interfaces.C;
import method.reference.interfaces.D;

public class Employee {

	String eName;
	int eAge;

	public Employee() {}

	public Employee(String eName, int eAge) {
		this.eName = eName;
		this.eAge = eAge;
	}


	public void getInfo() {
		System.out.println("I am a method of class Employee");
	}

	public static void main(String[] args) {
//      Constructor Reference
// 		Lambda
		C c1 = () -> new Employee();
		c1.getEmployee().getInfo();
		D d1 = (name, age) -> new Employee(name, age);
		d1.getEmployee("Tony", 34).getInfo();

//		Method Reference
		C c2 = Employee::new;
		c2.getEmployee().getInfo();
		D d2 = Employee::new;
		d2.getEmployee("Tony", 34).getInfo();
	}
}
