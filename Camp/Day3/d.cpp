#include <bits/stdc++.h>
using namespace std;

const int N = 16, MAXN = (1 << 14) + 10;

long long dp[MAXN][N];
int g[N][N], n, m, a, b, v, cnt[MAXN], mp[MAXN];

inline int lowbit(int x) {
	return x & -x;
}

int main() {
	cnt[0] = 0;
	for(int i = 0; i < 14; ++i) 
		mp[1 << i] = i;
	for(int i = 1; i < (1 << 14); ++i)
		cnt[i] = cnt[i >> 1] + (i & 1);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i) {
		scanf("%d%d%d", &a, &b, &v);
		a--, b--;
		g[a][b] = g[b][a] = v;
	}
	int tot = 1 << n;
	memset(dp, -1, sizeof(dp));
	for(int i = 0; i < n; ++i)
		dp[1 << i][i] = 0;
	for(int p = 0; p < tot; ++p) if(cnt[p] > 1) {
		for(int p1 = p & (p - 1); p1; p1 = (p1 - 1) & p) {
			int p2 = p ^ p1;
			for(int pp1 = p1; pp1; pp1 ^= lowbit(pp1)) {
				int i = mp[lowbit(pp1)];
				if(dp[p1][i] == -1) continue;
				for(int pp2 = p2; pp2; pp2 ^= lowbit(pp2)) {
					int j = mp[lowbit(pp2)];
					if(dp[p2][j] == -1)
						continue;
					if(g[i][j] != 0) {
						dp[p][i] = max(dp[p][i], dp[p1][i] + dp[p2][j] + 1LL * g[i][j] * cnt[p2] * (n - cnt[p2]));
					}
				}
			}
		}
	}
	long long ans = 0;
	for(int i = 0; i < n; ++i) {
		ans = max(ans, dp[tot - 1][i]);
	}
	printf("%lld\n", ans);
	return 0;
}