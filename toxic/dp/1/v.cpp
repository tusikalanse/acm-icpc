#include <bits/stdc++.h>
using namespace std;

int mp[30][30];
int dp[30][30][30][30];
int n, m, ans;
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			scanf("%1d", &mp[i][j]);
		}
	}
	for(int u = 1; u <= n; ++u) {
		for(int l = 1; l <= m; ++l) {
			for(int d = u; d <= n; ++d) {
				for(int r = l; r <= m; ++r) {
					dp[u][l][d][r] = 1;
					for(int i = u; i <= d; ++i) {
						for(int j = l; j <= r; ++j) 
							dp[u][l][d][r] &= (!mp[i][j]);
					}
					if(dp[u][l][d][r]) 
						ans = max(ans, (d - u + 1) * 2 + (r - l + 1) * 2);
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}