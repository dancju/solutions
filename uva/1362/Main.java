import static java.lang.System.out;

import java.util.Scanner;

public class Main {

    private static Scanner in = new Scanner(System.in);

    private static final int MOD = 1000000000;
    private static String s;
    private static Integer[][] f;
    
    private static int f(int from, int to) {
        if (f[from][to] == null) {
            if (from == to)
                f[from][to] = 1;
            else if (s.charAt(from) != s.charAt(to))
                f[from][to] = 0;
            else {
                f[from][to] = 0;
                for (int k = from+2; k <= to; k += 2)
                    if (s.charAt(from) == s.charAt(k))
                        f[from][to] = (int) ((f[from][to]+(long)f(from+1, k-1)*f(k, to))%MOD);
            }
        }
        return f[from][to];
    }
    
    public static void main(String[] args) {
        while (in.hasNext()) {
            s = in.next();
            f = new Integer[s.length()][s.length()];
            out.println(f(0, s.length()-1));
        }
    }

}