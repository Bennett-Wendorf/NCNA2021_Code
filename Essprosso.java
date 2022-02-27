import java.util.Scanner;

public class Essprosso {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int numTimes = 0;

        int n = in.nextInt(); // customers
        int s = in.nextInt(); // max
        in.nextLine();

        int currWater = s;
        String line;
        Scanner stringParse;
        int numShots;

        for (int i = 0; i < n; i++) {
            line = in.nextLine();
            stringParse = new Scanner(line);
            if(!stringParse.hasNextInt()) {
                stringParse.close();
                String newLine = line.substring(0, line.length()-1);
                stringParse = new Scanner(newLine);
                numShots = stringParse.nextInt();
                numShots++; // Add 1 to it to account for the latte
            } else {
                numShots = stringParse.nextInt();
            }
            if (numShots > currWater) {
                numTimes++;
                currWater = s;
            }
            currWater -= numShots;
            stringParse.close();
        }
        System.out.println(numTimes);
    }
}
