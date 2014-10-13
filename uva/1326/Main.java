import static java.lang.System.out;

import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

public class Main {

    private static Scanner in;

    private static int bitcount(int x) { return x==0 ? 0 : bitcount(x>>1)+(x&1); }
	
    public static void main(String[] args) {
        in = new Scanner(System.in);
        while (in.hasNext()) {
            int[] l = new int[in.nextInt()];
            for (int i = 0; i < l.length; i++) {
                String s = in.next();
                for (int j = 0; j < s.length(); j++)
                    l[i] |= 1<<(s.charAt(j)-'A');
            }
            Map<Integer, Integer> map = new TreeMap<Integer, Integer>();
            int n1 = (l.length>>1), n2 = l.length-n1;
            for (int i = 0; i < (1<<n1); i++) {
                int x = 0;
                for (int j = 0; j < n1; j++)
                    if ((i&(1<<j))!=0)
                        x ^= l[j];
                if (!map.containsKey(x) || bitcount(map.get(x))<bitcount(i))
                    map.put(x, i);
            }
            int ans = 0;
            for (int i = 0; i < (1<<n2); i++) {
                int x= 0;
                for (int j = 0; j < n2; j++)
                    if ((i&(1<<j))!=0)
                        x ^= l[n1+j];
                if (map.containsKey(x) && bitcount(ans)<bitcount(map.get(x))+bitcount(i))
                    ans = (i<<n1)^map.get(x);
            }
            out.println(bitcount(ans));
            for (int i = 0; i < l.length; i++)
                if ((ans&(1<<i))!=0)
                    out.print(i+1+" ");
            out.println();
        }
        in.close();
    }

}
