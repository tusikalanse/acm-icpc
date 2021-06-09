#include <bits/stdc++.h>
using namespace std;

const int N = 5010;

int dp[N][N][2], n, c[N];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &c[i]);
		dp[i][i][0] = dp[i][i][1] = 0;
	}
	for(int len = 2; len <= n; ++len) {
		for(int i = 1; i + len - 1 <= n; ++i) {
			int j = i + len - 1;
			dp[i][j][0] = min(dp[i + 1][j][0] + (c[i] != c[i + 1]), dp[i + 1][j][1] + (c[i] != c[j]));
			dp[i][j][1] = min(dp[i][j - 1][1] + (c[j - 1] != c[j]), dp[i][j - 1][0] + (c[i] != c[j]));
		}
	}
	printf("%d\n", min(dp[1][n][0], dp[1][n][1]));
	return 0;
}