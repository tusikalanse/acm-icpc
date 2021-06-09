#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int faz[N], siz[N], dfn[N], rnk[N], son[N], dep[N], top[N], cnt;
int head[N], nxt[N << 1], val[N << 1], pnt[N << 1], _cnt;
int mx[N << 2], mn[N << 2], sum[N << 2], rev[N << 2], a[N], v[N];
int n, m, x, y, z;
char com[10];

void addEdge(int x, int y, int v) {
	pnt[_cnt] = y;
	val[_cnt] = v;
	nxt[_cnt] = head[x];
	head[x] = _cnt++;
}

void dfs1(int rt, int pre) {
	dep[rt] = dep[pre] + 1;
	faz[rt] = pre;
	siz[rt] = 1;
	son[rt] = -1;
	for(int i = head[rt]; ~i; i = nxt[i]) {
		if(pnt[i] == pre) continue;
		dfs1(pnt[i], rt);
		v[pnt[i]] = val[i];
		siz[rt] += siz[pnt[i]];
		if(son[rt] == -1 || siz[son[rt]] < siz[pnt[i]])
			son[rt] = pnt[i]; 
	}
}

void dfs2(int rt, int t) {
	top[rt] = t;
	dfn[rt] = ++cnt;
	rnk[cnt] = rt;
	a[cnt] = v[rt];
	if(son[rt] == -1)
		return;
	dfs2(son[rt], t);
	for(int i = head[rt]; ~i; i = nxt[i]) {
		if(pnt[i] == faz[rt] || pnt[i] == son[rt]) continue;
		dfs2(pnt[i], pnt[i]);
	}
}

