import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        MyScanner in = new MyScanner(System.in);
        for (int iCase = 1; in.hasNext(); iCase++) {
            String s = in.next();
            short n = in.nextShort();
            Trie trie = new Trie();
            while ((n--) != 0)
                trie.put(in.next());
            int[] f = new int[s.length()+1];
            f[s.length()] = 1;
            for (int i = s.length()-1; i>=0; i--) {
                trie.get(s, f, i);
            }
            System.out.printf("Case %d: %d\n", iCase, f[0]);
        }
    }

}

class Trie {

    private static class Node {
        boolean val = false;
        Node[] next = new Node[RADIX];
    }

    private static final int RADIX = 26, MOD = 20071027;

    private Node root;

    private static int c2i(char c) { return c-'a'; }

    public void clear() { root = null; }

    public void get(String key, int[] f, int pos) {
        get(root, key, f, pos, 0);
    }

    private void get(Node x, String key, int[] f, int pos, int dep) {
        if (x == null)
            return;
        if (x.val) {
            f[pos] += f[pos+dep];
            f[pos] %= MOD;
        }
        if (key.length() != pos+dep)
            get(x.next[c2i(key.charAt(pos+dep))], key, f, pos, dep+1);
    }

    public void put(String key) { root = put(root, key, 0); }

    private Node put(Node x, String key, int d) {
        if (x == null)
            x = new Node();
        if (d == key.length()) {
            x.val = true;
            return x;
        }
        int c = c2i(key.charAt(d));
        x.next[c] = put(x.next[c], key, d+1);
        return x;
    }

}


class MyScanner {

    private BufferedReader reader;
    private StringTokenizer tokenizer;

    public MyScanner(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
        tokenizer = new StringTokenizer("");
    }

    public MyScanner(File source) throws FileNotFoundException {
        this(new FileInputStream(source));
    }
    
    public boolean hasNext() throws IOException {
        return tokenizer.hasMoreTokens() || reader.ready();
    }

    public String next() throws IOException {
        while (!tokenizer.hasMoreTokens())
            tokenizer = new StringTokenizer(reader.readLine());
        return tokenizer.nextToken();
    }

    public double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    public int nextInt() throws IOException { return Integer.parseInt(next()); }
    
    public short nextShort() throws IOException {
        return Short.parseShort(next());
    }

}