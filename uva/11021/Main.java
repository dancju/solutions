import static java.lang.System.out;

import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
        //Scanner in = new Scanner(new File("input.txt"));
        int nCase = in.nextInt();
        for (int iCase = 1; iCase <= nCase; iCase++) {
            int n = in.nextInt(), k = in.nextInt(), m = in.nextInt();
            double[] p = new double[n];
            double[] f = new double[m+1];
            for (int i = 0; i < n; i++)
                p[i] = in.nextDouble();
            for (int i = 1; i <= m; i++)
                for (int j = 0; j < n; j++)
                    f[i] += p[j]*Math.pow(f[i-1], j);
            out.printf("Case #%d: %.7f\n", iCase, Math.pow(f[m], k));
        }
        in.close();
    }

}