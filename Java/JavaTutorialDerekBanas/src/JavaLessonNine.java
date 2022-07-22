import java.util.Arrays;

public class JavaLessonNine {
	public static void main(String[] args){
		int[] randomArray;
		randomArray = new int[20];
		randomArray[19] = 2;

		int[] numberArray = new int[10];

		System.out.println(randomArray[1]);

		for(int i = 0; i < randomArray.length; i++){
			randomArray[i] = i;
		}


		int i = 66;
		for (int item : randomArray){
			item += i;
			System.out.println(item);
			i++;
		}
		System.out.println(Arrays.toString(randomArray));

		int k = 1;
		while (k <= 41){ System.out.print('-'); k++;}
		System.out.println();

		for(int j = 0; j < numberArray.length; j++){
			System.out.print("| " + j + " ");
		}
		System.out.println("|");

		String[][] multiArray = new String[10][10];

		for(i = 0; i < multiArray.length; i++){
			for(int j = 0; j < multiArray[i].length; j++){
				multiArray[i][j] = i + " " + j;
//				System.out.println(multiArray[i][j]);
			}
		}
		k = 0;
		while (k <= 41){ System.out.print('-'); k++;}
		System.out.println();

		for(i = 0; i < multiArray.length; i++){
			for(int j = 0; j < multiArray[i].length; j++){
				System.out.print("| " + multiArray[i][j] + " ");
			}
			System.out.println();
		}
		k = 0;
		while (k <= 41){ System.out.print('-'); k++;}
		System.out.println();


		for(String[] rows : multiArray){
			for(String column : rows){
				System.out.print("| " + column + " ");
			}
			System.out.println();
		}



		k = 0;
		while (k <= 41){ System.out.print('-'); k++;}
		System.out.println();


		for(int j = 0; j < numberArray.length; j++){
			numberArray[j] = j + 10;
			System.out.print("| " + j + " ");
		}
		System.out.println("|");

		int[] numberCopy = Arrays.copyOf(numberArray, 20);
		for(int j = 0; j < numberCopy.length; j++){
			numberCopy[j] = 666 + j;
//			System.out.print(numberCopy[j]);
		}


		for(int j = 0; j < numberCopy.length; j++){
			System.out.print("| " + numberCopy[j] + " ");
		}
		System.out.println("|");

		int[] numberCopy2 = Arrays.copyOfRange(numberCopy, 4, 5);
		System.out.println(Arrays.toString(numberCopy2));

		k = 0;
		while (k <= 41){ System.out.print('-'); k++;}
		System.out.println();

		int[] moreNumbers = new int[100];
		Arrays.fill(moreNumbers, 2);

		char[][] boardGame = new char[10][10];
		for(char[] row : boardGame){
			Arrays.fill(row, '*');
		}

		System.out.print(Arrays.toString(boardGame[9]));

		int[] numToSort = new int[10];
		for(i = 0; i < 10; i++){
			numToSort[i] = (int) (Math.random() * 10);
		}
		System.out.print('\n');
		System.out.print(Arrays.toString(numToSort));
		System.out.print('\n');
		Arrays.sort(numToSort);

		System.out.print(Arrays.toString(numToSort));
		int whereIs9 = Arrays.binarySearch(numToSort, 9);
		System.out.println("\n" + whereIs9);


//		for(int row : numberArray){
//			System.out.print(row);
//		}

		//		for(String[] row : multiArray){
//			System.out.println(row);
//		}

//		System.out.println(Arrays.toString(multiArray[1]));

//		String nazwa = "abcdefghijklmnop";
//		System.out.println(nazwa.charAt(1));
//		String [] stringArray = {"just", "random", "words"};
//		System.out.println(Arrays.toString(stringArray));
	}
}
