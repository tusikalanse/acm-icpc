#include <bits/stdc++.h>
using namespace std;

const int N = 110;

int dp[N][2], d[N], f[N], vis[N], n;
int head[N], nxt[N << 1], pnt[N << 1], cnt, mx, ans;

void add(int x, int y) {
	nxt[cnt] = head[x];
	pnt[cnt] = y;
	head[x] = cnt++;
}

void dfs(int rt, int pre, int &mx) {
	vis[rt] = 1;
	dp[rt][1] = f[rt];
	for(int i = head[rt]; ~i; i = nxt[i]) {
		int j = pnt[i];
		if(vis[j] || j == pre) continue;
		dfs(j, rt, mx);
		dp[rt][0] = max(dp[rt][0], dp[rt][0] + max(dp[j][0], dp[j][1]));
		dp[rt][1] = max(dp[rt][1], dp[rt][1] + max(dp[j][0], dp[j][1] - d[min(rt, j)]));
	}
	mx = max(mx, max(dp[rt][0], dp[rt][1]));
}

int main() {
	memset(head, -1, sizeof(head));
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &f[i]);
		if(i == 1) continue;
		if(i % 2 == 0)
			add(i, i / 2), add(i / 2, i);
		else if(3 * i + 1 <= n)
			add(i, 3 * i + 1), add(3 * i + 1, i);
	}
	for(int i = 1; i <= n; ++i) 
		scanf("%d", &d[i]);
	for(int i = 1; i <= n; ++i) if(!vis[i]) {
		mx = 0;
		dfs(i, 0, mx);
		ans += mx;
	}
	printf("%d\n", ans);
	return 0;
}