#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int head[N], pnt[N << 1], nxt[N << 1], val[N << 1], cnt;
map<int, int> vis[N];
int dep[N], dfn[N], top[N], fa[N], son[N], rnk[N], size[N], clk;
int mx[N << 2];
struct edge {
	int x, y, v;
	bool operator<(const edge &rhs) const {
		return v < rhs.v;
	}
	void adjust() {
		if(dep[x] > dep[y])
			swap(x, y);
	}
}seg[N];
int dsu[N];
int n, m, ans;

void add(int x, int y, int v) {
	pnt[cnt] = y;
	val[cnt] = v;
	nxt[cnt] = head[x];
	head[x] = cnt++;
}

int find(int x) {
	return dsu[x] == x ? x : dsu[x] = find(dsu[x]);
}

void unite(int x, int y) {
	int fx = find(x), fy = find(y);
	if(fx != fy)
		dsu[fx] = fy;
}

int kruskal() {
	int res = 0;
	sort(seg + 1, seg + m + 1);
	for(int i = 1; i <= n; ++i)
		dsu[i] = i;
	for(int i = 1; i <= m; ++i) {
		if(find(seg[i].x) == find(seg[i].y)) continue;
		vis[seg[i].x][seg[i].y] = 1;
		vis[seg[i].y][seg[i].x] = 1;
		unite(seg[i].x, seg[i].y);
		res += seg[i].v;
	}
	return res;
}

void dfs1(int rt, int pre, int depth) {
	dep[rt] = depth;
	son[rt] = -1;
	size[rt] = 1;
	fa[rt] = pre;
	for(int i = head[rt]; ~i; i = nxt[i]) {
		int j = pnt[i];
		if(j == pre) continue;
		if(!vis[rt].count(j)) continue;
		dfs1(j, rt, depth + 1);
		size[rt] += size[j];
		if(son[rt] == -1 || size[j] > size[son[rt]])
			son[rt] = j;
	}
}

void dfs2(int rt, int t) {
	top[rt] = t;
	dfn[rt] = clk;
	rnk[clk] = rt;
	clk++;
	if(son[rt] == -1)
		return;
	dfs2(son[rt], t);
	for(int i = head[rt]; ~i; i = nxt[i]) {
		int j = pnt[i];
		if(j == fa[rt] || j == son[rt]) continue;
		if(!vis[rt].count(j)) continue;
		dfs2(j, j);
	}
}

void pushup(int rt) {
	mx[rt] = max(mx[rt << 1], mx[rt << 1 | 1]);
}

void build(int rt, int l, int r) {
	mx[rt] = 0;
	if(l == r)
		return;
	int mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
}

void update(int rt, int l, int r, int pos, int val) {
	if(l == r) {
		mx[rt] = val;
		return;
	}
	int mid = l + r >> 1;
	if(pos <= mid)
		update(rt << 1, l, mid, pos, val);
	else
		update(rt << 1 | 1, mid + 1, r, pos, val);
	pushup(rt);
}

int query(int rt, int l, int r, int L, int R) {
	if(L <= l && r <= R)
		return mx[rt];
	int mid = l + r >> 1, ans = 0;
	if(L <= mid)
		ans = max(ans, query(rt << 1, l, mid, L, R));
	if(mid < R)
		ans = max(ans, query(rt << 1 | 1, mid + 1, r, L, R));
	return ans;
}

int ask(int a, int b) {
	int ans = 0, ta = top[a], tb = top[b];
	while(ta != tb) {
		if(dep[ta] < dep[tb])
			swap(ta, tb), swap(a, b);
		ans = max(ans, query(1, 1, n, dfn[ta], dfn[a]));
		a = fa[ta];
		ta = top[a];
	}
	if(a == b) return ans;
	if(dep[a] > dep[b]) swap(a, b);
	return max(ans, query(1, 1, n, dfn[son[a]], dfn[b]));
}

void input() {
	memset(head, -1, sizeof(head));
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i) {
		scanf("%d%d%d", &seg[i].x, &seg[i].y, &seg[i].v);
		add(seg[i].x, seg[i].y, seg[i].v);
		add(seg[i].y, seg[i].x, seg[i].v);
	}
}

void init() {
	clk = 1;
	kruskal();
	dfs1(1, 1, 0);
	dfs2(1, 1);
	build(1, 1, n);
	for(int i = 1; i <= m; ++i) {
		if(!vis[seg[i].x].count(seg[i].y)) continue;
		seg[i].adjust();
		update(1, 1, n, dfn[seg[i].y], seg[i].v);
	}
}

int solve() {
	for(int i = 1; i <= m; ++i) {
		if(vis[seg[i].x].count(seg[i].y)) continue;
		ans += seg[i].v == ask(seg[i].x, seg[i].y);
	}
	return ans;
}

int main() {
	input();
	init();
	printf("%d\n", solve());
	return 0;
}