import static java.lang.System.out;

import java.util.Scanner;

public class Main {

    private static Scanner in = new Scanner(System.in);

    public static void main(String[] args) {
        int n;
        while ((n=in.nextInt()) != 0) {
            int m = in.nextInt();
            if (n < m) {
                int t = n;
                n = m;
                m = t;
            }
            out.println(2l*m*(m-1)*(3*n-m-1)/3 + (long)n*m*(m+n-2));
            //out.println((-2l*m*m+9l*m*n+3l*n*n-12*n+2)*m/3);
        }
    }

}
