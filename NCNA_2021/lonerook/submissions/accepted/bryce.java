import java.util.*;
import java.io.*;

public class bryce {
    static int r, c;
    static int n;
    static char[][] board;

    static int drK[] = {1, 2, 2, 1, -1, -2, -2, -1};
    static int dcK[] = {2, 1, -1, -2, -2, -1, 1, 2};

    static int dr[] = {0, 1, 0, -1};
    static int dc[] = {1, 0, -1, 0};

    public static boolean inRange(int i, int j) {
        return i >= 0 && i < r && j >= 0 && j < c;
    }

    public static boolean isDanger(int i, int j) {
        for (int k = 0; k < 8; ++k) {
            int i_new = i + drK[k];
            int j_new = j + dcK[k];

            if (inRange(i_new, j_new) && board[i_new][j_new] == 'K') {
                return true;
            }
        }

        return false;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        r = in.nextInt();
        c = in.nextInt();
        n = Math.max(r, c);
        board = new char[r][c];

        Queue<List<Integer>> q = new LinkedList<List<Integer>>();

        for (int i = 0; i < r; ++i) {
            String line = in.next();
            for (int j = 0; j < c; ++j) {
                board[i][j] = line.charAt(j);
                if (board[i][j] == 'R') {
                    q.add(List.of(i, j));
                }
            }
        }

        boolean[][] visited = new boolean[r][c];
        boolean[][] visitableDanger = new boolean[r][c];

        while (!q.isEmpty()) {
            List<Integer> cur = q.poll();
            int i = cur.get(0);
            int j = cur.get(1);

        //    System.out.println(i + " " + j);

            if (isDanger(i, j)) {
                visitableDanger[i][j] = true;
                continue;
            }

        //    System.out.println("past checks");

            if (board[i][j] == 'T') {
                System.out.println("yes");
                return;
            }

            if (board[i][j] == 'K') {
                board[i][j] = '.';

                for (int k = 0; k < 8; ++k) {
                    int i_new = i + drK[k];
                    int j_new = j + dcK[k];
                    
                    if (inRange(i_new, j_new) && visitableDanger[i_new][j_new]) {
                        //visited[i_new][j_new] = false;
                        q.add(List.of(i_new, j_new));

                        visitableDanger[i_new][j_new] = false;
                    }
                }
            }

            for (int k = 0; k < 4; ++k) {
                for (int l = 1; l < n; ++l) {
                    int i_new = i + dr[k]*l;
                    int j_new = j + dc[k]*l;

                    if (inRange(i_new, j_new) && !visited[i_new][j_new]) {
                        q.add(List.of(i_new, j_new));
                        visited[i_new][j_new] = true;
                    }

                    if (!inRange(i_new, j_new) || board[i_new][j_new] == 'K') {
                        break;
                    }
                }
            }
        }
        System.out.println("no");
    }
}
