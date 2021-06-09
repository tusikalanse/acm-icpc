#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int dp[MAXN][510], n, k, a, b;
int pnt[MAXN << 1], nxt[MAXN << 1], cnt, head[MAXN];
long long ans;

void add(int x, int y) {
	pnt[cnt] = y;
	nxt[cnt] = head[x];
	head[x] = cnt++;
}

void dfs(int u, int pre, int dis) {
	dp[u][0] = 1;
	for(int i = head[u]; ~i; i = nxt[i]) if(pnt[i] != pre) {
		int j = pnt[i];
		dfs(j, u, dis + 1);
		for(int i = 0; i < k; ++i) ans += 1LL * dp[u][i] * dp[j][k - 1 - i];
		for(int i = 1; i < k; ++i) dp[u][i] += dp[j][i - 1];
	}
}

int main() {
	scanf("%d%d", &n, &k);
	memset(head, -1, sizeof(head));
	for(int i = 1; i < n; ++i) {
		scanf("%d%d", &a, &b);
		add(a, b);
		add(b, a);
	}
	dfs(1, 0, 0);
	printf("%lld\n", ans);
	return 0;
}