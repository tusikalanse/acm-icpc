#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

long long dp1[N << 2], ans;
int totx, toty;
int n;

int c[N];
void add(int p) {
	for(; p < N; p += p & -p)
		c[p]++;
}

int sum(int p) {
	int ans = 0;
	for(; p; p -= p & -p)
		ans += c[p];
	return ans;
}

void pushup(int rt) {
	dp1[rt] = dp1[rt << 1] + dp1[rt << 1 | 1];
}

void update(int rt, int l, int r, int pos, int val) {
	if(l == r) {
		dp1[rt] = val;
		return;
	}
	int mid = l + r >> 1;
	if(pos <= mid)
		update(rt << 1, l, mid, pos, val);
	else
		update(rt << 1 | 1, mid + 1, r, pos, val);
	pushup(rt);
}

long long query(int rt, int l, int r, int L, int R) {
	if(L <= l && r <= R) {
		return dp1[rt];
	}
	long long ans = 0;
	int mid = l + r >> 1;
	if(L <= mid)
		ans += query(rt << 1, l, mid, L, R);
	if(R > mid)
		ans += query(rt << 1 | 1, mid + 1, r, L, R);
	return ans;
}

vector<int> pos[N];
struct node {
	int x, y;
}ss[N];
int b[N], m;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d%d", &ss[i].x, &ss[i].y);
		b[i] = ss[i].x;
	}
	sort(b + 1, b + n + 1);
	totx = unique(b + 1, b + n + 1) - b - 1;
	for(int i = 1; i <= n; ++i) {
		ss[i].x = lower_bound(b + 1, b + totx + 1, ss[i].x) - b;
	}
	for(int i = 1; i <= n; ++i) {
		b[i] = ss[i].y;
	}
	sort(b + 1, b + n + 1);
	toty = unique(b + 1, b + n + 1) - b - 1;
	for(int i = 1; i <= n; ++i) {
		ss[i].y = lower_bound(b + 1, b + toty + 1, ss[i].y) - b;
		pos[ss[i].x].push_back(ss[i].y);
	}
	for(int i = 1; i <= 200000; ++i) {
		if(pos[i].empty()) continue;
		sort(pos[i].begin(), pos[i].end());
		ans += query(1, 1, toty, 1, pos[i][pos[i].size() - 1]);
		add(pos[i][pos[i].size() - 1]);
		for(auto v: pos[i]) {
			int c = sum(n) - sum(v - 1);
			update(1, 1, toty, v, c);
		}
	}
	ans += query(1, 1, toty, 1, toty);
	printf("%lld\n", ans);
	return 0;
}