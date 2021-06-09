#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 10;

int T, n, sum[N << 2], a[N], cas;
char com[8];

void pushup(int rt) {
	sum[rt] = sum[rt * 2] + sum[rt * 2 + 1];
}

void build(int rt, int l, int r) {
	if (l == r) {
		sum[rt] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(rt * 2, l, mid);
	build(rt * 2 + 1, mid + 1, r);
	pushup(rt);
}

int query(int rt, int l, int r, int ql, int qr) {
	if (ql <= l && r <= qr)
		return sum[rt];
	int mid = (l + r) / 2, ans = 0;
	if (ql <= mid)
		ans += query(rt * 2, l, mid, ql, qr);
	if (qr > mid)
		ans += query(rt * 2 + 1, mid + 1, r, ql, qr);
	return ans;
}

void update(int rt, int l, int r, int pos, int val) {
	if (l == r) {
		sum[rt] += val;
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
	scanf("%d", &T);
	while (T--) {
		printf("Case %d:\n", ++cas);
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
			scanf("%d", &a[i]);
		build(1, 1, n);
		while (scanf("%s", com)) {
			if (com[0] == 'E') break;
			int i, j;
			scanf("%d%d", &i, &j);
			if (com[0] == 'Q') 
				printf("%d\n", query(1, 1, n, i, j));
			else if (com[0] == 'A')
				update(1, 1, n, i, j);
			else if (com[0] == 'S')
				update(1, 1, n, i, -j);
		}
	}
	return 0;
}