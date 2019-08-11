public class Three_my{
    public static void main(String[] args)
    {
        int randomNumber = (int)(Math.random() * 50);
        if (randomNumber < 17)
        {
            System.out.println(randomNumber);
        }
        else if (randomNumber > 40)
        {
            System.out.println("The random number is greater than 40");
        }
        else if (randomNumber == 18)
        {
            System.out.println("The random number is equal to 18");
        }
        System.out.println("The random number is: " + randomNumber);
        int a = 10;
        if ((a > 10) && (a++ > 10))
        {
            System.out.println("\nI turned false into true" + a);
        }
        System.out.println(a + " <----");
        int valueOne = 3;
        int valueTwo = 888;

        int biggestValue = (valueOne > valueTwo) ? valueOne : valueTwo;
        System.out.println(biggestValue);

        char theGrade = 'b';
        switch (theGrade)
        {
            case 'A':
                System.out.println("Great A");
                break;
            case 'B':
                System.out.println("Great B");
                break;
            case 'C':
                System.out.println("Great C");
                break;
            case 'D':
                System.out.println("Great D");
                break;
            default:
                System.out.println("Great jobbbbb");
                break;
        }

    }
}