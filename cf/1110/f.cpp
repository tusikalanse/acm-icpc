#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 5e5 + 10;

int deg[N], vis[N], id[N][2], cnt, n, q, p, w, v, l, r;
vector< pair<int, int> > edge[N];
struct query {
	int l, r, id;
};
vector<query> Q[N];
LL mn[N << 2], dis[N], lazy[N << 2], ans[N];

void dfs(int rt, LL d) {
	id[rt][0] = ++cnt;
	dis[rt] = d;
	vis[rt] = 1;
	for(int i = 0; i < edge[rt].size(); ++i) {
		if(vis[edge[rt][i].first])
			continue;
		dfs(edge[rt][i].first, d + edge[rt][i].second);
	}
	id[rt][1] = cnt;
}

void pushup(int rt) {
	mn[rt] = min(mn[rt << 1], mn[rt << 1 | 1]);
}

void build(int rt, int l, int r) {
	if(l == r) {
		if(deg[l] == 1) {
			mn[rt] = dis[l];
		}
		else
			mn[rt] = 0x3f3f3f3f3f3f3f3f;
		return;
	}
	int mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	pushup(rt);
}

void pushdown(int rt) {
	if(lazy[rt]) {
		lazy[rt << 1] += lazy[rt];
		lazy[rt << 1 | 1] += lazy[rt];
		mn[rt << 1] += lazy[rt];
		mn[rt << 1 | 1] += lazy[rt];
		lazy[rt] = 0;
	}
}

void update(int rt, int l, int r, int L, int R, int val) {
	if(L <= l && r <= R) {
		lazy[rt] += val;
		mn[rt] += val;
		return;
	}
	pushdown(rt);
	int mid = l + r >> 1;
	if(mid >= L)
		update(rt << 1, l, mid, L, R, val);
	if(mid < R)
		update(rt << 1 | 1, mid + 1, r, L, R, val);
	pushup(rt);
}

LL get(int rt, int l, int r, int L, int R) {
	if(L <= l && r <= R)
		return mn[rt];
	pushdown(rt);
	int mid = l + r >> 1;
	LL ans = 0x3f3f3f3f3f3f3f3f;
	if(mid >= L)
		ans = min(ans, get(rt << 1, l, mid, L, R));
	if(mid < R)
		ans = min(ans, get(rt << 1 | 1, mid + 1, r, L, R));
	return ans;
}

void solve(int rt) {
	vis[rt] = 1;
	for(int i = 0; i < Q[rt].size(); ++i) {
		ans[Q[rt][i].id] = get(1, 1, n, Q[rt][i].l, Q[rt][i].r);
	}
	for(int i = 0; i < edge[rt].size(); ++i) {
		if(vis[edge[rt][i].first])
			continue;
		int j = edge[rt][i].first, w = edge[rt][i].second;
		update(1, 1, n, id[j][0], id[j][1], -w);
		if(id[j][0] > 1)
			update(1, 1, n, 1, id[j][0] - 1, w);
		if(id[j][1] < n)
			update(1, 1, n, id[j][1] + 1, n, w);
		solve(j);
		update(1, 1, n, id[j][0], id[j][1], w);
		if(id[j][0] > 1)
			update(1, 1, n, 1, id[j][0] - 1, -w);
		if(id[j][1] < n)
			update(1, 1, n, id[j][1] + 1, n, -w);
	}
}

int main() {
	scanf("%d%d", &n, &q);
	for(int i = 2; i <= n; ++i) {
		scanf("%d%d", &p, &w);
		edge[i].push_back(make_pair(p, w));
		edge[p].push_back(make_pair(i, w));
		++deg[i], ++deg[p];
	}
	for(int i = 1; i <= n; ++i)
		sort(edge[i].begin(), edge[i].end());
	dfs(1, 0);
	build(1, 1, n);
	for(int i = 1; i <= q; ++i) {
		scanf("%d%d%d", &v, &l, &r);
		Q[v].push_back({l, r, i});
	}
	memset(vis, 0, sizeof(vis));
	solve(1);
	for(int i = 1; i <= q; ++i)
		printf("%lld\n", ans[i]);
	return 0;
}