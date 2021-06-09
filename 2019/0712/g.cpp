#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int head[N], pnt[N << 1], nxt[N << 1], val[N << 1], deg[N], cnt, sz[N];
long long dp[N][110], f[110];
int T, n, k, u, v, w, root, cas;

void add(int x, int y, int v) {
	pnt[cnt] = y;
	nxt[cnt] = head[x];
	val[cnt] = v;
	head[x] = cnt++;
}

void dfs(int rt, int fa) {
	sz[rt] = 0;
	if(deg[rt] == 1) {
		sz[rt] = 1;
		dp[rt][0] = dp[rt][1] = 0;
		return;
	}
	dp[rt][0] = 0;
	for(int i = head[rt]; ~i; i = nxt[i]) {
		int j = pnt[i], v = val[i];
		if(j == fa) continue;
		dfs(j, rt);
		for(int ii = 0; ii <= k; ++ii) f[ii] = 1e18;
		for(int x = 0; x <= sz[rt]; ++x) {
			for(int y = 0; y <= sz[j] && x + y <= k; ++y) {
				f[x + y] = min(f[x + y], dp[rt][x] + dp[j][y] + 1LL * v * y * (k - y));
			}
		}
		sz[rt] += sz[j];
		sz[rt] = min(k, sz[rt]);
		for(int x = 0; x <= sz[rt]; ++x)
			dp[rt][x] = f[x];
	}
}


int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &k);
		cnt = 0;
		memset(head, -1, sizeof(int) * (n + 10));
		memset(deg, 0, sizeof(int) * (n + 10));
		for(int i = 1; i < n; ++i) {
			scanf("%d%d%d", &u, &v, &w);
			add(u, v, w);
			add(v, u, w);
			deg[u]++; deg[v]++;
		}
		if(n == 2) {
			if(k == 2) {
				printf("Case #%d: %d\n", ++cas, val[0]);
			}
			else
				printf("Case #%d: 0\n", ++cas);
			continue;
		}
		for(int i = 1; i <= n; ++i) {
			if(deg[i] > 1) {
				root = i;
				break;
			}
		}
		for(int i = 0; i <= n; ++i) {
			for(int j = 0; j <= k; ++j)
				dp[i][j] = 1e18;
		}
		dfs(root, 0);
		printf("Case #%d: %lld\n", ++cas, dp[root][k]);
	}
	return 0;
}