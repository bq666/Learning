import java.util.Random;
import java.util.Scanner;
//import
//import java.util.*;

public class Two {
    private static Scanner userInput = new Scanner(System.in);
    private static int numberEntered;
    private static int numberEntered2 = 5;
    public static void main(String[] args){
//        System.out.print("Your favorite number: ");
////        int numberEntered = 0;
//        if (userInput.hasNextInt()){
//            numberEntered = userInput.nextInt();
//            System.out.println(numberEntered);
//        } else {
//            System.out.println("Enter integer");
//        }
        System.out.println(numberEntered + numberEntered);
        System.out.println(Math.abs(numberEntered));
        System.out.println(Math.abs(numberEntered));
//        int b = Three_my.cos(10);
//        System.out.println(Three_my.cos(10));
        System.out.println(Math.max(5, 4));
        System.out.println(Math.min(5, 4));
        Random random_my = new Random();
        System.out.println(random_my.nextInt());
        double numSqrt = Math.sqrt(5.23);
        int numCeling = (int) Math.ceil(5.23);
        int numCeling1 = (int) Math.floor(5.23);
        int numCeling3 = (int) Math.round(5.63);

        System.out.println(numCeling);
        System.out.println(numCeling + numCeling1 + "<----" + numCeling3);
        System.out.println((int) (Math.random() * 10));
//        System.out.println(numCeling, numCeling1, numCeling3);

//        int a = Three_my.cos(10);
//        System.out.println(a);
    }
}
