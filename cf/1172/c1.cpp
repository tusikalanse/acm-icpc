#include <bits/stdc++.h>
using namespace std;

const int N = 55, mod = 998244353;

int a[N], n, m, w[N], tot, tx, ty;
int dp[N][N * 2][N * 2];

long long qp(long long a, long long n) {
	long long res = 1;
	while(n) {
		if(n & 1) {
			res = res * a % mod;
		}
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

long long inv(long long x) {
	return qp(x, mod - 2);
}


int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &w[i]);
		tot += w[i];
		if(a[i] == 1)
			tx += w[i];
		else
			ty += w[i];
	}
	for(int _ = 1; _ <= n; ++_) {
		memset(dp, 0, sizeof(dp));
		dp[0][w[_]][N] = 1;
		for(int i = 1; i <= m; ++i) {
			int mn, mx;
			if(a[_] == 0) {
				mx = w[_];
				mn = w[_] - i + 1;
			}
			else {
				mn = w[_];
				mx = w[_] + i - 1;
			}
			for(int j = mn; j <= mx; ++j) {
				for(int t = N - (i - 1); t <= N + i - 1; ++t) {
					int x = (t - N + i - 1) / 2, y = ((t - N) + i - 1) / 2, z = dp[i - 1][j][t];
					if(a[_] == 1) {
						dp[i][j][t - 1] = (dp[i][j][t - 1] + (ty - y) * inv(tot + t - N) % mod * z % mod) % mod;
						dp[i][j][t + 1] = (dp[i][j][t + 1] + (tx + x - j) * inv(tot + t - N) % mod * z % mod) % mod;
						dp[i][j + 1][t + 1] = (dp[i][j + 1][t + 1] + j * inv(tot + t - N) % mod * z % mod) % mod;
					}
					else {
						dp[i][j][t - 1] = (dp[i][j][t - 1] + (ty - y - j) * inv(tot + t - N) % mod * z % mod) % mod;
						dp[i][j][t + 1] = (dp[i][j][t + 1] + (tx + x) * inv(tot + t - N) % mod * z % mod) % mod;
						dp[i][j - 1][t - 1] = (dp[i][j - 1][t - 1] + j * inv(tot + t - N) % mod * z % mod) % mod;
						
					}
				}
			}
		}
		long long ans = 0;
		for(int j = 0; j <= 100; ++j) {
			for(int t = N - n; t <= N + n; ++t) {
				ans = (ans + j * dp[m][j][t] % mod) % mod;
			}
		}
		ans = (ans + mod) % mod;
		printf("%lld\n", ans);
	}



	return 0;
}