#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, m, a[N], x, y, op;

long long sum[N << 2], lazy[N << 2], k;

void pushup(int rt, int l, int r) {
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1] + lazy[rt] * (r - l + 1);
}

void build(int rt, int l, int r) {
	lazy[rt] = 0;
	if(l == r) {
		sum[rt] = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	pushup(rt, l, r);
}

void update(int rt, int l, int r, int L, int R, long long val) {
	if(L <= l && r <= R) {
		lazy[rt] += val;
		sum[rt] += val * (r - l + 1);
		return;
	}
	int mid = l + r >> 1;
	if(mid >= L)
		update(rt << 1, l, mid, L, R, val);
	if(mid < R)
		update(rt << 1 | 1, mid + 1, r, L, R, val);
	pushup(rt, l, r);
}

long long query(int rt, int l, int r, int L, int R, long long add) {
	if(L <= l && r <= R)
		return sum[rt] + add * (r - l + 1);
	int mid = l + r >> 1;
	long long ans = 0;
	add += lazy[rt];
	if(mid >= L)
		ans += query(rt << 1, l, mid, L, R, add);
	if(mid < R)
		ans += query(rt << 1 | 1, mid + 1, r, L, R, add);
	return ans;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	build(1, 1, n);
	while(m--) {
		scanf("%d%d%d", &op, &x, &y);
		if(op == 1) {
			scanf("%lld", &k);
			update(1, 1, n, x, y, k);
		}
		else
			printf("%lld\n", query(1, 1, n, x, y, 0));
	}
	return 0;
}