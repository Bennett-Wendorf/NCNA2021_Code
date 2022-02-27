import java.util.Scanner;

public class LandEquality {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int rows = in.nextInt();
        int columns = in.nextInt();

        int zeroCount = 0;
        int twoCount = 0;
        boolean oneAtEnd = false;

        int temp = in.nextInt();
        if (temp == 0) zeroCount++;
        if (temp == 2) twoCount++;
        if (temp == 1) oneAtEnd = true;

        for (int i = 0; i < rows * columns - 2; i++) {
            temp = in.nextInt();
            if (temp == 0) zeroCount++;
            if (temp == 2) twoCount++;
        }

        temp = in.nextInt();
        if (temp == 0) zeroCount++;
        if (temp == 2) twoCount++;
        if (temp == 1) oneAtEnd = true;

        if (zeroCount > 1) {
            System.out.println("0");
        } else if (zeroCount == 1) {

            if(rows == 1 || columns == 1) {
                if (oneAtEnd) {
                    System.out.println("1");
                } else {
                    System.out.println("2");
                }
            }else {
                if(twoCount + zeroCount < rows * columns){
                    System.out.println("1");
                } else {
                    System.out.println("2");
                }
            }
        } else if (twoCount % 2 == 0) {
            System.out.println("0");
        } else {
            System.out.println((int) Math.pow(2, Math.floor(twoCount/2.0)));
        }

    }


}
