#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int pos[N][N], x[N], y[N], n;
long long dp[N][N];

int main() {
	while(~scanf("%d", &n)) {
		memset(dp, 0x3f, sizeof(dp));
		for(int i = 1; i <= n; ++i) {
			scanf("%d%d", &x[i], &y[i]);
			dp[i][i] = 0;
			pos[i][i] = i;
		}
		for(int l = 2; l <= n; ++l) 
			for(int i = 1, j; (j = i + l - 1) <= n; ++i)
				for(int k = pos[i][j - 1]; k <= pos[i + 1][j]; ++k) {
					if(dp[i][j] > dp[i][k] + dp[k + 1][j] + x[k + 1] - x[i] + y[k] - y[j]) {
						dp[i][j] = dp[i][k] + dp[k + 1][j] + x[k + 1] - x[i] + y[k] - y[j];
						pos[i][j] = k;
					}
				}
		printf("%lld\n", dp[1][n]);
	}
	return 0;
}