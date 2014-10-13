import static java.lang.System.out;

import java.util.Arrays;
import java.util.Scanner;

public class Main {

    private static class Song implements Comparable<Song> {
        int iden, leng;
        double freq;
        public Song(int iden, int leng, double freq) {
            this.iden = iden;
            this.leng = leng;
            this.freq = freq;
        }
        public int compareTo(Song that) {
            if (this.freq*that.leng-that.freq*this.leng < 0)
                return 1;
            if (this.freq*that.leng-that.freq*this.leng > 0)
                return -1;
            return 0;
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNext()) {
            Song[] l = new Song[in.nextInt()];
            for (int i = 0; i < l.length; i++)
                l[i] = new Song(in.nextInt(), in.nextInt(), in.nextDouble());
            Arrays.sort(l);
            out.println(l[in.nextInt()-1].iden);
        }
        in.close();
    }

}
