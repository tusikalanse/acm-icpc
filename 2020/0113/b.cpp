#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n, m, mx[N << 2], a[N];
char com[8];

void pushup(int rt) {
	mx[rt] = max(mx[rt * 2], mx[rt * 2 + 1]);
}

void build(int rt, int l, int r) {
	if (l == r) {
		mx[rt] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(rt * 2, l, mid);
	build(rt * 2 + 1, mid + 1, r);
	pushup(rt);
}

int query(int rt, int l, int r, int ql, int qr) {
	if (ql <= l && r <= qr)
		return mx[rt];
	int mid = (l + r) / 2, ans = -1e9;
	if (ql <= mid)
		ans = max(ans, query(rt * 2, l, mid, ql, qr));
	if (qr > mid)
		ans = max(ans, query(rt * 2 + 1, mid + 1, r, ql, qr));
	return ans;
}

void update(int rt, int l, int r, int pos, int val) {
	if (l == r) {
		mx[rt] = val;
		return;
	}
	int mid = (l + r) / 2;
	if (pos <= mid)
		update(rt * 2, l, mid, pos, val);
	else
		update(rt * 2 + 1, mid + 1, r, pos, val);
	pushup(rt);
}

int main() {
	while (EOF != scanf("%d%d", &n, &m)) {
		for (int i = 1; i <= n; ++i)
			scanf("%d", &a[i]);
		build(1, 1, n);
		while (m--) {
			int A, B;
			scanf("%s%d%d", com, &A, &B);
			if (com[0] == 'Q') 
				printf("%d\n", query(1, 1, n, A, B));
			else if (com[0] == 'U')
				update(1, 1, n, A, B);
		}
	}
	return 0;
}