import static java.lang.System.out;

import java.util.Scanner;

public class Main {

    private static int bazinga(int[] pi, double x) {
        int ans = 0;
        for (int i : pi)
            ans += i/x;
        return ans;
    }
	
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int nCase = in.nextInt();
        while ((nCase--) != 0) {
            int[] pi = new int[in.nextInt()];
            int f = in.nextInt();
            for (int i = 0; i < pi.length; i++) {
                pi[i] = in.nextInt();
                pi[i] *= pi[i];
            }
            double ans0 = 0, ans1 = 1e8;
            while (ans1-ans0 > 1e-5) {
                double m = (ans0+ans1)/2;
                if (bazinga(pi, m) < f+1)
                    ans1 = m;
                else
                    ans0 = m;
            }
            ans0 *= Math.PI;
            out.printf("%.4f\n", ans0);
        }
        in.close();
    }

}
