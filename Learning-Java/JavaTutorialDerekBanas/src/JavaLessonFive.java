import java.util.Scanner;

public class JavaLessonFive {
	static double myPI = 3.14159;  // Class Variable
	static int randomNumber;
	static Scanner userInput = new Scanner(System.in);
	public static void main(String[] args){
		System.out.println(getRandomNum());
		int guessResult = 1;
		int randomGuess = 0;
		while (guessResult != -1){
			System.out.print("Guess a number between 0 and 50: ");
			randomGuess = userInput.nextInt();
			guessResult = checkGuess(randomGuess);
		}
		System.out.println("Yes the random number is " + randomGuess);
//		System.out.println(addThem(1, 2, 5));
////		System.out.println(myPI);
//		int d = 5;
//		System.out.println(d);

	}
	private static int getRandomNum(){
		randomNumber = (int) (Math.random() * 51);
		return randomNumber;

	}
	private static int checkGuess(int guess){
		if(guess == randomNumber){
			return -1;
		} else {
			return guess;
		}
	}
//	public static int addThem(int a, int b){
//		double smallPI = 3.140;
//		double myPI = 999;
//		System.out.println("Global " + myPI);
//		return 1;
//	}
	private static int addThem(int a, int b, int d){
		int c = a + b;
		d += 1;
		System.out.println(d);
		return c;
	}

}

