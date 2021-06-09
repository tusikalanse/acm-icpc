#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20010;
int size[MAXN], mx[MAXN], vis[MAXN];
int head[MAXN << 1], val[MAXN << 1], nxt[MAXN << 1], pnt[MAXN << 1], cnt;
int num[3], mn, n, ans;

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
	for(int i = head[rt]; ~i; i = nxt[i]) {
		int j = pnt[i];
		if(vis[j] || j == pre) continue;
		dfsdis(j, rt, d + val[i]);
	}
}

int calc(int rt, int d) {
	num[0] = num[1] = num[2] = 0;
	dfsdis(rt, 0, d);
	return num[0] * num[0] + 2 * num[1] * num[2];
}

void solve(int rt) {
	mn = n;
	int root;
	dfssize(rt, 0);
	dfsroot(rt, 0, size[rt], root);
	vis[root] = 1;
	ans += calc(root, 0);
	for(int i = head[root]; ~i; i = nxt[i]) {
		int j = pnt[i];
		if(vis[j]) continue;
		ans -= calc(j, val[i]);
		solve(j);
	}
}

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	scanf("%d", &n);
	int x, y, v;
	memset(head, -1, sizeof(head));
	for(int i = 1; i < n; ++i) {
		scanf("%d%d%d", &x, &y, &v);
		add(x, y, v);
		add(y, x, v);
	}
	solve(1);
	int tot = n * n, g = gcd(tot, ans);
	ans /= g;
	tot /= g;
	printf("%d/%d\n", ans, tot);
}