#include <bits/stdc++.h>
using namespace std;

const int N = 510;

int n, a[N][N], ans[N][N], dp[N][N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			scanf("%1d", &a[i][j]);
		}
	}
	for (int len = 1; len < n; ++len) {
		for (int i = 1, j = i + len; j <= n; ++i, ++j) {
			for (int k = i; k <= j; ++k) dp[i][j] = (dp[i][j] + dp[i][k] * ans[k][j]) % 10;
			if (a[i][j] == dp[i][j]) {ans[i][j] = 0; continue;}
			if (a[i][j] == (dp[i][j] + 1) % 10) {ans[i][j] = 1; (dp[i][j] += 1) %= 10; continue;}
			cout << i << " " << j << " " << a[i][j] << " " << dp[i][j] << endl;
			assert(false);
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			printf("%d", ans[i][j]);
		puts("");
	}
	return 0;
}