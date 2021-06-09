#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, mod = 1e9 + 7;

int u, v, k, m, rt, n, q, cnt, num;
int head[N], pnt[N << 1], nxt[N << 1], pre[N][18], l[N], r[N], dep[N], dp[N][310], h[N];
int c[N];

void addedge(int x, int y) {
	pnt[num] = y;
	nxt[num] = head[x];
	head[x] = num++;
}

void dfs(int rt, int fa) {
	dep[rt] = dep[fa] + 1;
	pre[rt][0] = fa;
	l[rt] = ++cnt;
	for(int i = 1; i < 18; ++i) {
		pre[rt][i] = pre[pre[rt][i - 1]][i - 1];
	}
	for(int i = head[rt]; ~i; i = nxt[i]) {
		if(pnt[i] != fa) {
			dfs(pnt[i], rt);
		}
	}
	r[rt] = cnt;
}

int lca(int x, int y) {
	if(dep[x] > dep[y])
		swap(x, y);
	for(int i = 17; ~i; --i) 
		if(dep[pre[y][i]] >= dep[x])
			y = pre[y][i];
	if(x == y)
		return x;
	for(int i = 17; ~i; --i) {
		if(pre[y][i] != pre[x][i]) {
			y = pre[y][i];
			x = pre[x][i];
		}
	}
	return pre[x][0];
}

inline int lowbit(int x) {
	return x & -x;
}

void add(int pos, int val) {
	for(int i = pos; i < N; i += lowbit(i))
		c[i] += val;
}

int sum(int x) {
	int res = 0;
	for(; x; x -= lowbit(x))
		res += c[x];
	return res;
}

int main() {
	memset(head, -1, sizeof(head));
	scanf("%d%d", &n, &q);
	for(int i = 1; i < n; ++i) {
		scanf("%d%d", &u, &v);
		addedge(u, v);
		addedge(v, u);
	}
	dfs(1, 0);
	while(q--) {
		set<int> vis;
		vector<int> points;
		scanf("%d%d%d", &k, &m, &rt);
		for(int i = 1; i <= k; ++i) {
			scanf("%d", &u);
			vis.insert(u);
			points.push_back(u);
			add(l[u], 1);
			add(r[u] + 1, -1);
		}
		int root = sum(l[rt]);
		for(int i = 0; i < k; ++i) {
			int u = points[i], LCA = lca(u, rt);
			h[i + 1] = sum(l[u]) + root - 2 * sum(l[LCA]) + vis.count(LCA) - 1;
		}
		sort(h + 1, h + k + 1);
		dp[0][0] = 1;
		for(int i = 1; i <= k; ++i) {
			for(int j = 1; j <= m; ++j) {
				dp[i][j] = (1LL * dp[i - 1][j] * (j - h[i]) + dp[i - 1][j - 1]) % mod;
			}
		}
		int ans = 0;
		for(int i = 1; i <= m; ++i) 
			ans = (ans + dp[k][i]) % mod;
		printf("%d\n", ans);
		for(auto &u: points) {
			add(l[u], -1);
			add(r[u] + 1, 1);
		}
	}
	return 0;
}