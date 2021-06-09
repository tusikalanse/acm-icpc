#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int> B[N];

int R[N], a[N], n, m, q, val[N], i, j, k;
int mn[N << 2], cnt, lazy[N << 2];

void build(int rt, int l, int r) {
	if (l == r) {
		mn[rt] = n - R[l] - val[l];
		return;
	}
	int mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	mn[rt] = min(mn[rt << 1], mn[rt << 1 | 1]);
}

void pushdown(int rt) {
	if (lazy[rt]) {
		lazy[rt << 1] += lazy[rt];
		lazy[rt << 1 | 1] += lazy[rt];
		mn[rt << 1] += lazy[rt];
		mn[rt << 1 | 1] += lazy[rt];
		lazy[rt] = 0;
	}
}

void update(int rt, int l, int r, int L, int R, int val) {
	if (L <= l && r <= R) {
		mn[rt] += val;
		lazy[rt] += val;
		return;
	}
	pushdown(rt);
	int mid = l + r >> 1;
	if (L <= mid)
		update(rt << 1, l, mid, L, R, val);
	if (R > mid)
		update(rt << 1 | 1, mid + 1, r, L, R, val);
	mn[rt] = min(mn[rt << 1], mn[rt << 1 | 1]);
}


int main() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		if (a[i] > a[1])
			cnt++;
	}
	for (int i = 1; i <= m; ++i) {
		val[i] = cnt;
		scanf("%d", &R[i]);
		B[i].resize(R[i]);
		for (int j = 0; j < R[i]; ++j) {
			scanf("%d", &B[i][j]);
			if (B[i][j] > a[1]) cnt++;
		}
	}
	build(1, 1, m);
	while (q--) {
		scanf("%d%d%d", &i, &j, &k);
		j--;
		if (i == m) {}
		else if (B[i][j] < a[1] && k > a[1])
			update(1, 1, m, i + 1, m, -1);
		else if(B[i][j] > a[1] && k < a[1])
			update(1, 1, m, i + 1, m, 1);
		if (mn[1] <= 0)
			puts("0");
		else
			puts("1");
		B[i][j] = k;
	}
	return 0;
}