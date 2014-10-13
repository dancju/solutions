import static java.lang.System.out;

import java.util.BitSet;
import java.util.Scanner;

public class Main {

    private static int[] prime = primeList(1000000);
    private static Double[] f = new Double[1000001];

    private static BitSet primeSet(int n) {
        BitSet ans = new BitSet();
        ans.set(2, n);
        int m = (int) Math.sqrt(n + 0.5);
        for (int i = 2; i <= m; i++)
            if (ans.get(i))
                for (int j = i * i; j < n; j += i)
                    ans.clear(j);
        return ans;
    }

    private static int[] primeList(int n) {
        BitSet set = primeSet(n);
        int[] ans = new int[set.cardinality()];
        int top = 0;
        for (int i = 2; i < n; i++)
            if (set.get(i))
                ans[top++] = i;
        return ans;
    }

    private static double f(int n) {
        if (f[n] != null)
            return f[n];
        f[n] = 0.;
        int g = 0, p = 0;
        for (p = 0; p < prime.length && prime[p] <= n; p++)
            if (n % prime[p] == 0) {
                g++;
                f[n] += f(n / prime[p]);
            }
        f[n] += p;
        f[n] /= g;
        return f[n];
    }

    public static void main(String[] args) throws IOException {
        f[1] = 0.;
        Scanner in = new Scanner(System.in);
        int nCase = in.nextInt();
        for (int iCase = 1; iCase <= nCase; iCase++)
            out.printf("Case %d: %.10f\n", iCase, f(in.nextInt()));
        in.close();
    }

}
