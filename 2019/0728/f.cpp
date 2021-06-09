#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, mod = 1e9 + 7;

long long sum[N << 2];

void pushup(int rt) {
	sum[rt] = (sum[rt << 1] + sum[rt << 1 | 1]) % mod;
}

void build(int rt, int l, int r) {
	sum[rt] = 0;
	if(l == r) return;
	int mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
}

void update(int rt, int l, int r, int pos, int val) {
	if(l == r) {
		sum[rt] += val;
		sum[rt] %= mod;
		return;
	}
	int mid = l + r >> 1;
	if(pos <= mid)
		update(rt << 1, l, mid, pos, val);
	else
		update(rt << 1 | 1, mid + 1, r, pos, val);
	pushup(rt);
}

long long query(int rt, int l, int r, int L, int R) {
	if(L <= l && r <= R)
		return sum[rt];
	int mid = l + r >> 1; long long ans = 0;
	if(L <= mid) ans += query(rt << 1, l, mid, L, R), ans %= mod;
	if(R > mid) ans += query(rt << 1 | 1, mid + 1, r, L, R), ans %= mod;
	return ans % mod;
}


long long x[N];
int n, m;
long long a[N], b[N], c[N];
long long ans;
int get(long long xx) {
	return upper_bound(x + 1, x + m + 1, xx) - x;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
		x[i] = 2 * a[i] - b[i];
	}
	sort(x + 1, x + n + 1);
	m = unique(x + 1, x + n + 1) - x - 1;
	build(1, 1, m);
	for(int i = 1; i <= n; ++i) {
		long long tmp = b[i] - 2 * a[i];
		int r = get(tmp) - 1;
		if(r != 0)
			ans = (ans + 1LL * c[i] * query(1, 1, m, 1, r) % mod) % mod;
		tmp = 2 * a[i] - b[i];
		r = lower_bound(x + 1, x + m + 1, tmp) - x;
		update(1, 1, m, r, c[i]);
	}
	for(int i = 1; i <= n; ++i) {
		x[i] = 2 * b[i] - a[i];
	}
	sort(x + 1, x + n + 1);
	m = unique(x + 1, x + n + 1) - x - 1;
	build(1, 1, m);
	for(int i = 1; i <= n; ++i) {
		long long tmp = a[i] - 2 * b[i];
		int r = get(tmp) - 1;
		if(r != 0)
			ans = (ans + 1LL * c[i] * query(1, 1, m, 1, r) % mod) % mod;
		tmp = 2 * b[i] - a[i];
		r = lower_bound(x + 1, x + m + 1, tmp) - x;
		update(1, 1, m, r, c[i]);
	}
	for(int i = 1; i <= n; ++i) {
		if(2LL * min(2 * a[i], 2 * b[i]) <= max(2 * a[i], 2 * b[i]))
			ans = (ans + 1LL * c[i] * c[i] % mod) % mod;
	}
	printf("%lld\n", (ans % mod + mod) % mod);
	return 0;
}