#include <bits/stdc++.h>
using namespace std;

const int N = 2010, mod = 1e9 + 7;

int dp[N][N], n, m, l, r, d, tmp;
char s[100010];

void init() {
	dp[0][0] = dp[1][1] = 1;
	for(int i = 2; i < N; ++i) 
		for(int j = (i + 1) >> 1; j <= i; ++j)
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
}


int main() {
	init();
	scanf("%d%d%s", &n, &m, s);
	if(n & 1)
		return 0 * puts("0");
	for(int i = 0; i < m; ++i) {
		if(s[i] == '(') {
			l++;
			tmp--;
		}
		else {
			r++;
			tmp++;
		}
		d = max(d, tmp);
	}
	long long ans = 0;
	for(int i = 0; i <= n - m; ++i) {
		for(int j = (d + i + 1) >> 1; j <= i && j <= n / 2 - l; ++j) 
			ans = (ans + 1LL * dp[i][j] * dp[n - m - i][n / 2 - r - (i - j)]) % mod;
	}
	printf("%lld\n", ans);
	return 0;
}