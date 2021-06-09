#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

int w[N], n, x, y, z;
long long ans, dp[N];

vector<pair<int, int>> G[N];

void dfs(int rt, int fa) {
	dp[rt] = w[rt];
	ans = max(ans, dp[rt]);
	for(auto it: G[rt]) {
		if(it.first == fa)
			continue;
		dfs(it.first, rt);
		if(dp[rt] >= it.second)
			ans = max(ans, dp[rt] + dp[it.first] - it.second);
		if(dp[it.first] >= it.second)
			dp[rt] = max(dp[rt], w[rt] + dp[it.first] - it.second);
	}
}



int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) 
		scanf("%d", &w[i]);
	for(int i = 1; i < n; ++i) {
		scanf("%d%d%d", &x, &y, &z);
		G[x].emplace_back(y, z);
		G[y].emplace_back(x, z);
	}
	dfs(1, 0);
	printf("%lld\n", ans);
	return 0;
}