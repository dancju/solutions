import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {

    private static class Rock {
        private int xMin, xMax, yMin, yMax, x, y;
        public Rock(int xMin, int yMin, int xMax, int yMax) {
            this.xMin = xMin;
            this.yMin = yMin;
            this.xMax = xMax;
            this.yMax = yMax;
        }
    }

    private static Rock[] lRock;

    private static boolean greedyX() {
        PriorityQueue<Rock> q = new PriorityQueue<Rock>(lRock.length, new Comparator<Rock>() {
                public int compare(Rock a, Rock b) { return a.xMin!=b.xMin ? a.xMin-b.xMin : a.xMax-b.xMax; }});
        for (Rock r : lRock)
            q.add(r);
        int t = 0;
        while (!q.isEmpty()) {
            Rock rock = q.remove();
            if (t == rock.xMin) {
                rock.x = t;
                t++;
            }
            else if (t > rock.xMin) {
                if (rock.xMax<t)
                    return false;
                rock.xMin = t;
                q.add(rock);
            }
            else
                return false;
        }
        return true;
    }	

    private static boolean greedyY() {
        PriorityQueue<Rock> q = new PriorityQueue<Rock>(lRock.length, new Comparator<Rock>() {
                public int compare(Rock a, Rock b) { return a.yMin!=b.yMin ? a.yMin-b.yMin : a.yMax-b.yMax; }});
        for (Rock r : lRock)
            q.add(r);
        int t = 0;
        while (!q.isEmpty()) {
            Rock rock = q.remove();
            if (t == rock.yMin) {
                rock.y = t;
                t++;
            }
            else if (t > rock.yMin) {
                if (rock.yMax < t)
                    return false;
                rock.yMin = t;
                q.add(rock);
            }
            else
                return false;
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int n;
        while ((n = cin.nextInt())!=0) {
            lRock = new Rock[n];
            for (int i = 0; i < n; i++)
                lRock[i] = new Rock(cin.nextInt()-1, cin.nextInt()-1, cin.nextInt()-1, cin.nextInt()-1);
            if (greedyX() && greedyY())
                for (Rock r : lRock)
                    System.out.println(r.x+1+" "+(r.y+1));
            else
                System.out.println("IMPOSSIBLE");
        }
        cin.close();
    }

}
