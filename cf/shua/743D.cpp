#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

long long dp[N], sz[N], ans = -1e18;

int n, a[N], x, y;
vector<int> G[N];

void dfs(int rt, int fa) {
	sz[rt] = a[rt];
	for(auto j : G[rt]) {
		if(j == fa) continue;
		dfs(j, rt);
		if(dp[rt] != -1e18)
			ans = max(ans, dp[rt] + dp[j]);
		dp[rt] = max(dp[rt], dp[j]);
		sz[rt] += sz[j];
	}
	dp[rt] = max(dp[rt], sz[rt]);
}


int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		dp[i] = -1e18;
	}
	for(int i = 1; i < n; ++i) {
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(1, 0);
	if(ans == -1e18) {
		puts("Impossible");
	}
	else
		printf("%lld\n", ans);
	return 0;
}