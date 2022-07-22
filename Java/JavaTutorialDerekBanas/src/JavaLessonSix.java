import java.util.*;
import java.io.*;

public class JavaLessonSix {
	static Scanner userInput = new Scanner(System.in);

	public static void main(String[] args) {
		try {
			getAFile("./somestuff.txt");
		} catch (IOException e) {
			System.out.println("An Io Error Occurred");
		}
	}


	//		System.out.println("How old are you?");
//		int age = checkValidAge();
//		if(age != 0){
//			System.out.println("You are " + age + " years old");


	//		divideByZero(10);


	private static void getAFile(String fileName) throws IOException, FileNotFoundException {
		FileInputStream file = new FileInputStream(fileName);
	}
}
		//		try {
//			FileInputStream file = new FileInputStream(fileName);
//		} catch (FileNotFoundException e) {
//			System.out.println("Sorry can't find that file");
//		} catch (IOException e) {
//			System.out.println("test");
//		}
//	}

//		} catch(IOException e) {
//			System.out.println("Unknown IO Error");
//		} catch(ClassNotFoundException | IOException e) {}
//		 catch(Exception e){
//			System.out.println("Some error occurred");
//		} finally {
//			System.out.println("");
//		}

//	private static int checkValidAge(){
//		try{
//			return userInput.nextInt();
//		} catch (InputMismatchException e){
//			userInput.next();
//			System.out.println("That isn't a whole number");
//			return 0;
//		}
//	}

//	private static void divideByZero(int a){
//		try{
//			System.out.println(a / 0);
//		} catch (ArithmeticException e){
////			System.out.println("You can't do that" + e );
//			System.out.println(e.getMessage());
//			System.out.println(e.toString());
//			e.printStackTrace();
//		}
//	}

