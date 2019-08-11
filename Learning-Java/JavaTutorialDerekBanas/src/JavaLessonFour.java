import java.util.Scanner;

public class JavaLessonFour {
    private static Scanner userInput = new Scanner(System.in);
    public static void main(String[] args){
//        System.out.println("testtest");
//        int i = 1;
//        while (i <= 20) {
//            if (i == 3) {
//                i += 2;
//                continue;
//            }
//            System.out.println(i);
//            i++;
//            if((i%2) == 0){
//                i++;
//            }
//            if(i > 10){
//                break;
//            }
//        }


//        double myPi = 4.0;
//        double j = 3.0;
//        // 4 - 4/3 + 4/5 - 4/7
//        while(j < 2000000000){
//            myPi = myPi - (4/j) + (4/(j+2));
//            j += 4;
////            System.out.println(myPi);
//        }
//        System.out.println(myPi + "Value of PI: " + Math.PI);

//        String contYorN = "Y";
//        int h = 1;
//
//        while (contYorN.equalsIgnoreCase("y")){
//            System.out.println(h);
//            System.out.print("Continue y or n? ");
//            contYorN = userInput.nextLine();
//            h++;
//        }

//        int k = 1;
//        do{
//            System.out.println(k);
//            k++;
//        } while (k < 10);
        int m, n;
        for (m = 1, n = 2; m <= 9 && n <=9 ; m++, n += 2){
            System.out.println(Integer.toString(m) + ' ' + Integer.toString(n));
        }

    }
}

