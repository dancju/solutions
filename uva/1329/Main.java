import static java.lang.System.out;

import java.util.Scanner;

public class Main {
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        short nCase = in.nextShort();
        while ((nCase--) != 0) {
            short n = in.nextShort();
            short[] pare = new short[n];
            for (short i = 0; i < n; i++)
                pare[i] = i;
            int[] dist = new int[n];
            char operator;
            while ((operator=in.next().charAt(0)) != 'O') {
                if (operator=='I') {
                    short u = (short)(in.nextShort()-1), v = (short)(in.nextShort()-1);
                    pare[u] = v;
                    dist[u] = Math.abs(u-v)%1000;
                }
                else {
                    short u = (short)(in.nextShort()-1);
                    while (pare[pare[u]] != pare[u]) {
                        dist[u] = dist[u]+dist[pare[u]];
                        pare[u] = pare[pare[u]];
                    }
                    out.println(dist[u]);
                }
            }
        }
        in.close();
    }

}
