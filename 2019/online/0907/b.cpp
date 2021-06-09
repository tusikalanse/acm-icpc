#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 10;

int b[N], op[N], x[N], n, q, m, ans, rnk[N];

int sum[N << 2];

void build(int rt, int l, int r) {
	if(l == r) {
		sum[rt] = 1;
		return;
	}
	int mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
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
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void find(int rt, int l, int r) {
	if(l == r) {
		if(sum[rt] && ans == -1) {
			ans = rnk[l];
		}
		return;
	}
	int mid = l + r >> 1;
	if(sum[rt << 1])
		find(rt << 1, l, mid);
	else
		find(rt << 1 | 1, mid + 1, r);
}

void query(int rt, int l, int r, int L, int R) {
	if(L <= l && r <= R) {
		find(rt, l, r);
		return;
	}
	int mid = l + r >> 1;
	if(L <= mid)
		query(rt << 1, l, mid, L, R);
	if(R > mid)
		query(rt << 1 | 1, mid + 1, r, L, R);
}

int main() {
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= q; ++i) {
		scanf("%d%d", &op[i], &x[i]);
		b[2 * i - 1] = x[i];
		b[2 * i] = min(n, x[i] + 1);
	}
	sort(b + 1, b + 2 * q + 1);
	m = unique(b + 1, b + 2 * q + 1) - b - 1;
	for(int i = 1; i <= m; ++i)
		rnk[i] = b[i];
	build(1, 1, m);
	for(int i = 1; i <= q; ++i) {
		if(op[i] == 1) 
			update(1, 1, m, lower_bound(b + 1, b + m + 1, x[i]) - b);
		else {
			ans = -1;
			query(1, 1, m, lower_bound(b + 1, b + m + 1, x[i]) - b, m);
			printf("%d\n", ans);
		}
	}
	return 0;
}