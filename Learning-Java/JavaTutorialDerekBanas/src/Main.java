public class Main {
    public static void main(String[] args){
        System.out.println("Hello World!");
        byte bigByte = 127;
        short bigShort = 32767;
        int bigInt = 2147483647;
        long bigLong = 34028235L;
        float bigFloat = 3.14F;
        double bigDouble = 3.12;

        boolean trueOrFalse = true;

        char randomChar = 66;
        char anotherChar = 'A';

        String randomString = "I'm a random string";
        String anotherString = "Stuff";

        String andAnotherString = randomString + " " + anotherString;

        System.out.println(andAnotherString);
        System.out.println(randomChar);

        System.out.println(Integer.MAX_VALUE);
        System.out.println(Float.MAX_VALUE);
        System.out.println(Double.MAX_VALUE);
        System.out.println(Byte.toString(bigByte));
        System.out.println(bigByte);

        double aDoubleValue = 3.1415;
        int doubleToInt = (int) aDoubleValue;
        String intString = Double.toString(aDoubleValue);

        double intFromString = Double.parseDouble(intString);

        System.out.println(intString + " " + Integer.toString(doubleToInt) + "<---");
        System.out.println(intString);
        System.out.println(intFromString);

    }
}
