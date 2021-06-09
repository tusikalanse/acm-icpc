#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10, INF = 0x3f3f3f3f;

int a[N], T, n, k, m, mx[N << 2];
long long sum[N], b[N];

void pushup(int rt) {mx[rt] = max(mx[rt << 1], mx[rt << 1 | 1]);};

void build(int rt, int l, int r) {
	if(l == r) {mx[rt] = -INF; return;}
	int mid = l + r >> 1;
	build(rt << 1, l, mid); build(rt << 1 | 1, mid + 1, r); pushup(rt);
}

void update(int rt, int l, int r, int pos, int val) {
	if(l == r) {mx[rt] = max(mx[rt], val); return;}
	int mid = l + r >> 1;
	if(pos <= mid) update(rt << 1, l, mid, pos, val); else update(rt << 1 | 1, mid + 1, r, pos, val);
	pushup(rt);
}

int query(int rt, int l, int r, int L, int R) {
	if(L <= l && r <= R) return mx[rt];
	int mid = l + r >> 1, ans = -INF;
	if(L <= mid) ans = max(ans, query(rt << 1, l, mid, L, R));
	if(R > mid) ans = max(ans, query(rt << 1 | 1, mid + 1, r, L, R));
	return ans;
}

bool check(long long delta) {
	build(1, 1, m);
	int pos, tmp;
	pos = lower_bound(b + 1, b + m + 1, 0) - b;
	update(1, 1, m, pos, 0);
	for(int i = 1; i <= n; ++i) {
		pos = lower_bound(b + 1, b + m + 1, sum[i] - delta) - b;
		if(pos <= m) {
			tmp = query(1, 1, m, pos, m) + 1;
			if(tmp >= k) return true;
			pos = lower_bound(b + 1, b + m + 1, sum[i]) - b;
			update(1, 1, m, pos, tmp);
		}
	}
	return false;
}

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &k);
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			sum[i] = sum[i - 1] + a[i];
			b[i] = sum[i];
		}
		b[n + 1] = 0;
		sort(b + 1, b + n + 2);
		m = unique(b + 1, b + n + 2) - b - 1;
		long long L = -2e14, R = 1e9, mid, ans;
		while(L <= R) {
			mid = L + R >> 1;
			if(check(mid)) {
				ans = mid;
				R = mid - 1;
			}
			else
				L = mid + 1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}