import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class EvenSubstrings {
    static String s;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        s = in.nextLine();
        int numQueries = in.nextInt();
        for(int i = 0; i < numQueries; i++){
            int firstNum = in.nextInt();
            int secondNum = in.nextInt();
//            System.out.println("in: " + firstNum + " " + secondNum);
            if (firstNum == 1) {
                solve1(s.substring(secondNum-1, in.nextInt()));
            } else {
                solve2(secondNum, in.next());
            }
        }
    }



    private static void solve1(String substr) {
//        System.out.println("S: " + substr);
        int count = 0;
        Map<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < substr.length()-1; i++) {
            for (char c : substr.substring(i).toCharArray()) {

                if (map.containsKey(c)) map.put(c, map.get(c) + 1);
                else map.put(c, 1);

                if (allEven(map)) {
//                    System.out.println(map.keySet() + " + " + map.values());
                    count++;
                }
            }
            map = new HashMap<>();
        }
        System.out.println(count);
    }

    private static boolean allEven(Map<Character, Integer> map) {
        boolean result = true;
        for (Character key : map.keySet()) {
            if (map.get(key)%2 == 1) {
                result = false;
                break;
            }
        }
        return result;
    }

    private static void solve2(int secondNum, String c) {
        s = s.substring(0,secondNum-1) + c + s.substring(secondNum);
    }
}

