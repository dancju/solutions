import static java.lang.System.out;

import java.util.ArrayList;
import java.util.BitSet;
import java.util.Scanner;

public class Main {

    private static boolean win(short[] sg, char[] s) {
        for (int i = 0; i+2 < s.length; i++)
            if (s[i] == 'X' && s[i+1]=='X' && s[i+2]=='X')
                return false;
        short result = 0;
        for (int i = 0; i<s.length; ) {
            int j;
            for (j = i; j<s.length && s[j]=='.'; j++);
            int len = j-i;
            if (i != 0)
                len -= 2;
            if (j != s.length)
                len -= 2;
            if (len <= -3)
                return true;
            if (len > 0)
                result ^= sg[len];
            i = j+1;
        }
        return result!=0;
    }

    public static void main(String[] args) {
        short[] sg = new short[201];
        sg[1] = sg[2] = sg[3] = 1;
        for (int i = 4; i <= 200; i++) {
            BitSet t = new BitSet();
            t.set(sg[i-3]);
            t.set(sg[i-4]);
            for (int j = 0; 0 <= i-j-5; j++)
                t.set((sg[j]^sg[i-j-5]));
            sg[i] = (short)t.nextClearBit(0);
        }
        Scanner in = new Scanner(System.in);
        short nCase = Short.parseShort(in.next());
        while ((nCase--) != 0) {
            char[] s = in.next().toCharArray();
            if (win(sg, s)) {
                out.println("WINNING");
                ArrayList<Integer> result = new ArrayList<Integer>(s.length);
                for (int i = 0; i < s.length; i++)
                    if (s[i] == '.') {
                        s[i] = 'X';
                        if (!win(sg, s))
                            result.add(i+1);
                        s[i] = '.'; 
                    }
                out.print(result.get(0));
                for (int i = 1; i < result.size(); i++)
                    out.print(" "+result.get(i));
                out.println();
            }
            else
                out.print("LOSING\n\n");
        }
        in.close();
    }

}
