import static java.lang.System.out;

import java.util.Scanner;

public class Main {

    private static Scanner in = new Scanner(System.in);

    private static int MOD = 1000007;

    public static void main(String[] args) {
        int[][] pascal = new int[401][401];
        for (int i = 0; i <= 400; i++) {
            pascal[i][0] = pascal[i][i] = 1;
            for (int j = 1; j < i; j++)
                pascal[i][j] = (pascal[i-1][j-1]+pascal[i-1][j])%MOD;
        }
        int nCase = in.nextInt();
        for (int iCase = 1; iCase <= nCase; iCase++) {
            int m = in.nextInt(), n = in.nextInt(), k = in.nextInt();
            int ans = 0;
            ans += pascal[m*n][k];
            ans -= 2*pascal[(m-1)*n][k];
            ans = (ans+MOD)%MOD;
            ans -= 2*pascal[m*(n-1)][k];
            ans = (ans+MOD)%MOD;
            ans += pascal[(m-2)*n][k];
            ans = (ans+MOD)%MOD;
            ans += pascal[m*(n-2)][k];
            ans = (ans+MOD)%MOD;
            ans += 4*pascal[(m-1)*(n-1)][k];
            ans = (ans+MOD)%MOD;
            ans -= 2*pascal[(m-2)*(n-1)][k];
            ans = (ans+MOD)%MOD;
            ans -= 2*pascal[(m-1)*(n-2)][k];
            ans = (ans+MOD)%MOD;
            ans += pascal[(m-2)*(n-2)][k];
            ans = (ans+MOD)%MOD;
            out.printf("Case %d: %d\n", iCase, ans);
        }
    }

}