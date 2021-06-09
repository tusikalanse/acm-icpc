#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int lim = 1e5 + 1;

int mx[N << 2], n, r, x, y;

void update(int rt, int l, int r, int pos, int val) {
	if(l == r) {
		mx[rt] += val;
		return;
	}
	int mid = l + r >> 1;
	if(pos <= mid)
		update(rt << 1, l, mid, pos, val);
	else
		update(rt << 1 | 1, mid + 1, r, pos, val);
	mx[rt] = max(mx[rt << 1], mx[rt << 1 | 1]);
}

vector<int> c[N];

int main() {
	scanf("%d%d", &n, &r);
	for(int i = 1; i <= n; ++i) {
		scanf("%d%d", &x, &y);
		x++, y++;
		c[y].push_back(x);
		if(y - r >= 1)
			c[y - r].push_back(x);
		if(y + r <= lim)
			c[y + r].push_back(x);
		update(1, 1, lim, x, 1);
		if(x - r >= 1)
			update(1, 1, lim, x - r, 1);
		if(x + r <= lim)
			update(1, 1, lim, x + r, 1);
	}
	int ans = 0;
	for(int y = 1; y <= lim; ++y) {
		for(auto i: c[y]) {
			update(1, 1, lim, i, -1);
			if(i - r >= 1)
				update(1, 1, lim, i - r, -1);
			if(i + r <= lim)
				update(1, 1, lim, i + r, -1);
		}
		ans = max(ans, (int)c[y].size() + mx[1]);
		for(auto i: c[y]) {
			update(1, 1, lim, i, 1);
			if(i - r >= 1)
				update(1, 1, lim, i - r, 1);
			if(i + r <= lim)
				update(1, 1, lim, i + r, 1);
		}
	}
	printf("%d\n", ans);
	return 0;
}