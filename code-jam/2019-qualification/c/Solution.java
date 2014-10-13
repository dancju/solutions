import static java.lang.System.out;
import java.math.*;
import java.util.*;

public class Solution {

  static Scanner in = new Scanner(System.in);

  static BigInteger[] main2(int len) {
    BigInteger[] l0 = new BigInteger[len];
    BigInteger[] l1 = new BigInteger[len+1];
    for (int i = 0; i < len; i++)
      l0[i] = in.nextBigInteger();
    for (int i = 1; i < len; i++)
      if (!l0[i-1].equals(l0[i]))
        l1[i] = l0[i-1].gcd(l0[i]);
    for (int i = 1; i < len; i++)
      if (l1[i] != null && l1[i+1] == null)
        l1[i+1] = l0[i].divide(l1[i]);
    for (int i = len-1; i > 0; i--)
      if (l1[i-1] == null && l1[i] != null)
        l1[i-1] = l0[i-1].divide(l1[i]);
    return l1;
  }

  static Map<BigInteger, Character> main3(BigInteger[] l1) {
    Set<BigInteger> s2 = new TreeSet<BigInteger>(Arrays.asList(l1));
    assert s2.size() == 26;
    Map<BigInteger, Character> m3 = new TreeMap<BigInteger, Character>();
    Iterator<BigInteger> i = s2.iterator();
    char j = 'A';
    for (; i.hasNext(); j++)
      m3.put(i.next(), j);
    return m3;
  }

  static void main1() {
    in.next();
    int len = in.nextInt();
    BigInteger[] l1 = main2(len);
    Map<BigInteger, Character> m3 = main3(l1);
    for (BigInteger i : l1)
      out.print(m3.get(i));
  }

  public static void main(String[] args) {
    int nCase = in.nextInt();
    for (int iCase = 1; iCase <= nCase; iCase++) {
      out.printf("Case #%d: ", iCase);
      main1();
      out.println();
    }
  }

}
