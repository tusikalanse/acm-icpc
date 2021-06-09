#include <bits/stdc++.h>
using namespace std;

const int N = 5010;

int dp[N][N], mark[N][N], ans, tmp, n, m;
char mp[N][N];

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		scanf("%s", &mp[i][1]);
		for(int j = 1; j <= m; ++j) {
			if(mp[i][j] == '1') {
				dp[i][j] = dp[i][j - 1] + 1;
				mark[j][dp[i][j]]++;
			}
			else
				dp[i][j] = 0;
		}
	}
	for(int j = 1; j <= m; ++j) {
		tmp = 0;
		for(int i = m; i; --i) {
			tmp += mark[j][i];
			ans = max(ans, tmp * i);
		}
	}
	printf("%d\n", ans);
	return 0;
}