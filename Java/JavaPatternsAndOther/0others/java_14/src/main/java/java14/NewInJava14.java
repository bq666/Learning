package java14;

class NewInJava14 {
	public record StudentRecord(Long rollNo, String name, int age, String email) {

	}

	public static void main(String[] args) {
		StudentRecord s = new StudentRecord(24l, "Robert", 24, "info@java.com");
		System.out.println(s.name());

		// Standard instanceof
		var student = new EngineeringStudent();
		if (student instanceof EngineeringStudent) {
			EngineeringStudent es = (EngineeringStudent) student;
			System.out.println(es.getStudentName());
		}


		//instanceof after Java 14 Pattaern Maching feature
//		if (student instanceof EngineeringStudent ess) {
//			System.out.println(ess.getStudentName());
//		}

	}

	static String formatterPatternSwitch(Object o) {
		return switch (o) {
			case Integer i -> String.format("int %d", i);
			case Long l    -> String.format("long %d", l);
			case Double d  -> String.format("double %f", d);
			case String s  -> String.format("String %s", s);
			default        -> o.toString();
		};
	}
}
