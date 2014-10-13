import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int nCase = cin.nextInt();
        for (int iCase = 1; iCase <= nCase; iCase++) {
            int n = cin.nextInt();
            int[] p = new int[cin.nextInt()], q = new int[cin.nextInt()], f = new int[n*n+1];
            cin.next();
            for (int i = 0; i < p.length; i++)
                f[cin.nextInt()] = i+1;
            cin.next();
            for (int i = 0; i < q.length; i++)
                q[i] = f[cin.nextInt()];
            List<Integer> s = new ArrayList<Integer>();
            for (int i : q) {
                if (i == 0)
                    continue;
                if (s.isEmpty() || i>s.get(s.size()-1))
                    s.add(i);
                else {
                    int t = Collections.binarySearch(s, i);
                    if (t < 0)
                        s.set(-t-1, i);
                }
            }
            System.out.printf("Case %d: %d\n", iCase, s.size()+1);
        }
        cin.close();
    }

}
