#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int a[N], b[N], cnt, vis[N];
int fa[N];

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

bool unite(int x, int y) {
	int fx = find(x), fy = find(y);
	if (fx == fy)
		return false;
	fa[fx] = fy;
	return true;
}

int main() {
	while (scanf("%d%d", &a[0], &b[0])) {
		if (a[0] == -1 && b[0] == -1) break;
		cnt = 1;
		if (a[0] == 0 && b[0] == 0) {
			puts("Yes");
			continue;
		}
		bool ok = true;
		while (scanf("%d%d", &a[cnt], &b[cnt])) {
			if (a[cnt] == 0 && b[cnt] == 0) break;
			cnt++;
		}
		for (int i = 0; i < cnt; ++i) {
			fa[a[i]] = a[i];
			fa[b[i]] = b[i];
		}
		for (int i = 0; i < cnt; ++i) {
			ok &= unite(a[i], b[i]);
		}
		int num = 0;
		for (int i = 0; i < cnt; ++i) {
			if (vis[a[i]] == 0) {
				vis[a[i]] = 1;
				num += a[i] == fa[a[i]];
			}
			if (vis[b[i]] == 0) {
				vis[b[i]] = 1;
				num += b[i] == fa[b[i]];
			}
		}
		if (ok && num == 1) 
			puts("Yes");
		else
			puts("No");
		for (int i = 0; i < cnt; ++i) 
			vis[a[i]] = vis[b[i]] = 0;
	}
	return 0;
}

