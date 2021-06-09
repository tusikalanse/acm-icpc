#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 3e5 + 10;

struct tree {
	LL sum, rmx, lmx, mx;
}sgt[N << 2];

int c[N], d[N], diff[N], a, n, l[N], r[N];
long long ans;

void pushup(int rt) {
	sgt[rt].sum = sgt[rt << 1].sum + sgt[rt << 1 | 1].sum;
	sgt[rt].mx = max(sgt[rt << 1].mx, sgt[rt << 1 | 1].mx);
	sgt[rt].lmx = max(sgt[rt << 1].lmx, sgt[rt << 1].sum + sgt[rt << 1 | 1].lmx);
	sgt[rt].rmx = max(sgt[rt << 1 | 1].rmx, sgt[rt << 1 | 1].sum + sgt[rt << 1].rmx);
	sgt[rt].mx = max(sgt[rt].mx, sgt[rt << 1].rmx + sgt[rt << 1 | 1].lmx);
}

void build(int rt, int l, int r) {
	if(l == r) {
		sgt[rt].sum = sgt[rt].lmx = sgt[rt].rmx = sgt[rt].mx = c[l];
		return;
	}
	int mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	pushup(rt);
}

tree query(int rt, int l, int r, int L, int R) {
	if(L <= l && r <= R) return sgt[rt];
	int mid = l + r >> 1;
	if(R <= mid) return query(rt << 1, l, mid, L, R);
	if(L > mid)  return query(rt << 1 | 1, mid + 1, r, L, R);
	tree u = query(rt << 1, l, mid, L, R), v = query(rt << 1 | 1, mid + 1, r, L, R), o;
	o.sum = u.sum + v.sum;
	o.mx = max(u.mx, v.mx);
	o.mx = max(o.mx, u.rmx + v.lmx);
	o.lmx = max(u.lmx, u.sum + v.lmx);
	o.rmx = max(v.rmx, v.sum + u.rmx);
	return o;
}

struct node {
	int val, id;
};

int main() {
	scanf("%d %d", &n, &a);
	for(int i = 1; i <= n; ++i) {
		scanf("%d%d", &d[i], &c[i]);
		c[i] = a - c[i];
		ans = max(ans, 1LL * c[i]);
	}
	for(int i = 1; i < n; ++i)
		diff[i] = d[i + 1] - d[i];
	build(1, 1, n);
	stack<node> stk;
	stk.push({(int)1e9, 0});
	for(int i = 1; i < n; ++i) {
		while(stk.top().val <= diff[i])
			stk.pop();
		l[i] = stk.top().id + 1;
		stk.push({diff[i], i});
	}
	while(!stk.empty()) stk.pop();
	stk.push({(int)1e9, n});
	for(int i = n - 1; i; --i) {
		while(stk.top().val <= diff[i])
			stk.pop();
		r[i] = stk.top().id;
		stk.push({diff[i], i});
	}
	for(int i = 1; i < n; ++i) {
		ans = max(ans, query(1, 1, n, l[i], r[i]).mx - 1LL * diff[i] * diff[i]);
	}
	printf("%lld\n", ans);
	return 0;
}