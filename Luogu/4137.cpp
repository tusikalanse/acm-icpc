#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

struct {
	int l, r, mn;
}pst[N * 40];
int root[N], cnt, a[N], n, m, x, y;

void pushUp(int rt) {
	pst[rt].mn = min(pst[pst[rt].l].mn, pst[pst[rt].r].mn);
}

void init() {
	cnt = 0;
	root[0] = 0;
	pst[0].l = pst[0].r = pst[0].mn = 0;
}

void update(int &rt, int l, int r, int pos, int val) {
	pst[++cnt] = pst[rt];
	rt = cnt;
	if(l == r) {
		pst[rt].mn = val;
		return;
	} 
	int mid = l + r >> 1;
	if(pos <= mid)
		update(pst[rt].l, l, mid, pos, val);
	else
		update(pst[rt].r, mid + 1, r, pos, val);
	pushUp(rt);
}

int query(int right, int left, int l, int r) {
	if(l == r)
		return l;
	int mid = l + r >> 1;
	if(pst[pst[right].l].mn >= left)
		return query(pst[right].r, left, mid + 1, r);
	else
		return query(pst[right].l, left, l, mid);
}

int main() {
	init();
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		if(a[i] >= n)
			a[i] = n - 1;
		root[i] = root[i - 1];
		update(root[i], 1, n + 1, a[i] + 1, i);
	}
	while(m--) {
		scanf("%d%d", &x, &y);
		printf("%d\n", query(root[y], x, 1, n + 1) - 1);
	}

	return 0;
}