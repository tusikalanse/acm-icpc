#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;
int fa[N], vis[N];
int a[N], b[N];

int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void unite(int x, int y) {
	int fx = find(x), fy = find(y);
	if(fx != fy)
		fa[fx] = fy;
}

int main() {
	int n, m;
	bool flag = 1;
	scanf("%d%d", &n, &m);
	if(n == 1) {
		puts("Yes");
		return 0;
	}
	for(int i = 1; i <= n; ++i) {
		fa[i] = i;
		vis[i] = 0;
	}
	for(int i = 1; i <= m; ++i) {
		scanf("%d%d", &a[i], &b[i]);
		flag &= (find(a[i]) != find(b[i]));
		vis[a[i]]++;
		vis[b[i]]++;
		unite(a[i], b[i]);
	}
	for(int i = 1; i <= n; ++i) {
		flag &= (vis[i] != 0);
	}
	for(int i = 1; i <= m; ++i) {
		flag &= ((vis[a[i]] < 2) || (vis[b[i]] < 2));
	}
	if(flag)
		puts("Yes");
	else
		puts("No");
	return 0;
}