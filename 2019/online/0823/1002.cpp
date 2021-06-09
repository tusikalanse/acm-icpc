#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int T, n, m, ans;
int a[N], p[N];
int op, x, y;
int sum[N << 2], mxpos[N << 2];

void pushup(int rt) {
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
	mxpos[rt] = max(mxpos[rt << 1], mxpos[rt << 1 | 1]);
}

void build(int rt, int l, int r) {
	if(l == r) {
		sum[rt] = 1;
		mxpos[rt] = p[l];
		return;
	}
	int mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	pushup(rt);
}

void update(int rt, int l, int r, int pos) {
	if(l == r) {
		sum[rt] = 0;
		return;
	}
	int mid = l + r >> 1;
	if(pos <= mid)
		update(rt << 1, l, mid, pos);
	else
		update(rt << 1 | 1, mid + 1, r, pos);
	pushup(rt);
}
bool f, ff;
int tans;

void find(int rt, int l, int r) {
	if(l == r) {
		if(mxpos[rt] > x || sum[rt] == 0) {
			ff = 1;
			tans = l;
		}
		return;
	}
	int mid = l + r >> 1;
	if(mxpos[rt << 1] > x || sum[rt << 1] != mid - l + 1)
		find(rt << 1, l, mid);
	else
		find(rt << 1 | 1, mid + 1, r);
}

void query(int rt, int l, int r, int L, int R) {
	if(L <= l && r <= R) {
		if(sum[rt] != r - l + 1 || mxpos[rt] > x) {
			f = 1;
			find(rt, l, r);
		}
		return;
	}
	int mid = l + r >> 1;
	if(L <= mid) 
		query(rt << 1, l, mid, L, R);
	if(R > mid && f == 0) 
		query(rt << 1 | 1, mid + 1, r, L, R);
}

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			p[a[i]] = i;
		}
		ans = 0;
		build(1, 1, n);
		while(m--) {
			scanf("%d%d", &op, &x);
			if(op == 1) {
				x ^= ans;
				if(a[x] != -1) {
					update(1, 1, n, a[x]);
					a[x] = -1;
				}
			}
			else {
				scanf("%d", &y);
				x ^= ans; y ^= ans;
				f = ff = 0;
				query(1, 1, n, y, n);
				if(f && ff) {
					printf("%d\n", ans = tans);
				}
				else 
					printf("%d\n", ans = n + 1);
			}
		}
	}
	return 0;
}