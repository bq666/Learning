import java.util.Arrays;

public class JavaLessonThirteen {
	public static void main(String[] args){
		String randomString = "i'm just a randomString";
		String gotToQuote = "He said, \"I'm here\" ";
		int numTwo = 2;
		System.out.println(randomString + gotToQuote + numTwo);

		String upperCaseText = "ABC";
		String lowerCaseText = "abc";
		if(upperCaseText.equalsIgnoreCase(lowerCaseText)){
			System.out.println("Eówne");
		}

		String letters = "abbcdea";
		String moreLetters ="abcdex";
		System.out.println("2nd char: " + letters.charAt(1));
		System.out.println(letters.compareTo(moreLetters));
		System.out.println(letters.contains("abc"));
		System.out.println(letters.endsWith("dea"));
		System.out.println(letters.startsWith("abc"));
		System.out.println(letters.indexOf('b'));
		System.out.println(letters.lastIndexOf('b'));
		System.out.println(letters.length());
		System.out.println(letters.replace("bb", "x"));

		String [] letterArray = letters.split("");
		System.out.println(Arrays.toString(letterArray));

		char[] charArray = letters.toCharArray();
		System.out.println(Arrays.toString(charArray));

		System.out.println(letters.substring(1,4));

		StringBuilder randSB = new StringBuilder("A random value");
		System.out.println(randSB.capacity());
		System.out.println(randSB);
		randSB.reverse();
		System.out.println(randSB);
		randSB.reverse();
		randSB.append(" again");
		System.out.println(randSB);
		randSB.delete(14 , 21);
		System.out.println(randSB);
	}
}
