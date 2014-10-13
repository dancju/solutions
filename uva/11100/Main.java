import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int n;
        while ((n = cin.nextInt())!=0) {
            int[] l = new int[n];
            for (int i = 0; i < n; i++)
                l[i] = cin.nextInt();
            Arrays.sort(l);
            int ans = 1;
            for (int cur = 1, i = 1; i < n; i++) {
                if (l[i] == l[i-1])
                    cur++;
                else
                    cur = 1;
                ans = Math.max(ans, cur);
            }
            System.out.println(ans);
            for (int i = 0; i < ans; i++) {
                System.out.print(l[i]);
                for (int j = i+ans; j < n; j += ans)
                    System.out.print(" "+l[j]);
                System.out.println();
            }
            System.out.println();
        }
        cin.close();
    }

}
