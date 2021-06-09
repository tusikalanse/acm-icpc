#include <bits/stdc++.h>
using namespace std;

map<int, int> cnt[50010];

int head[50010], pnt[50010 << 1], val[50010 << 1], nxt[50010 << 1], c = 0, ans;
bool vis[50010];
bool del[50010 << 1];

void add(int u, int v, int w) {
	cnt[u][w]++;
	pnt[c] = v;
	nxt[c] = head[u];
	val[c] = w;
	head[u] = c++;
}

void dfs(int u, int fa) {
	if(vis[u])
		ans--;
	vis[u] = 0;
	for(int i = head[u]; ~i; i = nxt[i]) {
		if(pnt[i] == fa)
			continue;
		if(!del[i]) {
			del[i] = 1;
			dfs(pnt[i], u);
		}
	}
}

int main() {
	memset(del, 0, sizeof(del));
	memset(vis, 1, sizeof(vis));
	memset(head, -1, sizeof(head));
	int n, a, b, c;
	scanf("%d", &n);
	ans = n;
	for(int i = 1; i < n; ++i) {
		scanf("%d %d %d", &a, &b, &c);
		add(a, b, c);
		add(b, a, c);
	}
	for(int i = 1; i <= n; ++i) {
		for(int u = head[i]; ~u; u = nxt[u]) {
			if(cnt[i][val[u]] > 1 && (!del[u])) {
				del[u] = 1;
				dfs(pnt[u], i);
			}
		}
	}
	printf("%d\n", ans);
	for(int i = 1; i <= n; ++i)
		if(vis[i])
			printf("%d\n", i);
	return 0;
}