#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 10, mod = 1e9 + 7;

int prime[65], ind, inv[65];
long long tot[N << 2], exist[N << 2], lazy[2][N << 2];
int n, q, l, r, x, a[N];
char ss[100];
bool isp(int x) {
	for(int i = 2; i * i <= x; ++i) {
		if(x % i == 0)
			return 0;
	}
	return 1;
}

int qp(int a, int x) {
	int res = 1;
	while(x) {
		if(x & 1)
			res = 1LL * res * a % mod;
		a = 1LL * a * a % mod;
		x >>= 1;
	}
	return res;
}

void pushup(int rt) {
	tot[rt] = tot[rt << 1] * tot[rt << 1 | 1] % mod;
	exist[rt] = exist[rt << 1] | exist[rt << 1 | 1];
}

void build(int rt, int l, int r) {
	lazy[0][rt] = 1;
	lazy[1][rt] = 0;
	if(l == r) {
		tot[rt] = a[l];
		for(int i = 0; i < ind; ++i) {
			if(a[l] % prime[i] == 0)
				exist[rt] |= 1LL << i;
		}
		return;
	}
	int mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	pushup(rt);
}

void pushdown(int rt, int l, int r) {
	if(lazy[0][rt] != 1) {
		int mid = l + r >> 1;
		lazy[0][rt << 1] *= lazy[0][rt];
		lazy[0][rt << 1] %= mod;
		lazy[0][rt << 1 | 1] *= lazy[0][rt];
		lazy[0][rt << 1 | 1] %= mod;
		tot[rt << 1] = tot[rt << 1] * qp(lazy[0][rt], mid - l + 1) % mod;
		tot[rt << 1 | 1] = tot[rt << 1 | 1] * qp(lazy[0][rt], r - mid) % mod;
		lazy[0][rt] = 1;
	}
	if(lazy[1][rt] != 0) {
		lazy[1][rt << 1] |= lazy[1][rt];
		lazy[1][rt << 1 | 1] |= lazy[1][rt];
		exist[rt << 1] |= lazy[1][rt];
		exist[rt << 1 | 1] |= lazy[1][rt];
		lazy[1][rt] = 0;
	}
}

long long calc(int x) {
	long long res = 0;
	for(int i = 0; i < ind; ++i) {
		if(x % prime[i] == 0)
			res |= 1LL << i;
	}
	return res;
}

void update(int rt, int l, int r, int L, int R, int val, long long gp) {
	if(L <= l && r <= R) {
		tot[rt] = tot[rt] * qp(val, r - l + 1) % mod;
		exist[rt] |= gp;
		lazy[0][rt] = lazy[0][rt] * val % mod;
		lazy[1][rt] |= gp;
		return;
	}
	pushdown(rt, l, r);
	int mid = l + r >> 1;
	if(mid >= L) 
		update(rt << 1, l, mid, L, R, val, gp);
	if(mid < R)
		update(rt << 1 | 1, mid + 1, r, L, R, val, gp);
	pushup(rt);
}

pair<long long, long long> query(int rt, int l, int r, int L, int R) {
	if(L <= l && r <= R) 
		return make_pair(tot[rt], exist[rt]);
	pushdown(rt, l, r);
	pair<long long, long long> ans = make_pair(1, 0), tmp;
	int mid = l + r >> 1;
	if(mid >= L) {
		tmp = query(rt << 1, l, mid, L, R);
		ans.first *= tmp.first;
		ans.first %= mod;
		ans.second |= tmp.second;
	}
	if(mid < R) {
		tmp = query(rt << 1 | 1, mid + 1, r, L, R);
		ans.first *= tmp.first;
		ans.first %= mod;
		ans.second |= tmp.second;
	}
	return ans;
}

long long getans(pair<long long, long long> a) {
	for(int i = 0; i < ind; ++i) {
		if(((1LL << i) & a.second) != 0) 
			a.first = a.first * (prime[i] - 1) % mod * inv[i] % mod;
	}
	return a.first;
}

int main() {
	for(int i = 2; i <= 300; ++i) {
		if(isp(i))
			prime[ind++] = i;
	}
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < ind; ++i) {
		inv[i] = qp(prime[i], mod - 2);
	}
	build(1, 1, n);
	while(q--) {
		scanf("%s%d%d", ss, &l, &r);
		if(ss[0] == 'M') {
			scanf("%d", &x);
			update(1, 1, n, l, r, x, calc(x));
		}
		else {
			printf("%lld\n", getans(query(1, 1, n, l, r)));
		}
	}
	return 0;
}