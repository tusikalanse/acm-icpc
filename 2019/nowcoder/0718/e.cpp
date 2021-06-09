#include <bits/stdc++.h>
using namespace std;

const int N = 1010, mod = 1e9 + 7;

int dp[N << 2][N << 1], n, m;

int main() {
	while(~scanf("%d%d", &n, &m)) {
		for(int i = 0; i <= 2 * (n + m); ++i) {
			for(int j = 0; j <= n + m; ++j)
				dp[i][j] = 0; 
		}
		if(n == 0 && m == 0) {
			puts("0");
			continue;
		}
		if(n != 0)
			dp[1][1] = 1;
		if(m != 0)
			dp[1][0] = 1;
		for(int i = 1; i < 2 * (n + m); ++i) {
			for(int j = 0; j <= i && j <= n + m; ++j) {
				if(j + 1 <= n || j + 1 <= n + (i + 1 - n) / 2) {
					dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % mod;
				}
				if(i + 1 - j <= m || i + 1 - j <= m + (i + 1 - m) / 2) {
					dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % mod;
				}
			}
		}
		printf("%d\n", dp[2 * (n + m)][n + m]);
	}
	return 0;
}