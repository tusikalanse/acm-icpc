#include <cstdio>
#include <cstring>
#define max(a, b) (a > b) ? a : b
int dp[1005][1005];
char s1[1005], s2[1005];


int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	while(~scanf("%s %s", s1, s2)) {
		memset(dp, 0, sizeof(dp));
		int n = strlen(s1), m = strlen(s2);
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				if(s1[i-1] == s2[j-1]) {
					dp[i][j] = dp[i-1][j-1] + 1;
				}
				else 
					dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
			}
		}
		printf("%d\n", dp[n][m]);
	}
	return 0;
}