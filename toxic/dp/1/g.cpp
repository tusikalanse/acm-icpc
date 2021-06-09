#include <bits/stdc++.h>
using namespace std;

const int N = 2010, mod = 1e9 + 7;
int vis[N], f[N], a[N], n, d;
int nxt[N << 1], pnt[N << 1], head[N], cnt;

void add(int x, int y) {
	pnt[cnt] = y;
	nxt[cnt] = head[x];
	head[x] = cnt++;
}

void dfs(int u, int root) {
	f[u] = vis[u] = 1;
	for(int i = head[u]; ~i; i = nxt[i]) {
		int j = pnt[i];
		if(vis[j] || a[j] < a[root] || a[j] > a[root] + d) continue;
		if(a[j] == a[root] && j < root) continue;
		dfs(j, root);
		f[u] = 1LL * f[u] * (f[j] + 1) % mod;
	}
}

int main() {
	memset(head, -1, sizeof(head));
	scanf("%d%d", &d, &n);
	for(int i = 1; i <= n; ++i) 
		scanf("%d", &a[i]);
	int u, v;
	for(int i = 1; i < n; ++i) {
		scanf("%d%d", &u, &v);
		add(u, v); add(v, u);
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		memset(vis, 0, sizeof(vis));
		dfs(i, i);
		ans = (ans + f[i]) % mod;
	}
	printf("%d\n", ans);
	return 0;
}