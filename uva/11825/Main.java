import static java.lang.System.out;

import java.util.Scanner;

public class Main {

    private static Scanner in;
    private static int n;
    private static int[] a, cover;
    private static Integer[] f;

    private static int f(int i) {
        if (f[i] == null) {
            f[i]= 0;
            for (int j = i; j != 0; j = i&(j-1))
                if (cover[j] == (1<<n)-1)
                    f[i] = Math.max(f[i], f(i^j)+1);
        }
        return f[i];
    }

    public static void main(String[] args) {
        in = new Scanner(System.in);
        int iCase = 0;
        while ((n=in.nextInt()) != 0) {
            a = new int[n];
            f = new Integer[1<<n];
            cover = new int[1<<n];
            for (int i = 0; i < n; i++) {
                a[i] = 1<<i; 
                int t = in.nextInt();
                for (int j = 0; j < t; j++)
                    a[i] |= 1<<in.nextInt();
            }
            for (int i = 0; i < (1<<n); i++)
                for (int j = 0; j < n; j++)
                    if (((1<<j)&i) == 0)
                        cover[(1<<j)^i] = cover[i] | a[j];
            out.printf("Case %d: %d\n", ++iCase, f((1<<n)-1));
        }
        in.close();
    }

}
