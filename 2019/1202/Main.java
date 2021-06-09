import java.io.*;
import java.util.*;
import java.math.*;

public class Main { 
	public static BigInteger[][] dp = new BigInteger[108][];
	public static int n, x, tot = 0;
	public static int[] c = new int[108];
	public static Scanner cin = new Scanner(System.in);
	public static BigInteger pp = BigInteger.ONE;
	public static Boolean legal(int a, int s)
	{
		return 2 * (tot - s) > (2 * n - a) * x;
	}
	 
	public static BigInteger f(int k)
	{
		BigInteger ret = BigInteger.ZERO;
		for (int i = 0; i <= k - 1; ++i) {
			ret = ret.add(BigInteger.valueOf(x * (2 * n - i)).multiply(pp).divide(BigInteger.valueOf(2 * (n - i))));
		}
		return ret;
	}

	public static void main(String[] args) {
		for (int i = 1; i <= 108; ++i)
			pp = pp.multiply(BigInteger.valueOf(2 * i));
		n = cin.nextInt();
		x = cin.nextInt();
		tot = 0;
		for (int i = 1; i <= n; ++i) {
			c[i] = cin.nextInt();
			tot += c[i];
		}
		for (int i = 0; i < 108; ++i) {
			dp[i] = new BigInteger[10008];
			for (int j = 0; j <= 10000; ++j)
				dp[i][j] = BigInteger.ZERO;
		}
		dp[0][0] = BigInteger.ONE;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = i - 1; j >= 0; --j)
			{
				for (int s = tot - c[i]; s >= 0; --s)
				{
					if ((dp[j][s].compareTo(BigInteger.ONE)) >= 0 && legal(j, s)) {
						dp[j + 1][s + c[i]] = dp[j + 1][s + c[i]].add(dp[j][s]);
					}
				}
			}
		}
		BigInteger cnt = BigInteger.ZERO;
		BigInteger ans = BigInteger.ZERO;
		for (int i = 0; i <= n; ++i)
		{
			for (int s = 0; s <= tot; ++s)
			{
				if ((dp[i][s].compareTo(BigInteger.ONE)) >= 0 && !legal(i, s))
				{
					cnt = cnt.add(dp[i][s]);
					ans = ans.add((f(i).add(BigInteger.valueOf(tot - s).multiply(pp))).multiply((dp[i][s])));
				}
			}
		}
		System.out.println((new BigDecimal(ans).divide(new BigDecimal(cnt.multiply(pp)), 50, BigDecimal.ROUND_HALF_UP)).toPlainString());
	}
}