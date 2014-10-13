import static java.lang.System.out;

import java.util.Scanner;

class DisjointSet {

    private int n;
    private int[] parent, rank;

    public DisjointSet(int n) {
        this.n = n;
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    public int find(int i) {
        if (i>=n)
            throw new IllegalArgumentException();
        return parent[i]==i ? i : (parent[i]=find(parent[i]));
    }

    public void union(int a, int b) {
        if (a>=n || b>=n)
            throw new IllegalArgumentException();
        a = find(a);
        b = find(b);
        if (a==b)
            return;
        if (rank[a] < rank[b]) {
            int t = a;
            a = b;
            b = t;
        }
        rank[a] += rank[b];
        rank[b] = 0;
        parent[b] = a;
    }

    public boolean connected(int a, int b) {
        if (a>=n || b>=n)
            throw new IllegalArgumentException();
        return find(a)==find(b);
    }
	
}

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNext()) {
            DisjointSet ds = new DisjointSet(100001);
            int result = 0, a;
            while ((a=in.nextInt()) != -1) {
                int b = in.nextInt();
                if (ds.connected(a, b))
                    result++;
                ds.union(a, b);
            }
            out.println(result);
        }
        in.close();
    }

}
