#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, root, dis[N], kk[N], k, mx, x, y;

vector<int> G[N];

void dfs(int rt, int fa, int dep) {
	dis[rt] = dep;
	if(dis[rt] > dis[root] && kk[rt])
		root = rt;
	for(auto f: G[rt]) {
		if(f == fa) continue;
		dfs(f, rt, dep + 1);
	}
}


void dfs2(int rt, int fa, int dep) {
	dis[rt] = dep;
	if(kk[rt])
		mx = max(mx, dis[rt]);
	for(auto f: G[rt]) {
		if(f == fa) continue;
		dfs2(f, rt, dep + 1);
	}
}


int main() {
	scanf("%d%d", &n, &k);
	if(k <= 1) {
		puts("0");
		return 0;
	}
	for(int i = 1; i < n; ++i) {
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for(int i = 1; i <= k; ++i) {
		scanf("%d", &x);
		kk[x] = 1;
		root = x;
	}
	dfs(root, 0, 0);
	memset(dis, 0, sizeof(dis));
	dfs2(root, 0, 0);
	printf("%d\n", (mx + 1) / 2);
	return 0;
}