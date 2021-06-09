#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int head[N], pnt[N << 1], nxt[N << 1], cnt = 0;
double ans = 0;

void add(int u, int v) {
	pnt[cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt++;
}

void dfs(int u, int f, int d) {
	ans += 1.0 / d;
	for(int i = head[u]; ~i; i = nxt[i]) {
		if(pnt[i] == f)
			continue;
		dfs(pnt[i], u, d + 1);
	}
}

int main() {
	memset(head, -1, sizeof(head));
	int n, u, v;
	scanf("%d", &n);
	for(int i = 2; i <= n; ++i) {
		scanf("%d %d", &u, &v);
		add(u, v);
		add(v, u);
	}
	dfs(1, 0, 1);
	printf("%.10f\n", ans);
	return 0;
}