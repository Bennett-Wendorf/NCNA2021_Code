import java.util.Scanner;

public class Concert {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        int hours = in.nextInt();
        int days = in.nextInt();
        int[] times = new int[n];
        for (int i = 0; i < n; i++) {
            times[i] = in.nextInt();
        }

        int result = 0;
        int student = 0;
        for (int i = 0; i < days; i++) {
            int timeRemaining = hours;
            while (times[student] <= timeRemaining) {
                timeRemaining = timeRemaining - times[student];
                if (student == n-1) {
                    result++;
                    student = 0;
                } else {
                    student++;
                }
            }
        }
        System.out.println(result);
    }
}
