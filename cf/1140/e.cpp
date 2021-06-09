#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10, mod = 998244353;

int n, k, a[N], f[N], aa[N];
long long dp[N << 2], lazy_add[N << 2], lazy_mul[N << 2], ans;

long long qp(long long a, long long n) {
	long long res = 1;
	while(n) {
		if(n & 1)
			res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

void pushup(int rt) {
	dp[rt] = (dp[rt << 1] + dp[rt << 1 | 1]) % mod;
}

void build(int rt, int l, int r) {
	lazy_mul[rt] = 1;
	dp[rt] = 0;
	lazy_add[rt] = 0;
	if(l == r) {
		dp[rt] = aa[l];
		return;
	}
	int mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	pushup(rt);
}

void pushdown(int rt, int l, int r) {
	int mid = l + r >> 1;
	int ll = mid - r + 1, rr = r - mid;
	if(lazy_mul[rt] != 1) {
		lazy_mul[rt << 1] = lazy_mul[rt << 1] * lazy_mul[rt] % mod;
		lazy_add[rt << 1] = lazy_add[rt << 1] * lazy_mul[rt] % mod;
		lazy_mul[rt << 1 | 1] = lazy_mul[rt << 1 | 1] * lazy_mul[rt] % mod;
		lazy_add[rt << 1 | 1] = lazy_add[rt << 1 | 1] * lazy_mul[rt] % mod;
		dp[rt << 1] = dp[rt << 1] * lazy_mul[rt] % mod;
		dp[rt << 1 | 1] = dp[rt << 1 | 1] * lazy_mul[rt] % mod;
		lazy_mul[rt] = 1;
	}
	if(lazy_add[rt] != 0) {
		lazy_add[rt << 1] = (lazy_add[rt << 1] + lazy_add[rt]) % mod;
		lazy_add[rt << 1 | 1] = (lazy_add[rt << 1 | 1] + lazy_add[rt]) % mod;
		dp[rt << 1] = (dp[rt << 1] + lazy_add[rt] * ll % mod) % mod;
		dp[rt << 1 | 1] = (dp[rt << 1 | 1] + lazy_add[rt] * rr % mod) % mod;
		lazy_add[rt] = 0;
	}
}


long long qsum(int rt, int l, int r, int L, int R) {
	if(L <= l && r <= R) {
		return dp[rt];
	}
	pushdown(rt, l, r);
	int mid = l + r >> 1;
	long long ans = 0;
	if(mid >= L)
		ans = (ans + qsum(rt << 1, l, mid, L, R)) % mod;
	if(mid < R)
		ans = (ans + qsum(rt << 1 | 1, mid + 1, r, L, R)) % mod;
	return ans;
}

void update_mul(int rt, int l, int r, int L, int R, int val) {
	if(L <= l && r <= R) {
		lazy_mul[rt] = lazy_mul[rt] * val % mod;
		lazy_add[rt] = lazy_add[rt] * val % mod;
		dp[rt] = dp[rt] * val % mod;
		return;
	}
	pushdown(rt, l, r);
	int mid = l + r >> 1;
	if(mid >= L)
		update_mul(rt << 1, l, mid, L, R, val);
	if(mid < R)
		update_mul(rt << 1 | 1, mid + 1, r, L, R, val);
	pushup(rt);
}


void update_add(int rt, int l, int r, int L, int R, int val) {
	if(L <= l && r <= R) {
		dp[rt] = (dp[rt] + 1LL * val * (r - l + 1) % mod) % mod;
		lazy_add[rt] = (lazy_add[rt] + val) % mod;
		return;
	}
	pushdown(rt, l, r);
	int mid = l + r >> 1;
	if(mid >= L)
		update_add(rt << 1, l, mid, L, R, val);
	if(mid < R)
		update_add(rt << 1 | 1, mid + 1, r, L, R, val);
	pushup(rt);
}

int main() {
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	if(a[1] != -1) {
		aa[a[1]] = 1;
	}
	else {
		for(int i = 1; i <= k; ++i)
			aa[i] = 1;
	}
	build(1, 1, k);
	cout << 1 << " " << qsum(1, 1, k, 1, 1) << endl;
		cout << 2 << " " << qsum(1, 1, k, 2, 2) << endl;
	for(int i = 3; i <= n; i += 2) {
		if(a[i] == -1) {
			long long sum = qsum(1, 1, k, 1, k);
			update_mul(1, 1, k, 1, k, mod - 1);
			update_add(1, 1, k, 1, k, sum);
			update_mul(1, 1, k, 1, k, k - 1);
		}
		else {
			long long sum = qsum(1, 1, k, 1, k) - qsum(1, 1, k, a[i], a[i]);
			update_mul(1, 1, k, 1, k, 0);
			update_add(1, 1, k, a[i], a[i], sum);
		}
		cout << 1 << " " << qsum(1, 1, k, 1, 1) << endl;
		cout << 2 << " " << qsum(1, 1, k, 2, 2) << endl;
	}
	ans = qsum(1, 1, k, 1, k);
	memset(aa, 0, sizeof(aa));
	if(a[2] != -1) {
		aa[a[2]] = 1;
	}
	else {
		for(int i = 1; i <= k; ++i)
			aa[i] = 1;
	}
	build(1, 1, k);
	cout << 1 << " " << qsum(1, 1, k, 1, 1) << endl;
		cout << 2 << " " << qsum(1, 1, k, 2, 2) << endl;
	for(int i = 4; i <= n; i += 2) {
		if(a[i] == -1) {
			long long sum = qsum(1, 1, k, 1, k);
			update_mul(1, 1, k, 1, k, mod - 1);
			update_add(1, 1, k, 1, k, sum);
			update_mul(1, 1, k, 1, k, k - 1);
		}
		else {
			long long sum = qsum(1, 1, k, 1, k) - qsum(1, 1, k, a[i], a[i]);
			update_mul(1, 1, k, 1, k, 0);
			update_add(1, 1, k, a[i], a[i], sum);
		}
		cout << 1 << " " << qsum(1, 1, k, 1, 1) << endl;
		cout << 2 << " " << qsum(1, 1, k, 2, 2) << endl;
	}
	ans = qsum(1, 1, k, 1, k) * ans % mod;
	printf("%lld\n", ans);
	return 0;
}