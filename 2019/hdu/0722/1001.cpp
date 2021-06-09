#include <bits/stdc++.h>
using namespace std;

const int N = 101, mod = 998244353;

int dp[N][N][N][2], T, n, m, l, r, x, ans;

vector<pair<int, int>> cons[N];

void addmod(int &x, int y) {
	x += y;
	if(x >= mod)
		x -= mod;
}

int main() {
	scanf("%d", &T);
	while(T--) {
		ans = 0;
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= m; ++i) {
			scanf("%d%d%d", &l, &r, &x);
			cons[r].push_back({l, x});
		}
		for(int i = 1; i <= n; ++i)
			cons[i].push_back({i, 1});
		memset(dp, 0, sizeof(dp));
		dp[0][0][0][0] = 1;
		for(int cur = 1; cur <= n; ++cur) {
			int o = cur & 1;
			for(int i = 0; i <= cur; ++i) 
				for(int j = i; j <= cur; ++j)
					for(int k = j; k <= cur; ++k)
						dp[i][j][k][o] = 0;
			for(int i = 0; i <= cur; ++i) 
				for(int j = i; j <= cur; ++j)
					for(int k = j; k <= cur; ++k) {
						addmod(dp[j][k][cur - 1][o], dp[i][j][k][o ^ 1]);
						addmod(dp[i][k][cur - 1][o], dp[i][j][k][o ^ 1]);
						addmod(dp[i][j][cur - 1][o], dp[i][j][k][o ^ 1]);
						addmod(dp[i][j][k][o], dp[i][j][k][o ^ 1]);
					}
			for(int i = 0; i <= cur; ++i) {
				for(int j = i; j <= cur; ++j)
					for(int k = j; k <= cur; ++k) 
						for(auto c : cons[cur]) {
							l = c.first, x = c.second;
							if((i >= l) + (j >= l) + (k >= l) + (cur >= l) != x)
								dp[i][j][k][o] = 0;
						}
			}
		}
		for(int i = 0; i <= n; ++i)
			for(int j = i; j <= n; ++j) 
				for(int k = j; k <= n; ++k)
					addmod(ans, dp[i][j][k][n & 1]);
		printf("%d\n", ans);
		for(int i = 1; i <= n; ++i)
			cons[i].clear();
	}
	return 0;
}