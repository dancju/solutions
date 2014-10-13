import static java.lang.System.out;

import java.util.Scanner;

public class Main {

    private static Scanner in;
	
    public static void main(String[] args) {
        in = new Scanner(System.in);
        int n;
        while ((n = in.nextInt()) != 0) {
            int k = in.nextInt(), m = in.nextInt(), ans = 0;
            for (int i = 2; i <= n; i++)
                ans = (ans+k)%i;
            ans = (m-k+1+ans)%n;	
            if (ans <= 0)
                ans += n;
            out.println(ans);
        }
        in.close();
    }

}
