#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20010, mod = 1e9 + 7;
int size[MAXN], mx[MAXN], vis[MAXN];
int head[MAXN << 1], val[MAXN << 1], nxt[MAXN << 1], pnt[MAXN << 1], cnt;
int num[3], mn, n, ans[3];
long long sum[3];

void add(int x, int y, int v) {
	val[cnt] = v;
	pnt[cnt] = y;
	nxt[cnt] = head[x];
	head[x] = cnt++;
}

void dfssize(int rt, int pre) {
	size[rt] = 1;
	for(int i = head[rt]; ~i; i = nxt[i]) {
		int j = pnt[i];
		if(vis[j] || j == pre) continue;
		dfssize(j, rt);
		size[rt] += size[j];
	}
}

void dfsroot(int rt, int pre, int tot, int &root) {
	int mx = tot - size[rt];
	for(int i = head[rt]; ~i; i = nxt[i]) {
		int j = pnt[i];
		if(vis[j] || j == pre) continue;
		dfsroot(j, rt, tot, root);
		mx = max(mx, size[j]);
	}
	if(mx < mn) {
		mn = mx; 
		root = rt;
	}
}

void dfsdis(int rt, int pre, int d) {
	num[d % 3]++;
	sum[d % 3] += d;
	sum[d % 3] %= mod;
	for(int i = head[rt]; ~i; i = nxt[i]) {
		int j = pnt[i];
		if(vis[j] || j == pre) continue;
		dfsdis(j, rt, (d + val[i]) % mod);
	}
}

int calc(int rt, int d, int f) {
	num[0] = num[1] = num[2] = 0;
	sum[0] = sum[1] = sum[2] = 0;
	dfsdis(rt, 0, d);
	ans[0] = (ans[0] + f * sum[0] * num[0]) % mod;
	ans[0] = (ans[0] + f * sum[1] * num[2]) % mod;
	ans[0] = (ans[0] + f * sum[2] * num[1]) % mod;
	ans[1] = (ans[1] + f * sum[0] * num[1]) % mod;
	ans[1] = (ans[1] + f * sum[1] * num[0]) % mod;
	ans[1] = (ans[1] + f * sum[2] * num[2]) % mod;
	ans[2] = (ans[2] + f * sum[0] * num[2]) % mod;
	ans[2] = (ans[2] + f * sum[1] * num[1]) % mod;
	ans[2] = (ans[2] + f * sum[2] * num[0]) % mod;
}

void solve(int rt) {
	mn = n;
	int root;
	dfssize(rt, 0);
	dfsroot(rt, 0, size[rt], root);
	vis[root] = 1;
	calc(root, 0, 1);
	for(int i = head[root]; ~i; i = nxt[i]) {
		int j = pnt[i];
		if(vis[j]) continue;
		calc(j, val[i], -1);
		solve(j);
	}
}


int main() {
	while(~scanf("%d", &n)) {
		cnt = 0;
		memset(ans, 0, sizeof(ans));
		int x, y, v;
		memset(head, -1, sizeof(head));
		memset(vis, 0, sizeof(vis));
		for(int i = 1; i < n; ++i) {
			scanf("%d%d%d", &x, &y, &v);
			x++; y++;
			add(x, y, v);
			add(y, x, v);
		}
		solve(1);
		ans[0] = (2 * ans[0]) % mod;
		ans[1] = (2 * ans[1]) % mod;
		ans[2] = (2 * ans[2]) % mod;
		printf("%d %d %d\n", (ans[0] + mod) % mod, (ans[1] + mod) % mod, (ans[2] + mod) % mod);
	}
	return 0;
}