import static java.lang.System.out;

import java.util.Scanner;

public class Main {

    private static long sg(long x) { return (x&1)==0 ? x>>1 : sg(x>>1); }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        short nCase = in.nextShort();
        while ((nCase--) != 0) {
            short n = in.nextShort();
            long result = 0;
            while ((n--) != 0)
                result ^= sg(in.nextLong());
            out.println(result==0 ? "NO" : "YES");
        }
        in.close();
    }

}