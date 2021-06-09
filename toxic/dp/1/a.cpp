#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int n, m, K;
char s[N], t[N];
int dp[N][N][12], mmax[N][N][12];


int main() {
	scanf("%d%d%d%s%s", &n, &m, &K, s + 1, t + 1);
	for(int k = 1; k <= K; ++k) {
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= m; ++j) {
				if(s[i] != t[j])
					dp[i][j][k] = 0;
				else {
					dp[i][j][k] = max(dp[i - 1][j - 1][k], mmax[i - 1][j - 1][k - 1]) + 1;
				}
				mmax[i][j][k] = max(dp[i][j][k], max(mmax[i][j - 1][k], mmax[i - 1][j][k]));
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			ans = max(ans, dp[i][j][K]);
	printf("%d\n", ans);

	return 0;
}