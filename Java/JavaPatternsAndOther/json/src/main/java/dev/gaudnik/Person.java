package dev.gaudnik;

public class Person {

	String name;
	Integer age;
	String profession;

	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public Integer getAge() {
		return age;
	}
	public void setAge(Integer age) {
		this.age = age;
	}
	public String getProfession() {
		return profession;
	}
	public void setProfession(String profession) {
		this.profession = profession;
	}

	@Override
	public String toString() {
		return "Person [name=" + name + ", age=" + age + ", profession=" + profession + "]";
	}
}
