#include <bits/stdc++.h>
using namespace std;

const int N = 5050;

int dp[N][N], pre[N][N], n, m, T, a, b, c, deg[N], ans;
vector<pair<int, int>> G[N];

void print(int x, int y) {
	if(y != 1)
		print(pre[x][y], y - 1);
	printf("%d%c", x, " \n"[x == n]);
}

int main() {
	scanf("%d%d%d", &n, &m, &T);
	for(int i = 1; i <= m; ++i) {
		scanf("%d%d%d", &a, &b, &c);
		deg[b]++;
		G[a].push_back(make_pair(b, c));
	}
	memset(dp, 0x3f, sizeof(dp));
	queue<int> que;
	que.push(1);
	dp[1][1] = 0;
	for(int i = 2; i <= n; ++i) {
		if(deg[i] == 0)
			que.push(i);
	}
	while(!que.empty()) {
		int u = que.front();
		que.pop();
		for(auto p : G[u]) {
			for(int i = 1; i <= n; ++i) {
				if(dp[u][i] == 0x3f3f3f3f) continue;
				if(dp[u][i] + p.second < dp[p.first][i + 1]) {
					dp[p.first][i + 1] = dp[u][i] + p.second;
					pre[p.first][i + 1] = u;
				}
			}
			if(--deg[p.first] == 0)
				que.push(p.first);
		}
	}
	for(int i = n; i >= 2; --i) {
		if(dp[n][i] <= T) {
			ans = i;
			break;
		}
	}
	printf("%d\n", ans);
	print(n, ans);
	return 0;
}