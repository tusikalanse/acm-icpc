#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e5 + 10;

struct Point {
	int x, y, a, b;
	bool operator<(const Point &rhs) const {
		if(x == rhs.x) return y > rhs.y;
		return x < rhs.x;
	}
}p[N];
int n, b[N];
LL lazy[N << 2], mx[N << 2];

void pushup(int rt) {
	mx[rt] = max(mx[rt << 1], mx[rt << 1 | 1]);
}

void pushdown(int rt) {
	if(lazy[rt]) {
		lazy[rt << 1] += lazy[rt];
		mx[rt << 1] += lazy[rt];
		lazy[rt << 1 | 1] += lazy[rt];
		mx[rt << 1 | 1] += lazy[rt];
		lazy[rt] = 0;
	}
}

void build(int rt, int l, int r) {
	mx[rt] = lazy[rt] = 0;
	if(l == r)
		return;
	int mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
}

void update(int rt, int l, int r, int pos, LL val) {
	if(l == r) {
		mx[rt] = val;
		return;
	}
	int mid = l + r >> 1;
	pushdown(rt);
	if(pos <= mid)
		update(rt << 1, l, mid, pos, val);
	else
		update(rt << 1 | 1, mid + 1, r, pos, val);
	pushup(rt);
}

void update(int rt, int l, int r, int L, int R, LL val) {
	if(L <= l && r <= R) {
		mx[rt] += val;
		lazy[rt] += val;
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

LL query(int rt, int l, int r, int L, int R) {
	if(L <= l && r <= R)
		return mx[rt];
	pushdown(rt);
	int mid = l + r >> 1;
	LL ans = -1e18;
	if(L <= mid)
		ans = max(ans, query(rt << 1, l, mid, L, R));
	if(R > mid)
		ans = max(ans, query(rt << 1 | 1, mid + 1, r, L, R));
	return ans;
}

int main() {
	while(~scanf("%d", &n)) {
		for(int i = 1; i <= n; ++i) {
			scanf("%d%d%d%d", &p[i].x, &p[i].y, &p[i].a, &p[i].b);
			b[i] = p[i].y;
		}
		sort(p + 1, p + n + 1);
		b[n + 1] = 0;
		sort(b + 1, b + n + 2);
		int m = unique(b + 1, b + n + 2) - b - 1;
		build(1, 1, m);
		for(int i = 1; i <= n; ++i) {
			int y = lower_bound(b + 1, b + m + 1, p[i].y) - b;
			LL r = query(1, 1, m, 1, y);
			update(1, 1, m, y, r + p[i].b);
			if(y > 1) {
				update(1, 1, m, 1, y - 1, p[i].a);
			}
			if(y < m) {
				update(1, 1, m, y + 1, m, p[i].b);
			}
		}
		printf("%lld\n", query(1, 1, m, 1, m));
	}
	return 0;
}