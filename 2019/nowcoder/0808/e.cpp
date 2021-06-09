#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 10;

int x[N], y[N], A[3], B[3], C[3], M[3], L[N], R[N];
int num[N << 1], tot, n;
long long pre[N << 1], now;

int lazy[N << 3], cnt[N << 3];
long long sum[N << 3];

void pushup(int rt) {
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void pushdown(int rt, int l, int r) {
	int mid = l + r >> 1;
	if(lazy[rt]) {
		lazy[rt << 1] += lazy[rt];
		lazy[rt << 1 | 1] += lazy[rt];
		cnt[rt << 1] += lazy[rt];
		cnt[rt << 1 | 1] += lazy[rt];
		sum[rt << 1] += 1LL * (pre[mid] - pre[l - 1]) * lazy[rt];
		sum[rt << 1 | 1] += 1LL * (pre[r] - pre[mid]) * lazy[rt];
		lazy[rt] = 0;
	}
}

void update(int rt, int l, int r, int L, int R) {
	if(L <= l && r <= R) {
		lazy[rt]++; cnt[rt]++;
		sum[rt] += (pre[r] - pre[l - 1]);
		return;
	}
	pushdown(rt, l, r);
	int mid = l + r >> 1;
	if(L <= mid) 
		update(rt << 1, l, mid, L, R);
	if(R > mid)
		update(rt << 1 | 1, mid + 1, r, L, R);
	pushup(rt);
}

int query(int rt, int l, int r, long long k) {
	if(l == r) {
		return num[l] + (k - 1) / cnt[rt];
	}
	pushdown(rt, l, r);
	int mid = l + r >> 1;
	if(sum[rt << 1] < k) return query(rt << 1 | 1, mid + 1, r, k - sum[rt << 1]);
	return query(rt << 1, l, mid, k);
}

int main() {
	cin >> n;
	cin >> x[1] >> x[2] >> A[1] >> B[1] >> C[1] >> M[1];
	cin >> y[1] >> y[2] >> A[2] >> B[2] >> C[2] >> M[2];
	for(int i = 1; i <= n; ++i) {
		if(i >= 3) {
			x[i] = (1LL * A[1] * x[i - 1] + 1LL * B[1] * x[i - 2] + C[1]) % M[1];
			y[i] = (1LL * A[2] * y[i - 1] + 1LL * B[2] * y[i - 2] + C[2]) % M[2];
		}
		L[i] = min(x[i], y[i]) + 1;
		R[i] = max(x[i], y[i]) + 2;
		num[i * 2 - 1] = L[i];
		num[i * 2] = R[i];
	}
	sort(num + 1, num + 2 * n + 1);
	tot = unique(num + 1, num + 2 * n + 1) - num - 1;
	num[tot + 1] = num[tot];
	for(int i = 1; i <= tot; ++i) {
		pre[i] = pre[i - 1] + num[i + 1] - num[i];
	}
	for(int i = 1; i <= n; ++i) {
		L[i] = lower_bound(num + 1, num + tot + 1, L[i]) - num;
		R[i] = lower_bound(num + 1, num + tot + 1, R[i]) - num - 1;
		now += pre[R[i]] - pre[L[i] - 1];
		update(1, 1, tot, L[i], R[i]);
		printf("%d\n", query(1, 1, tot, (now + 1) / 2));
	}
	return 0;
}