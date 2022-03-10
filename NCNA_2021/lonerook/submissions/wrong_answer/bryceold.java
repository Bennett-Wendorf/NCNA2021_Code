import java.util.*;
import java.io.*;

public class bryceold {
    static int r, c;
    static char[][] board;

    public static boolean isDanger(int MASK, int i, int j) {
        int dr[] = {1, 2, 2, 1, -1, -2, -2};
        int dc[] = {2, 1, -1, -2, -2, -1, 1};

        for (int k = 0; k < 8; ++k) {
            int i_new = i + dr[k];
            int j_new = j + dc[k];

            if (i_new >= 0 && i_new < r && j_new >= 0 && j_new < c) {
                if (board[i_new][j_new] >= '0' && board[i_new][j_new] <= '8') {
                    if (((MASK >> board[i_new][j_new]) & 1) == 1) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        r = in.nextInt();
        c = in.nextInt();
        board = new char[r][c];

        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};

        int knight = 0;
        int start_r = -1, start_c = -1;
        for (int i = 0; i < r; ++i) {
            String line = in.next();
            for (int j = 0; j < c; ++j) {
                board[i][j] = line.charAt(j);
                if (board[i][j] == 'K') {
                    board[i][j] = (char)knight++;
                } else if (board[i][j] == 'R') {
                    start_r = i;
                    start_c = j;
                }
            }
        }

        Queue<List<Integer>> q = new LinkedList<List<Integer>>();
        Set<List<Integer>> closed = new HashSet<List<Integer>>();
        q.add(List.of((1 << 9) - 1, start_r, start_c));
        while (!q.isEmpty()) {
            List<Integer> cur = q.poll();
            if (closed.contains(cur)) {
                continue;
            }
            int MASK = cur.get(0);
            int i = cur.get(1);
            int j = cur.get(2);
            if (i < 0 || i >= r || j < 0 || j >= c) {
                continue;
            }



            if (board[i][j] == 'T') {
                System.out.println("yes");
                return;
            }


        }
        System.out.println("no");
    }
}
