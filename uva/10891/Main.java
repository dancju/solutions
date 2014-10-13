import static java.lang.Math.max;
import static java.lang.System.out;

import java.util.Scanner;

public class Main {

    private static Scanner in;
    public static void main(String[] args) {
        in = new Scanner(System.in);
        int n;
        while ((n=in.nextInt()) != 0) {
            int[] s = new int[n+1];
            for (int i = 1; i <= n; i++)
                s[i] = in.nextInt()+s[i-1];
            int[][] f = new int[n+1][n+1];
            for (int len = 0; len < n; len++)
                for (int i = 1; i+len <= n; i++) {
                    int j = i+len;
                    f[i][j] = s[j]-s[i-1];
                    for (int k = i+1; k <= j; k++)
                        f[i][j] = max(f[i][j], s[j]-s[i-1]-f[k][j]);
                    for (int k = i; k <= j-1; k++)
                        f[i][j] = max(f[i][j], s[j]-s[i-1]-f[i][k]);
                }
            out.println(2*f[1][n]-s[n]);
        }
        in.close();
    }

}
