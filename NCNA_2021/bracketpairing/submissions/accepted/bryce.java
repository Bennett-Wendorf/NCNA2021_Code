import java.util.*;
import java.io.*;

public class bryce {
    public static long multiplier(char first, char second) {
        if (first == '?' && second == '?') {
            return 4;
        }

        Map<Character, Character> matching = Map.of(
            '(', ')',
            '<', '>',
            '[', ']',
            '{', '}'
        );

        if (matching.containsKey(first) && second == '?') {
            return 1;
        }
        if (matching.containsValue(second) && first == '?') {
            return 1;
        }

        return matching.containsKey(first) && matching.get(first) == second ? 1 : 0;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String line = in.nextLine();

        int n = line.length();
        long[][] ways = new long[n+1][n+1];
        for (int i = 0; i < ways.length; ++i) {
            for (int j = 0; j < ways[i].length; ++j) {
                if (j < i) {
                    ways[i][j] = 1;
                }
            }
        }

        for (int len = 2; len <= n; ++len) {
            for (int i = 0; true; ++i) {
                int j = i+len-1;
                if (j >= n) break;
                for (int k = i+1; k <= j; ++k) {
                    ways[i][j] += (multiplier(line.charAt(i), line.charAt(k)) * ways[i+1][k-1]) * ways[k+1][j];
                }
            }
        }
        System.out.println(ways[0][n-1]);
    }
}
