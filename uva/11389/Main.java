import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int n;
        while ((n = cin.nextInt())!=0) {
            int d = cin.nextInt(), r = cin.nextInt();
            int[] a = new int[n], b = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = cin.nextInt();
            for (int i = 0; i < n; i++)
                b[i] = cin.nextInt();
            Arrays.sort(a);
            Arrays.sort(b);
            int ans = 0;
            for (int i = 0; i < n; i++) {
                int t = a[i]+b[n-1-i];
                if (t > d)
                    ans += (t-d)*r;
            }
            System.out.println(ans);
        }
        cin.close();
    }

}
