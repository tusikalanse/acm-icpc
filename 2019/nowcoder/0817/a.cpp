#include <bits/stdc++.h>
using namespace std;

const int N = 510;

double dp[2][N][N], p[N], ans;
int n, a, b, x[N];

int main() {
	scanf("%d%d%d", &n, &a, &b);
	dp[0][0][0] = 1;
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &x[i]);
		memcpy(dp[i & 1], dp[(i & 1) ^ 1], sizeof(dp[0]));
		for(int j = 1; j <= n; ++j)
			for(int k = x[i]; k <= b; ++k)
				dp[i & 1][j][k] += dp[(i & 1) ^ 1][j - 1][k - x[i]];
	}
	p[1] = 1.0 / n;
	for(int i = 2; i <= n; ++i) 
		p[i] = p[i - 1] * (i - 1) / (n - i + 1);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) 
			for(int k = x[i]; k <= b; ++k)
				dp[n & 1][j][k] -= dp[n & 1][j - 1][k - x[i]];
		for(int j = 0; j < n; ++j) {
			for(int k = max(0, a - x[i] + 1); k <= a && k + x[i] <= b; ++k)
				ans += dp[n & 1][j][k] * p[j + 1];
		}
		for(int j = n; j >= 1; --j) {
			for(int k = b; k >= x[i]; --k)
				dp[n & 1][j][k] += dp[n & 1][j - 1][k - x[i]];
		}
	}
	printf("%.15f\n", ans);
	return 0;
}