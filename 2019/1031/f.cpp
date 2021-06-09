#include <bits/stdc++.h>
using namespace std; 

const int N = 4010;

int n, deg[N], a, b, sz[N], cc;
unsigned long long h[N], g[N], r[N];
vector<int> G[N];


void dfs_size(int rt, int pre) {
	sz[rt] = 1;
	for (auto u: G[rt]) {
		if (u == pre) continue;
		dfs_size(u, rt);
		sz[rt] += sz[u];
	}
}

void dfs1(int rt, int pre) {
	h[rt] = 1;
	for (auto u: G[rt]) {
		if (u == pre) continue;
		dfs1(u, rt);
		h[rt] += h[u] * r[sz[u]];
	}
}

void dfs2(int rt, int pre, unsigned long long V, vector<int> &save) {
	g[rt] = (h[rt] + V * r[cc - sz[rt]]);
	save.push_back(g[rt]);
	V = (V * r[cc - sz[rt]] + 1);
	for (auto u: G[rt]) {
		if (u == pre) continue;
		dfs2(u, rt, V + h[rt] - 1 - h[u] * r[sz[u]], save);
	}
}

bool gao(int rt) {
	dfs_size(rt, 0);
	vector<int> s;
	for (auto u: G[rt])
		s.push_back(sz[u]);
	sort(s.begin(), s.end());
	if (s.front() != s.back()) return false;
	cc = s.front();
	vector<vector<int>> GG;
	GG.resize(deg[rt]); 
	int cnt = 0;
	for (auto u: G[rt]) {
		dfs1(u, rt);
		dfs2(u, rt, 0, GG[cnt++]);
	}
	sort(GG[0].begin(), GG[0].end());
	for (int i = 1; i < deg[rt]; ++i) {
		sort(GG[i].begin(), GG[i].end());
		for (int j = 0; j < cc; ++j) 
			if (GG[0][j] != GG[i][j]) return false;
	}
	return true;
}

int main() {
	for (int i = 0; i < N; ++i) r[i] = (rand() << 31LL) + rand();
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		scanf("%d%d", &a, &b);
		deg[a]++;
		deg[b]++;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int ans = -1;
	for (int i = 1; i <= n; ++i) {
		if (deg[i] > 1 && gao(i))
			ans = max(ans, deg[i]);
	}
	printf("%d\n", ans);
	return 0;
}