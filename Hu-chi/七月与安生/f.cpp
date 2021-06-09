#include <bits/stdc++.h>
using namespace std;

int son[100010], later[100010], fa[100010];
int head[100010], pnt[100010], nxt[100010], cnt = 0;
double expectation[100010];

int dfs(int n) {
	int ans = 0;
	for(int i = head[n]; ~i; i = nxt[i]) {
		ans += dfs(pnt[i]) + 1;
	}
	return later[n] = ans;
}

void add(int x, int y) {
	pnt[cnt] = y;
	nxt[cnt] = head[x];
	head[x] = cnt++;
}

int main() {
	int n, t;
	memset(head, -1, sizeof(head));
	cin >> n;
	for(int i = 2; i <= n; ++i) {
		cin >> t;
		fa[i] = t;
		add(t, i);
	}
	fa[1] = 0;
	dfs(1);
	expectation[1] = 1;
	for(int i = 2; i <= n; ++i) {
		expectation[i] = expectation[fa[i]] + 1 + 0.5 * (later[fa[i]] - later[i] - 1);
	}
	for(int i = 1; i <= n; ++i)
		printf("%.1f%c", expectation[i], " \n"[i == n]);
	return 0;
}