#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

struct node {
	int val, id;
	bool operator<(const node &rhs) const {
		return val < rhs.val;
	}
}a[N];
int rnk[N], root[N], grand[N][20], dep[N];
int n, m, u, v, k, cnt;
int head[N], pnt[N << 1], nxt[N << 1], _cnt;

void addEdge(int x, int y) {
	pnt[_cnt] = y;
	nxt[_cnt] = head[x];
	head[x] = _cnt++;
}

struct {
	int l, r, num;
}pst[N * 40];

void init() {
	memset(head, -1, sizeof(head));
	_cnt = cnt = 0;
	root[0] = pst[0].l = pst[0].r = pst[0].num = 0;
}

void update(int &rt, int l, int r, int pos) {
	pst[++cnt] = pst[rt];
	rt = cnt;
	pst[rt].num++;
	if(l == r) 
		return;
	int mid = l + r >> 1;
	if(pos <= mid)
		update(pst[rt].l, l, mid, pos);
	else
		update(pst[rt].r, mid + 1, r, pos);
}

void dfs(int rt, int fa) {
	dep[rt] = dep[fa] + 1;
	grand[rt][0] = fa;
	for(int i = 1; i <= 17; ++i)
		grand[rt][i] = grand[grand[rt][i - 1]][i - 1];
	root[rt] = root[fa];
	update(root[rt], 1, n, rnk[rt]);
	for(int i = head[rt]; ~i; i = nxt[i]) {
		if(pnt[i] == fa) continue;
		dfs(pnt[i], rt);
	}
}

int LCA(int u, int v) {
	if(dep[u] < dep[v])
		swap(u, v);
	for(int i = 17; ~i; --i) {
		if(dep[grand[u][i]] >= dep[v])
			u = grand[u][i];
	}
	if(u == v)
		return u;
	for(int i = 17; ~i; --i) {
		if(grand[u][i] != grand[v][i])
			u = grand[u][i], v = grand[v][i];
	}
	return grand[u][0];
}

int query(int u, int v, int lca, int fa_lca, int k, int l, int r) {
	if(l == r)
		return l;
	int mid = l + r >> 1;
	int d = pst[pst[u].l].num + pst[pst[v].l].num - pst[pst[lca].l].num - pst[pst[fa_lca].l].num;
	if(d >= k)
		return query(pst[u].l, pst[v].l, pst[lca].l, pst[fa_lca].l, k, l, mid);
	else
		return query(pst[u].r, pst[v].r, pst[lca].r, pst[fa_lca].r, k - d, mid + 1, r);
}

int main() {
	init();
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i].val);
		a[i].id = i;
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i)
		rnk[a[i].id] = i;
	for(int i = 1; i < n; ++i) {
		scanf("%d%d", &u, &v);
		addEdge(u, v);
		addEdge(v, u);
	}
	dfs(1, 0);
	while(m--) {
		scanf("%d%d%d", &u, &v, &k);
		int lca = LCA(u, v);
		printf("%d\n", a[query(root[u], root[v], root[lca], root[grand[lca][0]], k, 1, n)].val);
	}
	return 0;
}