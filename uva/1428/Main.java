import static java.lang.System.out;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        short nCase = in.nextShort();
        while ((nCase--) != 0) {
            short n = in.nextShort();
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = in.nextInt();
            int[] c = new int[n];
            FenwickTree f = new FenwickTree(100000); 
            for (int i = 0; i < n; i++) {
                f.modify(a[i], 1);
                c[i] = (int) f.sum(a[i]-1);
            }
            int[] d = new int[n];
            f = new FenwickTree(100000);
            for (int i = n-1; i>=0; i--) {
                f.modify(a[i], 1);
                d[i] = (int) f.sum(a[i]-1);
            }
            long result = 0;
            for (int i = 0; i < n; i++) {
                result += c[i]*(n-i-1-d[i]);
                result += (i-c[i])*d[i];
            }
            out.println(result);
        }
        in.close();
    }

}

class FenwickTree {

    private static int lowbit(int x) { return x&-x; }

    private final int n;
    private final long[] f;

    /**
     * 建立一個長度爲 n 的數組 f[] , 下標爲 1 至 n .
     * @param n
     */
    public FenwickTree(int n) {
        this.n = n;
        f = new long[n+1];
    }

    /**
     * 把 f[x] 的值增加 delta.
     * @param x
     * @param delta
     */
    public void modify(int x, long delta) {
        if (x<1 || x>n)
            throw new IllegalArgumentException();
        while (x <= n) {
            f[x] += delta;
            x += lowbit(x);
        }
    }

    /**
     * 詢問 f[1] 至 f[x] 共 x 個元素之和.
     * @param x
     * @return 0 若 x 爲 0, 否則 f[1] 至 f[x] 共 x 個元素之和.
     */
    public long sum(int x) {
        if (x<0 || x>n)
            throw new IllegalArgumentException();
        long result = 0;
        while (x > 0) {
            result += f[x];
            x -= lowbit(x);
        }
        return result;
    }
    
    /**
     * 詢問 f[from] 至 f[to] 共 from-to+1 元素的和.
     * @param from
     * @param to
     * @return
     */
    public long sum(int from, int to) {
        if (from<1 || from>to || to>n)
            throw new IllegalArgumentException();
        return sum(to)-sum(from-1);
    }

}
