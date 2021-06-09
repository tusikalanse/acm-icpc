#include <bits/stdc++.h>
using namespace std;

const int N = 510;

int ans, n, dp[N][N][26], mn[N][N];
char s[N];

int main() {
	scanf("%d%s", &n, s + 1);
	ans = 0x3f3f3f3f;
	memset(dp, 0x3f, sizeof(dp));
	memset(mn, 0x3f, sizeof(mn));
	for(int i = 1; i <= n; ++i) {
		dp[i][i][s[i] - 'a'] = 0;
		mn[i][i] = 0;
	}
	for(int len = 2; len <= n; ++len) {
		for(int l = 1; l + len - 1 <= n; ++l) {
			int r = l + len - 1;
			for(int k = l; k < r; ++k) {
				for(int ch = 0; ch < 26; ++ch) {
					dp[l][r][ch] = min(dp[l][r][ch], dp[l][k][ch] + dp[k + 1][r][ch]);
					dp[l][r][ch] = min(dp[l][r][ch], dp[l][k][ch] + mn[k + 1][r] + 1);
					dp[l][r][ch] = min(dp[l][r][ch], mn[l][k] + dp[k + 1][r][ch] + 1);
					mn[l][r] = min(mn[l][r], dp[l][r][ch]);
				}
			}
		}
	}
	printf("%d\n", mn[1][n] + 1);
	return 0;
}