#include <bits/stdc++.h>
using namespace std;

const int N = 2010;

long long dp[N][N];
int a[N], sum[N], f[N][N], n;

int main() {
	while(~scanf("%d", &n)) {
		memset(dp, 0x3f, sizeof dp);
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			a[i + n] = a[i];
			dp[i][i] = dp[i + n][i + n] = 0;
			f[i][i] = i;
			f[i + n][i + n] = i + n;
		}
		for(int i = 1; i <= (n << 1); ++i) 
			sum[i] = sum[i - 1] + a[i];
		for(int l = 2; l <= n; ++l) {
			for(int i = 1, j = i + l - 1; j <= (n << 1); ++i, ++j) {
				for(int k = f[i][j - 1]; k <= f[i + 1][j]; ++k) {
					if(dp[i][j] > dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]) {
						dp[i][j] = dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1];
						f[i][j] = k;
					}
				}
			}
		}
		long long ans = 0x3f3f3f3f3f3f3f3f;
		for(int i = 1; i <= n; ++i) 
			ans = min(ans, dp[i][i + n - 1]);
		printf("%lld\n", ans);
	}
	return 0;
}