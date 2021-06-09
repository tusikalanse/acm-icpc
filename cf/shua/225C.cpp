#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

char s[N];
int a[N], dp[N][N << 1], ans;
int n, m, x, y, sum[N];
int NO = 0x3f3f3f3f;

void mmin(int &a, int b) {
	if(b < a)
		a = b;
}

int main() {
	scanf("%d%d%d%d", &n, &m, &x, &y);
	for(int i = 1; i <= n; ++i) {
		scanf("%s", s + 1);
		for(int j = 1; j <= m; ++j)
			a[j] += s[j] == '.';
	}
	for(int i = 1; i <= m; ++i)
		sum[i] = a[i] + sum[i - 1];
	memset(dp, 0x3f, sizeof(dp));
	dp[x][N + x] = sum[x];
	dp[x][N - x] = n * x - sum[x];
	for(int i = x; i < m; ++i) {
		for(int j = N + x; j <= N + y; ++j) if(dp[i][j] != NO) {
			if(i + x <= m)
				mmin(dp[i + x][N - x], dp[i][j] + n * x - (sum[i + x] - sum[i]));
			if(j != N + y)
				mmin(dp[i + 1][j + 1], dp[i][j] + a[i + 1]);
		}
		for(int j = N - y; j <= N - x; ++j) if(dp[i][j] != NO) {
			if(i + x <= m)
				mmin(dp[i + x][N + x], dp[i][j] + sum[i + x] - sum[i]);
			if(j != N - y)
				mmin(dp[i + 1][j - 1], dp[i][j] + n - a[i + 1]);
		}
	}
	ans = NO;
	for(int j = N - y; j <= N + y; ++j) 
		mmin(ans, dp[m][j]);
	printf("%d\n", ans);
	return 0;
}