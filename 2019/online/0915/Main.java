import java.io.*;
import java.util.*;
import java.math.*;

class Main {
	public static Scanner cin = new Scanner(System.in);
	public static BigInteger[] fac = new BigInteger[30];
	public static BigInteger[][] pow = new BigInteger[30][30];
	public static BigInteger[][] val = new BigInteger[30][30];
	public static BigInteger[] Bell = new BigInteger[30];
	public static BigInteger C(int n, int m) {
		return fac[n].divide(fac[m]).divide(fac[n - m]);
	}
	public static BigInteger get(int i, int t) {
		if(val[i][t].compareTo(BigInteger.valueOf(-1)) != 0) return val[i][t];
		BigInteger tmp = BigInteger.ZERO;
		for(int kk = 0; kk <= i; ++kk) {
			tmp = tmp.add(C(i, kk).multiply(pow[t][kk]).multiply(Bell[i - kk]));
		}
		val[i][t] = tmp;
		return tmp;
	}
	public static void main(String[] args) {
		fac[0] = fac[1] = BigInteger.ONE;
		for(int i = 2; i <= 26; ++i) {
			fac[i] = fac[i - 1].multiply(BigInteger.valueOf(i));
		}
		for(int i = 1; i <= 26; ++i) {
			pow[i][0] = BigInteger.ONE;
			for(int j = 1; j <= 26; ++j) {
				pow[i][j] = pow[i][j - 1].multiply(BigInteger.valueOf(i));
			}
		}
		Bell[0] = Bell[1] = BigInteger.ONE;
		for(int i = 2; i <= 26; ++i) {
			Bell[i] = BigInteger.ZERO;
			for(int j = 0; j <= i - 1; ++j)
				Bell[i] = Bell[i].add(C(i - 1, j).multiply(Bell[j]));
		}
		for(int i = 0; i <= 26; ++i) {
			for(int j = 0; j <= 26; ++j)
				val[i][j] = BigInteger.valueOf(-1);
		}
		int T = cin.nextInt(), cas = 0, n, mx;
		BigInteger k;
		while(T-- != 0) {
			n = cin.nextInt();
			k = cin.nextBigInteger();
			String ans = new String();
			ans += 'A'; mx = 1;
			for(int i = 2; i <= n; ++i) {
				for(int j = 1; j <= mx + 1; ++j) {
					int t = mx; if(j > mx) t = j;
					BigInteger tmp = get(n - i, t);
					if(k.compareTo(tmp) > 0) {
						k = k.subtract(tmp);
					}
					else {
						ans += (char)('A' - 1 + j);
						if(j == mx + 1) mx = j;
						break;
					}
				}
			}
			System.out.println("Case #" + (++cas) + ": " + ans);
		}
	}
}