import java.util.*;
import java.io.*;

public class brycewa {
    public static boolean matches(char first, char second) {
        if (first == '?' || second == '?') {
            return true;
        }

        Map<Character, Character> matching = Map.of(
            '(', ')',
            '<', '>',
            '[', ']',
            '{', '}'
        );

        return matching.containsKey(first) && matching.get(first) == second;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String line = in.nextLine();

        int n = line.length();
        int[][] ways = new int[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j < i) {
                    ways[i][j] = 1;
                }
            }
        }

        for (int len = 2; len <= n; ++len) {
            for (int i = 0; true; ++i) {
                int j = i+len-1;
                if (j >= n) break;
                if (line.charAt(i) == '?' && line.charAt(j) == '?') {
                    ways[i][j] += 4*ways[i+1][j-1];
                } else if (matches(line.charAt(i), line.charAt(j))) {
                    ways[i][j] += ways[i+1][j-1];
                }
                for (int k = i+1; k+1 < j; ++k) {
                    ways[i][j] += ways[i][k] * ways[k+1][j];
                }
            }
        }
        System.out.println(ways[0][n-1]);
    }
}
