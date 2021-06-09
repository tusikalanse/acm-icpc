#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int mx[N << 3], lazy[N << 3];

void pushup(int rt) {
	mx[rt] = max(mx[rt << 1], mx[rt << 1 | 1]);
}

void pushdown(int rt) {
	if(lazy[rt]) {
		lazy[rt << 1] += lazy[rt];
		lazy[rt << 1 | 1] += lazy[rt];
		mx[rt << 1] += lazy[rt];
		mx[rt << 1 | 1] += lazy[rt];
		lazy[rt] = 0;
	}
}

void update(int rt, int l, int r, int L, int R, int val) {
	if(L <= l && r <= R) {
		lazy[rt] += val;
		mx[rt] += val;
		return;
	}
	pushdown(rt);
	int mid = l + r >> 1;
	if(L <= mid)
		update(rt << 1, l, mid, L, R, val);
	if(R > mid)
		update(rt << 1 | 1, mid + 1, r, L, R, val);
	pushup(rt);
}

struct edge {
	int a, b, h, s;
	edge() {}
	edge(int _a, int _b, int _h, int _s) {
		a = _a;
		b = _b;
		h = _h;
		s = _s;
	}
}e[N << 1];

int x[N << 1], bx[N << 1], n, k, m, ans;

int main() {
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i) {
		int x1, y1;
		scanf("%d%d", &x1, &y1);
		x[i * 2 - 1] = x1;
		x[i * 2] = x1 + k;
		e[i * 2 - 1] = edge(x1, x1 + k, y1, 1);
		e[i * 2] = edge(x1, x1 + k, y1 + k + 1, -1);
	}
	sort(x + 1, x + 2 * n + 1);
	m = unique(x + 1, x + 2 * n + 1) - x - 1;
	sort(e + 1, e + 2 * n + 1, [&](edge &i, edge &j) {return i.h < j.h;});
	for(int i = 1; i <= 2 * n; ++i) {
		int a = lower_bound(x + 1, x + m + 1, e[i].a) - x;
		int b = lower_bound(x + 1, x + m + 1, e[i].b) - x;
		update(1, 1, m, a, b, e[i].s);
		ans = max(ans, mx[1]);
	}
	printf("%d\n", ans);
	return 0;
}