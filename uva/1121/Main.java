import static java.lang.System.out;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNext()) {
            int[] l = new int[in.nextInt()+1];
            int s = in.nextInt();
            for (int i = 1; i < l.length; i++) {
                l[i] = in.nextInt();
                l[i] += l[i-1];
            }
            int ans = Integer.MAX_VALUE;
            for (int i = 0, j = 1; j < l.length;) {
                if (l[j]-l[i] < s) {
                    j++;
                }
                else {
                    ans = Math.min(ans, j-i);
                    i++;
                }
            }
            out.println(ans==Integer.MAX_VALUE ? 0 : ans);
        }
        in.close();
    }

}
