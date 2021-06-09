#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;;

int a[N], b[N], vis[N];
vector<int> G[N];
int T, cas, n, m, x, y;
int mx[2], mn[2];


struct node {
	int mn0, mx0;
	int mn1, mx1;
	node() {}
	node(int a, int b, int c, int d) {
		mn0 = a, mx0 = b, mn1 = c, mx1 = d;
		adjust();
	}
	void adjust() {
		if (mn0 > mn1) 
			swap(mn0, mn1), swap(mx0, mx1);
	}
	bool operator<(const node &rhs) const {
		if (mn0 != rhs.mn0) return mn0 < rhs.mn0;
		if (mn1 != rhs.mn1) return mn1 < rhs.mn1;
		return true;
	}
};

vector<node> v;
int suf[N];

bool dfs(int rt, int pre) {
	bool ans = true;
	vis[rt] = vis[pre] ^ 1;
	if (vis[rt] == 0) {
		mn[0] = min(mn[0], a[rt]);
		mx[0] = max(mx[0], a[rt]);
		mn[1] = min(mn[1], b[rt]);
		mx[1] = max(mx[1], b[rt]);
	}
	else {
		mn[0] = min(mn[0], b[rt]);
		mx[0] = max(mx[0], b[rt]);
		mn[1] = min(mn[1], a[rt]);
		mx[1] = max(mx[1], a[rt]);
	}
	for (auto v : G[rt]) {
		if (vis[v] != -1) {
			if (vis[v] == vis[rt]) return false;
		}
		else ans &= dfs(v, rt);
	}
	return ans;
}

bool dfs() {
	for (int i = 1; i <= n; ++i) 
		if (vis[i] == -1) {
			mx[0] = mx[1] = -1e9;
			mn[0] = mn[1] = 11e8;
			if (!dfs(i, 0))
				return false;
			v.push_back(node(mn[0], mx[0], mn[1], mx[1]));
		}
	return true;
}

int gao() {
	sort(v.begin(), v.end());
	int tot = v.size();
	suf[tot] = -1e9;
	for (int i = tot - 1; i >= 0; --i)
		suf[i] = max(suf[i + 1], min(v[i].mx0, v[i].mx1));
	int ans = 1e9, mmn = 1e9, mmx = 0;
	for (int i = 0; i < tot; ++i) {
		if (mmn < v[i].mn0) {
			break;
		}
		ans = min(ans, max(max(suf[i + 1], mmx), v[i].mx0) - v[i].mn0);
		mmn = min(mmn, v[i].mn1);
		mmx = max(mmx, v[i].mx1);
	}
	int maxx = -1e9;
	for (int j = 0; j < tot; ++j) {
		if (v[j].mn0 >= mmn) maxx = max(maxx, min(v[j].mx0, v[j].mx1));
		else maxx = max(maxx, v[j].mx1);
	}
	ans = min(ans, maxx - mmn);
	return ans;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		v.clear();
		scanf("%d%d", &n, &m);
		memset(vis, -1, sizeof(int) * (n + 8));
		vis[0] = 0;
		for (int i = 1; i <= m; ++i) {
			scanf("%d%d", &x, &y);
			G[x].push_back(y);
			G[y].push_back(x);
		}
		for (int i = 1; i <= n; ++i) {
			scanf("%d%d", &a[i], &b[i]);
		}
		printf("Case %d: ", ++cas);
		if (!dfs())
			puts("IMPOSSIBLE");
		else {
			printf("%d\n", gao());
		}
		for (int i = 1; i <= n; ++i) G[i].clear();
	}
	return 0;
}