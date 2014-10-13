import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int nCase = cin.nextInt();
        while ((nCase--) != 0) {
            int x = cin.nextInt(), y = cin.nextInt(), z = cin.nextInt(); 
            long[][][] s1 = new long[x+1][y+1][z+1];
            for (int i = 1; i <= x; i++)
                for (int j = 1; j <= y; j++) {
                    long t = 0;
                    for (int k = 1; k <= z ; k++) {
                        t += cin.nextLong();
                        s1[i][j][k] = s1[i][j-1][k]+t;
                    }
                }
            long ans = Long.MIN_VALUE;
            for (int j0 = 1; j0 <= y; j0++)
                for (int k0 = 1; k0 <= z; k0++)
                    for (int j1 = 0; j1 < j0; j1++)
                        for (int k1 = 0; k1 < k0; k1++) {
                            long t = 0;
                            for (int i = 1; i <= x; i++) {
                                t = Math.max(t, 0l)+s1[i][j0][k0]-s1[i][j1][k0]-s1[i][j0][k1]+s1[i][j1][k1];
                                ans = Math.max(ans, t);
                            }
                        }
            System.out.println(ans);
            if (nCase != 0)
                System.out.println();
        }
        cin.close();
    }

}