void pushUp(int rt) {
	mx[rt] = max(mx[rt << 1], mx[rt << 1 | 1]);
	mn[rt] = min(mn[rt << 1], mn[rt << 1 | 1]);
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void buildSegTree(int rt, int l, int r) {
	rev[rt] = 0;
	if(l == r) {
		mx[rt] = mn[rt] = sum[rt] = a[l];
		return;
	}
	int mid = l + r >> 1;
	buildSegTree(rt << 1, l, mid);
	buildSegTree(rt << 1 | 1, mid + 1, r);
	pushUp(rt);
}

void pushDown(int rt) {
	if(rev[rt] == 1) {
		sum[rt << 1] *= -1;
		sum[rt << 1 | 1] *= -1;
		swap(mx[rt << 1], mn[rt << 1]);
		swap(mx[rt << 1 | 1], mn[rt << 1 | 1]);
		mx[rt << 1] *= -1;
		mx[rt << 1 | 1] *= -1;
		mn[rt << 1] *= -1;
		mn[rt << 1 | 1] *= -1;
		rev[rt << 1] ^= 1;
		rev[rt << 1 | 1] ^= 1;
		rev[rt] = 0;
	}
}

void modifySegTree(int rt, int l, int r, int pos, int val) {
	if(l == r) {
		mx[rt] = mn[rt] = sum[rt] = val;
		return;
	}
	pushDown(rt);
	int mid = l + r >> 1;
	if(pos <= mid)
		modifySegTree(rt << 1, l, mid, pos, val);
	else
		modifySegTree(rt << 1 | 1, mid + 1, r, pos, val);
	pushUp(rt);
}

void revSegTree(int rt, int l, int r, int L, int R) {
	if(L <= l && r <= R) {
		rev[rt] ^= 1;
		sum[rt] *= -1;
		mn[rt] *= -1;
		mx[rt] *= -1;
		swap(mx[rt], mn[rt]);
		return;
	}
	pushDown(rt);
	int mid = l + r >> 1;
	if(mid >= L)
		revSegTree(rt << 1, l, mid, L, R);
	if(mid < R)
		revSegTree(rt << 1 | 1, mid + 1, r, L, R);
	pushUp(rt);
}

int querySegTreeSum(int rt, int l, int r, int L, int R) {
	if(L <= l && r <= R)
		return sum[rt];
	int mid = l + r >> 1, ans = 0;
	pushDown(rt);
	if(mid >= L)
		ans += querySegTreeSum(rt << 1, l, mid, L, R);
	if(mid < R)
		ans += querySegTreeSum(rt << 1 | 1, mid + 1, r, L, R);
	return ans;
}

int querySegTreeMax(int rt, int l, int r, int L, int R) {
	if(L <= l && r <= R) 
		return mx[rt];
	pushDown(rt);
	int mid = l + r >> 1, ans = -1e9;
	if(mid >= L)
		ans = max(ans, querySegTreeMax(rt << 1, l, mid, L, R));
	if(mid < R)
		ans = max(ans, querySegTreeMax(rt << 1 | 1, mid + 1, r, L, R));
	return ans;
}

int querySegTreeMin(int rt, int l, int r, int L, int R) {
	if(L <= l && r <= R) 
		return mn[rt];
	pushDown(rt);
	int mid = l + r >> 1, ans = 1e9;
	if(mid >= L)
		ans = min(ans, querySegTreeMin(rt << 1, l, mid, L, R));
	if(mid < R)
		ans = min(ans, querySegTreeMin(rt << 1 | 1, mid + 1, r, L, R));
	return ans;
}

int querySum(int a, int b) {
	int ans = 0, va = top[a], vb = top[b];
	while(va != vb) {
		if(dep[va] < dep[vb])
			swap(a, b), swap(va, vb);
		ans += querySegTreeSum(1, 1, n, dfn[va], dfn[a]);
		a = faz[va];
		va = top[a];
	}
	if(a != b) {
		if(dep[a] > dep[b])
			swap(a, b);
		ans += querySegTreeSum(1, 1, n, dfn[a] + 1, dfn[b]);
	}
	return ans;
}

int queryMax(int a, int b) {
	int ans = -1e9, va = top[a], vb = top[b];
	while(va != vb) {
		if(dep[va] < dep[vb])
			swap(a, b), swap(va, vb);
		ans = max(ans, querySegTreeMax(1, 1, n, dfn[va], dfn[a]));
		a = faz[va];
		va = top[a];
	}
	if(a != b) {
		if(dep[a] > dep[b])
			swap(a, b);
		ans = max(ans, querySegTreeMax(1, 1, n, dfn[a] + 1, dfn[b]));
	}
	return ans;
}

int queryMin(int a, int b) {
	int ans = 1e9, va = top[a], vb = top[b];
	while(va != vb) {
		if(dep[va] < dep[vb])
			swap(a, b), swap(va, vb);
		ans = min(ans, querySegTreeMin(1, 1, n, dfn[va], dfn[a]));
		a = faz[va];
		va = top[a];
	}
	if(a != b) {
		if(dep[a] > dep[b])
			swap(a, b);
		ans = min(ans, querySegTreeMin(1, 1, n, dfn[a] + 1, dfn[b]));
	}
	return ans;
}

void reversePath(int a, int b) {
	int va = top[a], vb = top[b];
	while(va != vb) {
		if(dep[va] < dep[vb])
			swap(a, b), swap(va, vb);
		revSegTree(1, 1, n, dfn[va], dfn[a]);
		a = faz[va];
		va = top[a];
	}
	if(a != b) {
		if(dep[a] > dep[b])
			swap(a, b);
		revSegTree(1, 1, n, dfn[a] + 1, dfn[b]);
	}
}

struct {
	int x, y, z;
	void adjust() {
		if(dep[x] > dep[y])
			swap(x, y);
	}
}s[N];


int main() {
	scanf("%d", &n);
	memset(head, -1, sizeof(head));
	for(int i = 1; i < n; ++i) {
		scanf("%d%d%d", &s[i].x, &s[i].y, &s[i].z);
		addEdge(s[i].x, s[i].y, s[i].z);
		addEdge(s[i].y, s[i].x, s[i].z);
	}
	dfs1(0, 0);
	dfs2(0, 0);
	for(int i = 1; i < n; ++i)
		s[i].adjust();
	buildSegTree(1, 1, n);
	scanf("%d", &m);
	while(m--) {
		scanf("%s%d%d", com, &x, &y);
		if(com[0] == 'C') {
			modifySegTree(1, 1, n, dfn[s[x].y], y);
		}
		else if(com[0] == 'N')
			reversePath(x, y);
		else if(com[0] == 'S')
			printf("%d\n", querySum(x, y));
		else if(com[2] == 'X')
			printf("%d\n", queryMax(x, y));
		else
			printf("%d\n", queryMin(x, y));
	}
	return 0;
}