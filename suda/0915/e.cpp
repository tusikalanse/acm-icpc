#include <bits/stdc++.h>
using namespace std;


const int N = 1e5 + 10;

int fa[N], son[N], size[N], top[N], dfn[N], rnk[N], val[N], dep[N], clk, root;
int head[N], nxt[N << 1], pnt[N << 1], cnt;
unsigned long long sum[N << 2], mul[N << 2], pls[N << 2];
int n, m, a, b, opt;
unsigned long long x;
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
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void build(int rt, int l, int r) {
	sum[rt] = pls[rt] = 0;
	mul[rt] = 1;
	if(l == r) return;
	int mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
}

void pushdown(int rt, int l, int r) {
	if(pls[rt] == 0 && mul[rt] == 1) return;
	int mid = l + r >> 1;
	unsigned long long ll = mid - l + 1, rr = r - mid;
	(sum[rt << 1] *= mul[rt]) += pls[rt] * ll;
	(sum[rt << 1 | 1] *= mul[rt]) += pls[rt] * rr;
	mul[rt << 1] *= mul[rt];
	mul[rt << 1 | 1] *= mul[rt];
	(pls[rt << 1] *= mul[rt]) += pls[rt];
	(pls[rt << 1 | 1] *= mul[rt]) += pls[rt];
	mul[rt] = 1;
	pls[rt] = 0;
}


void pplus(int rt, int l, int r, int L, int R, unsigned long long val) {
	if(val == 0) return;
	if(l >= L && r <= R) {
		sum[rt] += (r - l + 1) * val;
		pls[rt] += val;
		return;
	}
	pushdown(rt, l, r);
	int mid = l + r >> 1;
	if(mid >= L)
		pplus(rt << 1, l, mid, L, R, val);
	if(mid < R)
		pplus(rt << 1 | 1, mid + 1, r, L, R, val);
	pushup(rt);
}

void multy(int rt, int l, int r, int L, int R, unsigned long long val) {
	if(val == 1) return;
	if(l >= L && r <= R) {
		sum[rt] *= val;
		pls[rt] *= val;
		mul[rt] *= val;
		return;
	}
	pushdown(rt, l, r);
	int mid = l + r >> 1;
	if(mid >= L)
		multy(rt << 1, l, mid, L, R, val);
	if(mid < R)
		multy(rt << 1 | 1, mid + 1, r, L, R, val);
	pushup(rt);
}

unsigned long long qsum(int rt, int l, int r, int L, int R) {
	if(L <= l && r <= R) 
		return sum[rt];
	int mid = l + r >> 1;
	pushdown(rt, l, r);
	unsigned long long ans = 0;
	if(mid >= L)
		ans += qsum(rt << 1, l, mid, L, R);
	if(mid < R)
		ans += qsum(rt << 1 | 1, mid + 1, r, L, R);
	return ans;
}

unsigned long long getsum(int va, int vb) {
	unsigned long long ans = 0; 
	int f1 = top[va], f2 = top[vb];
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


void change(int va, int vb, unsigned long long m, unsigned long long p) {
    int f1 = top[va], f2 = top[vb];
    while(f1 != f2) {
        if(dep[f1] < dep[f2]) 
            swap(va, vb), swap(f1, f2);
        // cout << dfn[f1] << " " << dfn[va] << endl;
        pplus(1, 1, n, dfn[f1], dfn[va], p);
        multy(1, 1, n, dfn[f1], dfn[va], m);
        va = fa[f1];
        f1 = top[va];
    }
    if(dep[va] > dep[vb]) swap(va, vb);
    // cout << dfn[va] << " " << dfn[vb] << endl;
    pplus(1, 1, n, dfn[va], dfn[vb], p);
    multy(1, 1, n, dfn[va], dfn[vb], m);
}

void init() {
	clk = cnt = 0;
	memset(head, -1, sizeof(head));
}


int main() {
	while(~scanf("%d", &n)) {
		init();
		for(int i = 2; i <= n; ++i) {
			scanf("%d", &m);
			add(m, i);
			add(i, m);
		}
		dfs1(1, 0, 0);
		dfs2(1, 1);
		build(1, 1, n);
		scanf("%d", &m);
		while(m--) {
			scanf("%d %d %d", &opt, &a, &b);
			if(opt == 1) {
				scanf("%llu", &x);
				change(a, b, x, 0);
			}
			else if(opt == 2) {
				scanf("%llu", &x);
				change(a, b, 1, x);
			}
			else if(opt == 3) {
				change(a, b, 18446744073709551615ULL, 1);
			}
			else ssew 
				printf("%llu\n", getsum(a, b));
		}
	}
	return 0;
}