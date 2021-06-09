#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, m;
int size[N], fa[N], top[N], dfn[N], rnk[N], dep[N], son[N], cnt;
int head[N], nxt[N << 1], pnt[N << 1], num;
int mx[N << 2];

void add(int x, int y) {
	pnt[num] = y;
	nxt[num] = head[x];
	head[x] = num++;
}

void dfs1(int rt, int pre, int depth) {
	dep[rt] = depth;
	fa[rt] = pre;
	son[rt] = -1;
	size[rt] = 1;
	for(int i = head[rt]; ~i; i = nxt[i]) if(pnt[i] != pre) {
		int j = pnt[i];
		dfs1(j, rt, depth + 1);
		if(son[rt] == -1 || size[son[rt]] < size[j])
			son[rt] = j;
		size[rt] += size[j];
	}
}

void dfs2(int rt, int t) {
	top[rt] = t;
	dfn[rt] = cnt;
	rnk[cnt] = rt;
	cnt++;
	if(son[rt] == -1)
		return;
	dfs2(son[rt], t);
	for(int i = head[rt]; ~i; i = nxt[i]) {
		int j = pnt[i];
		if(j != fa[rt] && j != son[rt])
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
		mx[rt] += val;
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
	if(mid >= L)
		ans = max(ans, query(rt << 1, l, mid, L, R));
	if(mid < R)
		ans = max(ans, query(rt << 1 | 1, mid + 1, r, L, R));
	return ans;
}

int getmax(int u, int v) {
	int ans = 0;
	int fu = top[u], fv = top[v];
	while(fu != fv) {
		if(dep[fu] < dep[fv])
			swap(u, v), swap(fu, fv);
		ans = max(ans, query(1, 1, n, dfn[fu], dfn[u]));
		u = fa[fu];
		fu = top[u];
	}
	if(dep[u] > dep[v])
		swap(u, v);
	return max(ans, query(1, 1, n, dfn[u], dfn[v]));
}

int main() {
	scanf("%d", &n);
	memset(head, -1, sizeof(head));
	cnt = num = 1;
	int u, v;
	char ch[5];
	for(int i = 1; i < n; ++i) {
		scanf("%d%d", &u, &v);
		add(u, v); add(v, u);
	}
	dfs1(1, 0, 0);
	dfs2(1, 1);
	build(1, 1, n);
	scanf("%d", &m);
	while(m--) {
		scanf("%s%d%d", ch, &u, &v);
		if(ch[0] == 'I')
			update(1, 1, n, dfn[u], v);
		else
			printf("%d\n", getmax(u, v));
	}
	return 0;
}