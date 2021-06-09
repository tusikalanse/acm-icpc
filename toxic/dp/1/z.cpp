#include <bits/stdc++.h>
using namespace std;

int dp[110][10010];
int sum[110][110], size[110], mx[110][110];
int n, m, a;

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &size[i]);
		for(int j = 1; j <= size[i]; ++j) {
			scanf("%d", &a);
			sum[i][j] = sum[i][j - 1] + a;
		}
		for(int tot = 1; tot <= size[i]; ++tot) {
			for(int j = 0; j <= tot; ++j)
				mx[i][tot] = max(mx[i][tot], sum[i][j] - sum[i][0] + sum[i][size[i]] - sum[i][size[i] - tot + j]);
		}
	}	
	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j <= m; ++j) {
			for(int k = 0; k <= size[i]; ++k) {
				if(j + k <= m)
					dp[i][j + k] = max(dp[i][j + k], dp[i - 1][j] + mx[i][k]);
			}
		}
	}
	printf("%d\n", dp[n][m]);
	return 0;
}