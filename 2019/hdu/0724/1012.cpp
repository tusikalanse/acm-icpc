#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int mn[N << 2], lazy[N << 2];

void pushdown(int rt) {
	if(lazy[rt]) {
		lazy[rt << 1] += lazy[rt];
		lazy[rt << 1 | 1] += lazy[rt];
		mn[rt << 1] += lazy[rt];
		mn[rt << 1 | 1] += lazy[rt];
		lazy[rt] = 0;
	}
}

void pushup(int rt) {
	mn[rt] = min(mn[rt << 1], mn[rt << 1 | 1]);
}

void build(int rt, int l, int r) {
	lazy[rt] = mn[rt] = 0;
	if(l == r)
		return;
	int mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
}

void update(int rt, int	l, int r, int L, int R, int val) {
	if(L <= l && r <= R) {
		mn[rt] += val;
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

int query(int rt, int l, int r) {
	if(mn[rt] > 0) return 0;
	if(l == r) return l;
	pushdown(rt);
	int mid = l + r >> 1;
	if(mn[rt << 1] == 0)
		return query(rt << 1, l, mid);
	return query(rt << 1 | 1, mid + 1, r);
}

int a[N], n, c, k, ans, i, j, x, y;
vector<int> pos[N];

int main() {
	while(~scanf("%d%d%d", &n, &c, &k)) {
		if(k == 1) {
			for(int i = 1; i <= n; ++i)
				scanf("%*d");
			printf("%d\n", n);
			continue;
		}
		build(1, 1, n);
		ans = 0;
		for(i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			if(pos[a[i]].empty()) {
				update(1, 1, n, 1, i, 1);
				pos[a[i]].push_back(i);
			}
			else {
				x = pos[a[i]].size() - k;
				y = pos[a[i]].back();
				if(x < 0) {
					update(1, 1, n, 1, y, -1);
				}
				else {
					update(1, 1, n, pos[a[i]][x] + 1, y, -1);
				}
				pos[a[i]].push_back(i);
				x = pos[a[i]].size() - k;
				y = pos[a[i]].back();
				if(x < 0) {
					update(1, 1, n, 1, y, 1);
				}
				else {
					update(1, 1, n, pos[a[i]][x] + 1, y, 1);
				}
			}
			j = query(1, 1, n);
			if(j) ans = max(ans, i - j + 1);
		}
		for(int i = 1; i <= c; ++i)
			pos[i].clear();
		printf("%d\n", ans);
	}
	return 0;
}