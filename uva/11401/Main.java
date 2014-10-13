import static java.lang.System.out;

import java.util.Scanner;

public class Main {

	private static Scanner in = new Scanner(System.in);

	public static void main(String[] args) {
	    long[] f = new long[1000001];
	    for (int i = 4; i <= 1000000; i++)
	        f[i] = f[i-1] + ((i-1l)*(i-2)/2-(i-1)/2)/2;
	    int n;
		while ((n=Integer.parseInt(in.next())) >= 3) {
			out.println(f[n]);
		}
	}
	
}