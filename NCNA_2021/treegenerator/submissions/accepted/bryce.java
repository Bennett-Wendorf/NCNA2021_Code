import java.util.*;
import java.io.*;

public class bryce {
    static int n, q;
    static long m;
    static List<Integer>[] tree;
    static long[] L, sumDown, digit;
    static int[][] P;
    static long[][] sumUp;

    static long powMod(long x, long k) {
        if (k == 0) return 1;
        else if (k % 2 == 1) return (x * powMod(x, k-1)) % m;
        else {
            long half = powMod(x, k/2);
            return (half * half) % m;
        }
    }

    static int log2(long x) {
        int j;
        for (j = 0; (1 << j) < x; ++j);
        return j;
    }

    static void get_dist() {
        Stack<Integer> s = new Stack<Integer>();
        s.push(0);
        sumDown[0] = digit[0];
        L[0] = 0;
        while (!s.empty()) {
            int cur = s.pop();
            for (int i = 0; i < tree[cur].size(); ++i) {
                int next = tree[cur].get(i);
                P[next][0] = cur;
                tree[next].remove(Integer.valueOf(cur));
                L[next] = L[cur]+1;
                sumDown[next] = (sumDown[cur] * 10 + digit[next]) % m;
                s.push(next);
            }
        }
    }

    static void preprocess() {
        for (int j = 1; (1 << j) < n; ++j) {
            for (int i = 0; i < n; ++i) {
                if (P[i][j-1] != -1) {
                    P[i][j] = P[P[i][j-1]][j-1];
                    sumUp[i][j] = (sumUp[i][j-1] * powMod(10, 1 << (j-1)) + sumUp[P[i][j-1]][j-1]) % m;
                }
            }
        }
    }

    static long calculateTotal(int a, int b, int lca, long totalSumUp, long totalSumDown) {
        return ((totalSumUp * powMod(10, L[b]-L[lca]+1))%m + totalSumDown) % m;
    }

    // calculates totalSumDown from c to descendant b, including lca
    static long calculateDown(int b, int lca) {
        if (lca == 0) {
            return sumDown[b];
        }
        lca = P[lca][0];
        return (sumDown[b] + m - (sumDown[lca] * powMod(10, L[b]-L[lca]))%m) % m;
    }

    static long getTotalSumUp(int jumpPower, long totalSumUp, int na) {
        return (totalSumUp * powMod(10, 1 << jumpPower) + sumUp[na][jumpPower]) % m;
    }

    static long LCAAns(int a, int b) {
        // totalSumUp does not include LCA(a,b)
        long totalSumUp = 0;
        int na = a;
        for (int i = log2(n)-1; i >= 0; --i) {
            if (P[na][i] != -1 && L[P[na][i]] >= L[b]) {
                totalSumUp = getTotalSumUp(i, totalSumUp, na);
                na = P[na][i];
            }
        }
        int nb = b;
        for (int i = log2(n)-1; i >= 0; --i) {
            if (P[nb][i] != -1 && L[P[nb][i]] >= L[na]) {
                nb = P[nb][i];
            }
        }

        if (na == nb) {
            return calculateTotal(a, b, na, totalSumUp, calculateDown(b, na));
        }

        for (int i = log2(n)-1; i >= 0; --i) {
            if (P[na][i] != P[nb][i]) {
                totalSumUp = getTotalSumUp(i, totalSumUp, na);
                na = P[na][i];
                nb = P[nb][i];
            }
        }
        totalSumUp = getTotalSumUp(0, totalSumUp, na);
        na = P[na][0];
        nb = P[nb][0];

        return calculateTotal(a, b, na, totalSumUp, calculateDown(b, na));
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        m = in.nextInt();
        q = in.nextInt();

        tree = new ArrayList[n];
        for (int i = 0; i < n; ++i) {
            tree[i] = new ArrayList<Integer>();
        }
        for (int i = 0; i < n-1; ++i) {
            int x = in.nextInt();
            int y = in.nextInt();
            --x;
            --y;
            tree[x].add(y);
            tree[y].add(x);
        }

        digit = new long[n];
        for (int i = 0; i < n; ++i) {
            digit[i] = in.nextInt();
        }

        P = new int[n][log2(n)];
        sumUp = new long[n][log2(n)];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < log2(n); ++j) {
                P[i][j] = -1;
                sumUp[i][j] = -1;
            }
        }
        for (int i = 0; i < n; ++i) {
            sumUp[i][0] = digit[i];
        }
        L = new long[n];
        sumDown = new long[n];

        get_dist();
        preprocess();

        for (int i = 0; i < q; ++i) {
            int a = in.nextInt();
            int b = in.nextInt();
            --a;
            --b;

            System.out.println(LCAAns(a, b));
        }
    }
}
