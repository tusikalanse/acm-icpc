#include <bits/stdc++.h>
using namespace std;

const int N = 3010, mod = 998244353;

int fac[N], invfac[N], ans, T, n, m;

int qp(int a, int n) {
	int res = 1;
	while(n) {
		if(n & 1)
			res = 1LL * res * a % mod;
		a = 1LL * a * a % mod;
		n >>= 1;
	}
	return res;
}

void init() {
	fac[0] = invfac[0] = 1;
	for(int i = 1; i < N; ++i) {
		fac[i] = 1LL * fac[i - 1] * i % mod;
		invfac[i] = qp(fac[i], mod - 2);
	}
}

int C(int n, int m) {
	return 1LL * fac[n] * invfac[n - m] % mod * invfac[m] % mod;
}


int dp[N][N], dp2[N][N];

char s[N], t[N];

int main() {
	init();
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d%s%s", &n, &m, s + 1, t + 1);
		ans = 0;
		for(int i = 0; i <= n; ++i) {
			for(int j = 0; j <= m; ++j) dp[i][j] = dp2[i][j] = 0;
			dp2[i][0] = 1;
		}
		for(int i = 1; i <= n; ++i) {
			if(s[i] == '0') continue;
			for(int j = n - i; j >= m; --j) {
				ans = (ans + C(n - i, j)) % mod;
			}
		}
		//cout << ans << endl;
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j) {
				dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % mod;;
				if(s[i] > t[j]) {
					dp[i][j] = (dp[i][j] + dp2[i - 1][j - 1]) % mod;
				}
				dp2[i][j] = dp2[i - 1][j];
				if(s[i] == t[j])
					dp2[i][j] = (dp2[i][j] + dp2[i - 1][j - 1]) % mod;
			}
		}
		ans = (ans + dp[n][m]) % mod;
		printf("%d\n", ans);
	}
	return 0;
}