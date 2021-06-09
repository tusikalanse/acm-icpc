import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	static int n;
	static BigInteger m;
	static BigInteger[] a = new BigInteger[110], r = new BigInteger[110];
	static BigInteger[] exgcd(BigInteger a, BigInteger b) {
		BigInteger[] res = new BigInteger[3];
		if(b.equals(BigInteger.ZERO)) {
			res[0] = a;
			res[1] = BigInteger.ONE;
			res[2] = BigInteger.ZERO;
			return res;
		}
		BigInteger[] tmp = exgcd(b, a.mod(b));
		res[0] = tmp[0];
		res[1] = tmp[2];
		res[2] = tmp[1].subtract(a.divide(b).multiply(tmp[2]));
		return res;
	}
	static BigInteger excrt() {
		BigInteger M = a[1], R = r[1], x, y, d;
		for(int i = 2; i <= n; ++i) {
			BigInteger[] rrr = exgcd(M, a[i]);
			d = rrr[0]; x = rrr[1]; y = rrr[2];
			if(!(R.subtract(r[i]).mod(d)).equals(BigInteger.ZERO)) return BigInteger.valueOf(-1);
			x = (R.subtract(r[i]).divide(d).multiply(x)).mod(a[i]);
			R = R.subtract(M.multiply(x));
			M = M.divide(d).multiply(a[i]);
			R = R.mod(M);
		}
		return R.mod(M).add(M).mod(M);
	}
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		n = cin.nextInt();
		m = cin.nextBigInteger();
		for(int i = 1; i <= n; ++i) {
			a[i] = cin.nextBigInteger();
			r[i] = cin.nextBigInteger();
		}
		BigInteger res = excrt();
		if(res.equals(BigInteger.valueOf(-1))) {
			System.out.println("he was definitely lying");
		}
		else if(res.compareTo(m) > 0) {
			System.out.println("he was probably lying");
		}
		else {
			System.out.println(res);
		}
	}
}