#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1010;

long long dp[N][N], cost[N][N];
int a[N], sum[N], s[N][N], n, m;

int main() {
	while(~scanf("%d%d", &n, &m) && n) {
		memset(dp, 0x3f, sizeof(dp));
		memset(cost, 0x3f, sizeof(cost));
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			sum[i] = sum[i - 1] + a[i];
		}
		for(int i = 1; i <= n; ++i) {
			cost[i][i] = 0;
			for(int j = i + 1; j <= n; ++j)
				cost[i][j] = cost[i][j - 1] + 1LL * a[j] * (sum[j - 1] - sum[i - 1]);
			dp[i][0] = cost[1][i];
			s[i][0] = 0;
		}
		for(int j = 1; j <= m; ++j) {
			s[n + 1][j] = n;
			for(int i = n; i > 0; --i) {
				for(int k = s[i][j - 1]; k <= s[i + 1][j]; ++k) {
					if(dp[i][j] > dp[k][j - 1] + cost[k + 1][i]) {
						dp[i][j] = dp[k][j - 1] + cost[k + 1][i];
						s[i][j] = k;
					}
				}
			}
		}
		printf("%lld\n", dp[n][m]);
	}
	return 0;
}