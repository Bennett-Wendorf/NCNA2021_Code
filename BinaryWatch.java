import java.util.Scanner;

public class BinaryWatch {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        while(in.hasNext()){
            var str = in.nextLine();
            solve(str);
        }
    }

    public static void solve(String s) {
        int[] arr = new int[4];
        for(int i = 0; i < 4; i++){
            arr[i] = Integer.parseInt(s.charAt(i)+ "");
        }


        for (int i = 8; i > 0; i=i/2) {
            char[] chars = new char[4];
            for (int j = 0; j < 4; j++) {
                if (arr[j]/i >= 1) {
                    chars[j] = '*';
                } else {
                    chars[j] = '.';
                }
                arr[j] = arr[j]%i;
            }
            System.out.println(chars[0] + " " + chars[1] + "   " + chars[2] + " " + chars[3]);
        }
    }
}
