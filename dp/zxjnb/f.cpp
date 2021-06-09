#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 310;

int dp[MAXN][32], cost[MAXN][MAXN], n, m, pos[MAXN], s[MAXN][32];

int main() {
	memset(cost, 0x3f, sizeof(cost));
	memset(dp, 0x3f, sizeof(dp));
	scanf("%d%d", &n, &m);
	dp[0][0] = 0;
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &pos[i]);
	}
	for(int i = 1; i <= n; ++i) {
		cost[i][i] = 0;
		for(int j = i + 1; j <= n; ++j) 
			cost[i][j] = cost[i][j - 1] + pos[j] - pos[i + j >> 1];
		dp[i][1] = cost[1][i];
		s[i][1] = 0;
	}
	for(int j = 2; j <= m; ++j) {
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
	printf("%d\n", dp[n][m]);
	return 0;
}