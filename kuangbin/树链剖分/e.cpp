#include <bits/stdc++.h>
using namespace std;

const int N = 30010;

int fa[N], son[N], size[N], top[N], dfn[N], rnk[N], val[N], dep[N], clk, root;
int head[N], nxt[N << 1], pnt[N << 1], cnt;
int mx[N << 2], sum[N << 2];
int n, m, a, b;
char ch[8];

void add(int x, int y) {
	pnt[cnt] = y;
	nxt[cnt] = head[x];
	head[x] = cnt++;
}

void dfs1(int u, int pre, int depth) {
	fa[u] = pre;
	son[u] = -1;
	size[u] = 1;
	dep[u] = depth;
	for(int i = head[u]; ~i; i = nxt[i]) if(pre != pnt[i]) {
		int v = pnt[i];
		dfs1(v, u, depth + 1);
		size[u] += size[v];
		if(son[u] == -1 || size[v] > size[son[u]])
			son[u] = v;
	}
}

void dfs2(int u, int t) {
	top[u] = t;
	dfn[u] = ++clk;
	rnk[dfn[u]] = u;
	if(son[u] == -1)
		return;
	dfs2(son[u], t);
	for(int i = head[u]; ~i; i = nxt[i]) {
		int v = pnt[i];
		if(v != fa[u] && v != son[u])
			dfs2(v, v);
	}
}

void pushup(int rt) {
	mx[rt] = max(mx[rt << 1], mx[rt << 1 | 1]);
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void build(int rt, int l, int r) {
	if(l == r) {
		sum[rt] = mx[rt] = val[rnk[l]];
		return;
	}
	int mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	pushup(rt);
}

void update(int rt, int l, int r, int pos, int num) {
	if(l == r) {
		sum[rt] = mx[rt] = num;
		return;
	}
	int mid = l + r >> 1;
	if(pos <= mid)
		update(rt << 1, l, mid, pos, num);
	else 
		update(rt << 1 | 1, mid + 1, r, pos, num);
	pushup(rt);
}

int qmax(int rt, int l, int r, int L, int R) {
	if(L <= l && r <= R) 
		return mx[rt];
	int mid = l + r >> 1, ans = -1e9;
	if(mid >= L)
		ans = max(ans, qmax(rt << 1, l, mid, L, R));
	if(mid < R)
		ans = max(ans, qmax(rt << 1 | 1, mid + 1, r, L, R));
	return ans;
}

int qsum(int rt, int l, int r, int L, int R) {
	if(L <= l && r <= R) 
		return sum[rt];
	int mid = l + r >> 1, ans = 0;
	if(mid >= L)
		ans += qsum(rt << 1, l, mid, L, R);
	if(mid < R)
		ans += qsum(rt << 1 | 1, mid + 1, r, L, R);
	return ans;
}

int getmax(int va, int vb) {
	int ans = -1e9, f1 = top[va], f2 = top[vb];
	while(f1 != f2) {
		if(dep[f1] < dep[f2])
			swap(va, vb), swap(f1, f2);
		ans = max(ans, qmax(1, 1, n, dfn[f1], dfn[va]));
		va = fa[f1];
		f1 = top[va];
	}
	if(dep[va] > dep[vb])
		swap(va, vb);
	ans = max(ans, qmax(1, 1, n, dfn[va], dfn[vb]));
	return ans;
}

int getsum(int va, int vb) {
	int ans = 0, f1 = top[va], f2 = top[vb];
	while(f1 != f2) {
		if(dep[f1] < dep[f2])
			swap(va, vb), swap(f1, f2);
		ans += qsum(1, 1, n, dfn[f1], dfn[va]);
		va = fa[f1];
		f1 = top[va];
	}
	if(dep[va] > dep[vb])
		swap(va, vb);
	ans += qsum(1, 1, n, dfn[va], dfn[vb]);
	return ans;
}

void init() {
	clk = cnt = 0;
	root = 1;
	memset(head, -1, sizeof(head));
	for(int i = 1; i < n; ++i) {
		scanf("%d%d", &a, &b);
		add(a, b); add(b, a);
	}
	for(int i = 1; i <= n; ++i)
		scanf("%d", &val[i]);
	dfs1(1, 0, 0);
	dfs2(1, 1);
	build(1, 1, n);
}

void solve() {
	scanf("%d", &m);
	while(m--) {
		scanf("%s%d%d", ch, &a, &b);
		if(ch[0] == 'C') {
			update(1, 1, n, dfn[a], b);
		}
		else if(ch[1] == 'S')
			printf("%d\n", getsum(a, b));
		else
			printf("%d\n", getmax(a, b));
	}
}


void change(int va, int vb, int val) {
    int f1 = top[va], f2 = top[vb], ans = 0;
    while(f1 != f2) {
        if(dep[f1] < dep[f2]) 
            swap(va, vb), swap(f1, f2);
        update(1, 1, n, dfn[f1], dfn[va], val);
        va = fa[f1];
        f1 = top[va];
    }
    if(dep[va] > dep[vb]) swap(va, vb);
    return update(1, 1, n, dfn[va], dfn[vb], val);
}


int main() {
	while(~scanf("%d", &n)) {
		init();
		solve();
	}
	return 0;
}