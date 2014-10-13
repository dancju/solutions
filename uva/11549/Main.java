import java.util.Scanner;

public class Main {

    private static int next(int n, int k) {
        String t = String.valueOf((long)k * k);
        if (t.length() > n)
            t = t.substring(0, n);
        return Integer.parseInt(t);
    }

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int nCase = cin.nextInt();
        while ((nCase--) != 0) {
            int n = cin.nextInt(), k = cin.nextInt();
            int ans = k, t0 = k, t1 = k;
            do {
                t0 = next(n, t0);
                t1 = next(n, t1);
                ans = Math.max(ans,  t1);
                t1 = next(n, t1);
                ans = Math.max(ans,  t1);
            } while (t0 != t1);
            System.out.println(ans);
        }
        cin.close();
    }

}
