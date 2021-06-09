import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	static int n;
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
		R = R.mod(M).add(M).mod(M);
		if(R.equals(BigInteger.ZERO))
			R = R.add(M);
		return R;
	}
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		BigInteger e15 = new BigInteger("1000000000000000");
		BigInteger[] fib = new BigInteger[74];
		fib[0] = BigInteger.ZERO;
		fib[1] = BigInteger.ONE;
		for(int i = 2; i < 74; ++i)
			fib[i] = fib[i - 1].add(fib[i - 2]);
		n = cin.nextInt();
		for(int i = 1; i <= n; ++i) {
			a[i] = cin.nextBigInteger();
			r[i] = cin.nextBigInteger();
		}
		BigInteger res = excrt();
		if(res.equals(BigInteger.valueOf(-1)) || res.compareTo(e15) > 1) {
			System.out.println("Tankernb!");
		}
		else {
			boolean find = false;
			for(int i = 0; i < 74; ++i) {
				if(fib[i].equals(res))
					find = true;
			}
			if(find)
				System.out.println("Lbnb!");
			else
				System.out.println("Zgxnb!");
		}
	}
}