import static java.lang.System.out;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        in.useDelimiter("(\\s|/)+");
        short nCase = in.nextShort();
        for (short iCase = 1; iCase <= nCase; iCase++) {
            short nume = in.nextShort(), demo = in.nextShort(), n = in.nextShort();
            double p = (double)nume/demo;
            double[] f0, f1 = {1};
            for (int i = 1; i <= n; i++) {
                f0 = f1;
                f1 = new double[2+(int)(p*i)];
                f1[0] = f0[0]*(1-p);
                for (int j = 1; j*demo<=nume*i; j++)
                    f1[j] = f0[j]*(1-p)+f0[j-1]*p;
            }
            double result = 0;
            for (int j = 0; j*demo<=nume*n; j++)
                result += f1[j];
            out.printf("Case #%d: %d\n", iCase, (int)(1/result));
        }
        in.close();
    }

}
