#include <bits/stdc++.h>
using namespace std;

const int N = 5010, mod = 1e9 + 7;

char s[N][2];
int dp[N][N], sum[N][N], ans, n;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) 
		scanf("%s", s[i]);
	dp[0][0] = 1;
	sum[0][0] = 1;
	for(int j = 1; j <= n; ++j) 
		sum[0][j] = 1;
	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j <= n; ++j) {
			if(s[i - 1][0] == 'f') {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = ((sum[i - 1][n] - sum[i - 1][j - 1]) % mod + mod) % mod;
			}
		}
		sum[i][0] = dp[i][0];
		for(int j = 1; j <= n; ++j) 
			sum[i][j] = (sum[i][j - 1] + dp[i][j]) % mod;
	}
	printf("%d\n", sum[n][n]);
	return 0;
}