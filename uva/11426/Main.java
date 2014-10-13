import static java.lang.System.out;

import java.util.Scanner;

public class Main {

    public static int[] phiList(int n) {
        int[] result = new int[n];
        result[1] = 1;
        for (int i = 2; i < n; i++)
            if (result[i] == 0)
                for (int j = i; j < n; j += i) {
                    if (result[j] == 0)
                        result[j]= j;
                    result[j] /= i;
                    result[j] *= i-1; 
                }
        return result;
    }

    public static void main(String[] args) {
        final int MAXN = 4000000;
        int[] phi = phiList(MAXN+1);
        long[] f = new long[MAXN+1];
        for (int i = 1; i <= MAXN; i++)
            for (int n = 2; i*n <= MAXN; n++)
                f[i*n] += i*phi[n];
        for (int i = 3; i <= MAXN; i++)
            f[i] += f[i-1]; 
        Scanner in = new Scanner(System.in);
        int n;
        while ((n=in.nextInt()) != 0)
            out.println(f[n]);
        in.close();
    }

}
