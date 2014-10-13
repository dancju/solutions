import static java.lang.System.out;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.Scanner;
import java.util.TreeMap;

public class Main {

  private static class Component implements Comparable<Component> {
    private int pric, qual;
    public Component(int pric, int qual) {
      this.pric = pric;
      this.qual = qual;
    }
    public int compareTo(Component that) { return this.qual-that.qual; }
  }

  private static int price(Collection<ArrayList<Component>> lType, int q) {
    int ans = 0;
    Component comp = new Component(0, q);
    for (ArrayList<Component> l : lType) {
      int i = Collections.binarySearch(l, comp);
      if (i < 0)
        i = -i-1;
      if (i==l.size())
        return Integer.MAX_VALUE;
      ans += l.get(i).pric;
    }
    return ans;
  }

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int nCase = in.nextInt();
    while ((nCase--) != 0) {
      int n = in.nextInt(), b = in.nextInt();
      TreeMap<String, ArrayList<Component>> m = new TreeMap<String, ArrayList<Component>>();
      while ((n--) != 0) {
        String type = in.next();
        in.next();
        Component comp = new Component(in.nextInt(), in.nextInt());
        ArrayList<Component> lCom;
        if (m.containsKey(type))
          lCom = m.get(type);
        else {
          lCom = new ArrayList<Component>();
          m.put(type, lCom);
        }
        lCom.add(comp);
      }
      Collection<ArrayList<Component>> lType = m.values();
      m = null;
      for (ArrayList<Component> i : lType) {
        Collections.sort(i);
        for (int j = i.size()-1; j > 0; j--)
          i.get(j-1).pric = Math.min(i.get(j-1).pric, i.get(j).pric);
      }
      int ans0 = 0, ans1 = 1000000000;
      while (ans1 > ans0+1) {
        int mid = (ans1+ans0)>>1;
        if (price(lType, mid)>b)
          ans1 = mid;
        else
          ans0 = mid;
      }
      out.println(ans0);
    }
    in.close();
  }

}
