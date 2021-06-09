#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 2010;
int n, m, tx, ty, T;
int x[N], y[N], w[N], b[N];
vector<int> id[N];
LL ans;

struct tree {
    LL sum, rmx, lmx, mx;
    int tag;
}sgt[N << 2];

void pushup(int rt) {
    sgt[rt].sum = sgt[rt << 1].sum + sgt[rt << 1 | 1].sum;
    sgt[rt].mx = max(sgt[rt << 1].mx, sgt[rt << 1 | 1].mx);
    sgt[rt].lmx = max(sgt[rt << 1].lmx, sgt[rt << 1].sum + sgt[rt << 1 | 1].lmx);
    sgt[rt].rmx = max(sgt[rt << 1 | 1].rmx, sgt[rt << 1 | 1].sum + sgt[rt << 1].rmx);
    sgt[rt].mx = max(sgt[rt].mx, sgt[rt << 1].rmx + sgt[rt << 1 | 1].lmx);
}

void build(int rt, int l, int r) {
	sgt[rt].tag = 0;
    sgt[rt].sum = sgt[rt].lmx = sgt[rt].rmx = sgt[rt].mx = 0;
    if(l == r) {
        return;
    }
    int mid = l + r >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    pushup(rt);
}

void update(int rt, int l, int r, int pos, int val) {
	sgt[rt].tag = 1;
	if(l == r) {
		sgt[rt].mx += val;
        sgt[rt].sum = sgt[rt].lmx = sgt[rt].rmx = sgt[rt].mx;
		return;
	}
	int mid = l + r >> 1;
	if(pos <= mid)
		update(rt << 1, l, mid, pos, val);
	else
		update(rt << 1 | 1, mid + 1, r, pos, val);
	pushup(rt);
}

int main() {
	scanf("%d", &T);
	while(T--) {
		ans = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i) {
			scanf("%d%d%d", &x[i], &y[i], &w[i]);
			b[i] = x[i];
			id[i].clear();
		}
		sort(b + 1, b + n + 1);
		tx = unique(b + 1, b + n + 1) - b - 1;
		for(int i = 1; i <= n; ++i) {
			x[i] = lower_bound(b + 1, b + tx + 1, x[i]) - b;
		}
		for(int i = 1; i <= n; ++i) {
			b[i] = y[i];
		}
		sort(b + 1, b + n + 1);
		ty = unique(b + 1, b + n + 1) - b - 1;
		for(int i = 1; i <= n; ++i) {
			y[i] = lower_bound(b + 1, b + ty + 1, y[i]) - b;
			id[y[i]].push_back(i);
		}
		for(int i = 1; i <= ty; ++i) {
			build(1, 1, tx);
			for(int j = i; j <= ty; ++j) {
				for(auto f : id[j]) {
					update(1, 1, tx, x[f], w[f]);
				}
				ans = max(ans, sgt[1].mx);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}