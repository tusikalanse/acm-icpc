#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int mod = 998244353;
int n, m, k;
LL dp[2][108];
LL inv[208], fac[208], invfac[208];
int a[108][2];
LL qp(LL a, int b)
{
	LL ret = 1;
	while (b)
	{
		if (b & 1)
			ret = ret * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ret;
}

LL C(int n, int m)
{
	//cout << "n = " << n << "   m = " << m << endl;
	if (n < m || n < 0 || m < 0)
		return 0;
	return fac[n] * invfac[n - m] % mod * invfac[m] % mod;
}
void gao()
{
	inv[1] = 1; fac[0] = fac[1] = 1; invfac[0] = invfac[1] = 1;
	for (LL i = 2; i <= 200; ++i)
	{
		inv[i] = qp(i, mod - 2);
		fac[i] = fac[i - 1] * i % mod;
		invfac[i] = invfac[i - 1] * inv[i] % mod;
	}
}

int main()
{
	gao();
	int T;
	scanf("%d", &T);
	while (T--)
	{
		memset(dp, 0, sizeof(dp));
		scanf("%d %d %d", &n, &k, &m);
		int p = 0;
		for (int i = 1; i <= n; ++i)
		{
			scanf("%1d", &a[i][0]);
		}
		for (int i = 1; i <= n; ++i)
		{
			scanf("%1d", &a[i][1]);
			p += (a[i][1] != a[i][0]);
		}
		dp[0][p] = 1;
		int c = 1;
		for (int i = 1; i <= k; ++i)
		{
			for (int j = 0; j <= n; ++j)
			{
				dp[c][j] = 0;
				int stp = max(0, j - m);
				if ((stp + m - j) % 2)
					stp++;
				//cout << "i = " << i << "  j = " << j << endl;
				for (int p = stp; p <= min(n, j + m); p += 2)
				{
					//cout << "p = " << p << 
					//"  contri = " << dp[c^1][p] * C(p, (p + m - j) / 2) % mod * C(n - p, (m - p + j) / 2) % mod << endl;
					dp[c][j] += dp[c^1][p] * C(p, (p + m - j) / 2) % mod * C(n - p, (m - p + j) / 2) % mod;
					dp[c][j] %= mod;
				}
				//printf("dp[%d][%d] = %lld\n\n", i, j, dp[c][j]);
			}
			c ^= 1;
		}
		printf("%lld\n", dp[c^1][0]);
	}
}