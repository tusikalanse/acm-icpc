#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int fa[N], top[N], son[N], dfn[N], size[N], dep[N], rnk[N], clk;
int head[N], pnt[N << 1], nxt[N << 1], cnt;
int key[N << 2];
int n, q, op, x, y;

void add(int x, int y) {
	pnt[cnt] = y;
	nxt[cnt] = head[x];
	head[x] = cnt++;
}

void dfs1(int rt, int pre) {
	dep[rt] = dep[pre] + 1;
	size[rt] = 1;
	fa[rt] = pre;
	son[rt] = -1;
	for(int i = head[rt]; ~i; i = nxt[i]) if(pnt[i] != pre) {
		dfs1(pnt[i], rt);
		size[rt] += size[pnt[i]];
		if(son[rt] == -1 || size[son[rt]] < size[pnt[i]])
			son[rt] = pnt[i];
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
		if(j != fa[rt] && j != son[rt])
			dfs2(j, j);
	}
}

void pushup(int rt) {
	if(~key[rt << 1])
		key[rt] = key[rt << 1];
	else
		key[rt] = key[rt << 1 | 1];
}

void build(int rt, int l, int r) {
	key[rt] = -1;
	if(l == r) 
		return;
	int mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
}

void update(int rt, int l, int r, int pos) {
	if(l == r) {
		if(key[rt] == -1)
			key[rt] = rnk[l];
		else
			key[rt] = -1;
		return;
	}
	int mid = l + r >> 1;
	if(pos <= mid)
		update(rt << 1, l, mid, pos);
	else
		update(rt << 1 | 1, mid + 1, r, pos);
	pushup(rt);
}

int query(int rt, int l, int r, int L, int R) {
	if(L <= l && r <= R)
		return key[rt];
	int mid = l + r >> 1, ans = -1;
	if(mid >= L)
		ans = query(rt << 1, l, mid, L, R);
	if(~ans)
		return ans;
	if(mid < R)
		ans = query(rt << 1 | 1, mid + 1, r, L, R);
	return ans;
}

void init() {
	clk = 1;
	dep[0] = 0;
	cnt = 0;	
	memset(head, -1, sizeof(head));
}

int getans(int x) {
	int ans = -1, t;
	while(top[x] != 1) {
		t = query(1, 1, n, dfn[top[x]], dfn[x]);
		if(~t) ans = t;
		x = fa[top[x]];
	}
	t = query(1, 1, n, dfn[1], dfn[x]);
	if(~t) ans = t;
	return ans;
}

int main() {
	scanf("%d%d", &n, &q);
	init();
	for(int i = 1; i < n; ++i) {
		scanf("%d%d", &x, &y);
		add(x, y); add(y, x);
	}
	dfs1(1, 0);
	dfs2(1, 1);
	build(1, 1, n);
	while(q--) {
		scanf("%d%d", &op, &x);
		if(op == 0)
			update(1, 1, n, dfn[x]);
		else
			printf("%d\n", getans(x));
	}
	return 0;
}