#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;

int T, n, m, k;
int ans, mx;
int x, y, z, vis[N];
vector<pair<int, int>> G[N];

void dfs(int u, int cnt, int sum, int flag) {
	if(vis[u] == flag) return;
	if(sum + mx * (k - cnt) <= ans) return;
	if(k == cnt) {
		ans = max(ans, sum);
		return;
	}
	vis[u] = flag;
	for(auto &e: G[u]) {
		int v, w;
		tie(v, w) = e;
		dfs(v, cnt + 1, sum + w, flag);
	}
	vis[u] = 0;
}

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d%d", &n, &m, &k);
		ans = 0; mx = -1;
		memset(vis, 0, sizeof(int) * (n + 3));
		for(int i = 1; i <= n; ++i) 
			G[i].clear();
		for(int i = 1; i <= m; ++i) {
			scanf("%d%d%d", &x, &y, &z);
			G[x].emplace_back(y, z);
			G[y].emplace_back(x, z);
			mx = max(mx, z);
		}
		for(int i = 1; i <= n; ++i) 
			dfs(i, 1, 0, i);
		if(ans == 0)
			puts("impossible");
		else
			printf("%d\n", ans);
	}
	return 0;
}