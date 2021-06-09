#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n, q, x, p, ll, rr;
int a[N], nl, nr, l[N], r[N];
long long suml[N], sumr[N];
int lazy[N << 2], sum[N << 2];

void pushup(int rt) {
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void build(int rt, int l, int r) {
	lazy[rt] = -1;
	if(l == r) {
		sum[rt] = a[l] > x;
		return;
	}
	int mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	pushup(rt);
} 

void pushdown(int rt, int l, int r) {
	if(lazy[rt] != -1) {
		int mid = l + r >> 1;
		lazy[rt << 1] = lazy[rt];
		lazy[rt << 1 | 1] = lazy[rt];
		sum[rt << 1] = lazy[rt] * (mid - l + 1);
		sum[rt << 1 | 1] = lazy[rt] * (r - mid);
		lazy[rt] = -1;
	}
}

int query(int rt, int l, int r, int L, int R) {
	if(L <= l && r <= R)
		return sum[rt];
	int mid = l + r >> 1, ans = 0;
	pushdown(rt, l, r);
	if(mid >= L)
		ans += query(rt << 1, l, mid, L, R);
	if(mid < R)
		ans += query(rt << 1 | 1, mid + 1, r, L, R);
	return ans;
}

void update(int rt, int l, int r, int L, int R, int val) {
	if(L <= l && r <= R) {
		sum[rt] = val * (r - l + 1);
		lazy[rt] = val;
		return;
	}
	int mid = l + r >> 1;
	pushdown(rt, l, r);
	if(mid >= L)
		update(rt << 1, l, mid, L, R, val);
	if(mid < R)
		update(rt << 1 | 1, mid + 1, r, L, R, val);
	pushup(rt);
}

int main() {
	scanf("%d%d%d", &n, &q, &x);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		if(a[i] <= x)
			l[++nl] = a[i];
		else
			r[++nr] = a[i];
	}
	for(int i = 1; i <= nl; ++i)
		suml[i] = suml[i - 1] + l[i];
	for(int i = 1; i <= nr; ++i)
		sumr[i] = sumr[i - 1] + r[i];
	build(1, 1, n);
	while(q--) {
		scanf("%d%d%d", &p, &ll, &rr);
		if(p == 2) {
			int cnt = query(1, 1, n, ll, rr);
			if(cnt != 0)
				update(1, 1, n, rr - cnt + 1, rr, 1);
			if(cnt != rr - ll + 1)
				update(1, 1, n, ll, rr - cnt, 0);
		}
		else if(p == 3) {
			int cnt = query(1, 1, n, ll, rr);
			if(cnt != rr - ll + 1)
				update(1, 1, n, ll + cnt, rr, 0);
			if(cnt != 0)
				update(1, 1, n, ll, ll + cnt - 1, 1);
		}
		else {
			int cnt = query(1, 1, n, 1, rr), cntpre = 0;
			if(ll != 1)
				cntpre = query(1, 1, n, 1, ll - 1);
			printf("%lld\n", sumr[cnt] - sumr[cntpre] + suml[rr - cnt] - suml[ll - 1 - cntpre]);
		}
	}
	return 0;
}