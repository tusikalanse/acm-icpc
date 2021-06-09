#include <bits/stdc++.h>
using namespace std;

int dp[4][1010][1010];
int num[1010][1010], n, m, ans;

bool check(int i, int j) {
	return i && i <= n && j && j <= m;
}

void mmax(int &a, int b) {
	if(b > a)
		a = b;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			scanf("%d", &num[i][j]);
			dp[0][i][j] = dp[1][i][j] = dp[2][i][j] = dp[3][i][j] = num[i][j];
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			if(check(i + 1, j))
				mmax(dp[0][i + 1][j], dp[0][i][j] + num[i + 1][j]);
			if(check(i, j + 1))
				mmax(dp[0][i][j + 1], dp[0][i][j] + num[i][j + 1]);
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = m; j; --j) {
			if(check(i + 1, j))
				mmax(dp[1][i + 1][j], dp[1][i][j] + num[i + 1][j]);
			if(check(i, j - 1))
				mmax(dp[1][i][j - 1], dp[1][i][j] + num[i][j - 1]);
		}
	}
	for(int i = n; i; --i) {
		for(int j = 1; j <= m; ++j) {
			if(check(i - 1, j))
				mmax(dp[2][i - 1][j], dp[2][i][j] + num[i - 1][j]);
			if(check(i, j + 1))
				mmax(dp[2][i][j + 1], dp[2][i][j] + num[i][j + 1]);
		}
	}
	for(int i = n; i; --i) {
		for(int j = m; j; --j) {
			if(check(i - 1, j))
				mmax(dp[3][i - 1][j], dp[3][i][j] + num[i - 1][j]);
			if(check(i, j - 1))
				mmax(dp[3][i][j - 1], dp[3][i][j] + num[i][j - 1]);
		}
	}
	for(int i = 2; i < n; ++i) 
		for(int j = 2; j < m; ++j) {
			mmax(ans, dp[0][i - 1][j] + dp[3][i + 1][j] + dp[2][i][j - 1] + dp[1][i][j + 1]);
			mmax(ans, dp[0][i][j - 1] + dp[3][i][j + 1] + dp[2][i + 1][j] + dp[1][i - 1][j]);
		}
	printf("%d\n", ans);
	return 0;
}