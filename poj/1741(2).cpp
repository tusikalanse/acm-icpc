#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;

const int N = 1e4 + 10;

int size[N], fa[N], dep[N], vis[N];
int head[N], val[N << 1], pnt[N << 1], nxt[N << 1], cnt;
int n, k, L, R, u, v, l, mn;

void add(int x, int y, int v) {
	pnt[cnt] = y;
	val[cnt] = v;
	nxt[cnt] = head[x];
	head[x] = cnt++;
}

void dfs(int rt, int pre) {
	fa[rt] = pre;
	size[rt] = 1;
	for(int i = head[rt]; ~i; i = nxt[i]) {
		int j = pnt[i];
		if(vis[j] || j == pre) continue;
		dfs(j, rt);
		size[rt] += size[j];
	}
}

void getroot(int rt, int pre, int tot, int &root) {
	int mx = tot - size[rt];
	for(int i = head[rt]; ~i; i = nxt[i]) {
		int j = pnt[i];
		if(j == pre || vis[j]) continue;
		getroot(j, rt, tot, root);
		mx = max(mx, size[j]);
	}
	if(mx < mn) {
		mn = mx;
		root = rt;
	}
}

void getlen(int rt, int pre, int d) {
	dep[R++] = d;
	for(int i = head[rt]; ~i; i = nxt[i]) {
		int j = pnt[i];
		if(j == pre || vis[j]) continue;
		getlen(j, rt, d + val[i]);
	}
}

int calc(int l, int r) {
	sort(dep + l, dep + r);
	int ans = 0, pos = r - 1;
	for(int i = l; i < r; ++i) {
		if(dep[i] > k) break;
		while(pos >= l && dep[i] + dep[pos] > k) pos--;
		ans += pos - l + 1;
		if(pos >= i) ans--;
	}
	return ans >> 1;
}

void init() {
	memset(head, -1, sizeof(head));
	memset(vis, 0, sizeof(vis));
	cnt = 0;
	for(int i = 1; i < n; ++i) {
		scanf("%d%d%d", &u, &v, &l);
		add(u, v, l); add(v, u, l);
	}
}

int solve(int rt) {
	dfs(rt, 0);
	int tot = size[rt], ans = 0, root;
	mn = 0x3f3f3f3f;
	getroot(rt, 0, tot, root);
	vis[root] = 1;
	for(int i = head[root]; ~i; i = nxt[i]) {
		int j = pnt[i];
		if(vis[j]) continue;
		ans += solve(j);
	}
	L = R = 0;
	for(int i = head[root]; ~i; i = nxt[i]) {
		int j = pnt[i];
		if(vis[j]) continue;
		getlen(j, root, val[i]);
		ans -= calc(L, R);
		L = R;
	}
	ans += calc(0, R);
	for(int i = 0; i < R; ++i)
		if(dep[i] <= k) ans++;
		else break;
	vis[root] = 0;
	return ans;
}


int main() {
	while(scanf("%d%d", &n, &k) && n) {
		init();
		printf("%d\n", solve(1));
	}
	return 0;
}