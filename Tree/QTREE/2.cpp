#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;
int dep[N], fa[N][16], dis[N];
int head[N], pnt[N << 1], nxt[N << 1], val[N << 1], cnt;
int T, n, u, v, k;
char op[30];

void add(int x, int y, int v) {
	pnt[cnt] = y;
	nxt[cnt] = head[x];
	val[cnt] = v;
	head[x] = cnt++;
}

void dfs(int u, int pre) {
	fa[u][0] = pre;
	dep[u] = dep[pre] + 1;
	for(int i = 1; i < 16; ++i)
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for(int i = head[u]; ~i; i = nxt[i]) if(pnt[i] != pre) {
		dis[pnt[i]] = dis[u] + val[i];
		dfs(pnt[i], u);
	}
}

void init() {
	dis[1] = dep[0] = cnt = 0;
	memset(head, -1, sizeof(head));
}

int lca(int x, int y) {
	if(dep[x] > dep[y]) swap(x, y);
	for(int k = 0; k < 16; ++k)
		if((dep[y] - dep[x]) >> k & 1)
			y = fa[y][k];
	if(x == y)
		return x;
	for(int k = 15; k >= 0; --k)
		if(fa[x][k] != fa[y][k])
			x = fa[x][k], y = fa[y][k];
	return fa[x][0];
}

int kth(int u, int k) {
	for(int i = 0; i < 16; ++i)
		if(k >> i & 1)
			u = fa[u][i];
	return u;
}

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		init();	
		for(int i = 1; i < n; ++i) {
			scanf("%d%d%d", &u, &v, &k);
			add(u, v, k);
			add(v, u, k);
		}
		dfs(1, 0);
		while(1) {
			scanf("%s", op);
			if(op[1] == 'O')
				break;
			if(op[0] == 'D') {
				scanf("%d%d", &u, &v);
				int t = lca(u, v);
				printf("%d\n", dis[u] + dis[v] - 2 * dis[t]);
			}
			else {
				scanf("%d%d%d", &u, &v, &k);
				int t = lca(u, v);
				if(dep[u] - dep[t] + 1 >= k)
					printf("%d\n", kth(u, k - 1));
				else 
					printf("%d\n", kth(v, dep[u] + dep[v] - 2 * dep[t] - k + 1));
			}
		}
	}

	return 0;
}