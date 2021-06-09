#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e5 + 10;

struct node {
	int l, r;
	bool operator<(const node &rhs) const {
		return l < rhs.l;
	}
}lis[N];

int tree[N << 2], n, m, k, a, b;
long long sum[N];

void pushup(int rt) {
	tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
}

void build(int n) {
	memset(tree, 0, n * 4LL * sizeof(int));
}

void update(int rt, int l, int r, int pos) {
	if(l == r) {
		tree[rt]++;
		return;
	}
	int mid = l + r >> 1;
	if(pos <= mid)
		update(rt << 1, l, mid, pos);
	else
		update(rt << 1 | 1, mid + 1, r, pos);
	pushup(rt);
}

int query(int rt, int l, int r, int k) {
	if(l == r) 
		return l;
	int mid = l + r >> 1;
	if(tree[rt << 1 | 1] < k)
		return query(rt << 1, l, mid, k - tree[rt << 1 | 1]);
	return query(rt << 1 | 1, mid + 1, r, k);
}

int main() {
	while(~scanf("%d%d%d", &n, &k, &m)) {
		build(n);
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &a);
			sum[i] = sum[i - 1] + a;
		}
		for(int i = 1; i <= m; ++i) 
			scanf("%d%d", &lis[i].l, &lis[i].r);
		sort(lis + 1, lis + m + 1);
		for(int i = 1; i <= k - 1; ++i) 
			update(1, 1, n, lis[i].r);
		long long ans = 0;
		for(int i = k; i <= m; ++i) {
			update(1, 1, n, lis[i].r);
			int pos = query(1, 1, n, k);
			if(pos >= lis[i].l) {
				ans = max(ans, sum[pos] - sum[lis[i].l - 1]);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}