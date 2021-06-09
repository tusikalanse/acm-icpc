#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 10;

int p[N], k[N], n, T, ans[N], now;
int dp[N], vis[N], valid[N], b[N], pre[N], pos[N];

void lis() {
	memset(vis, 0, sizeof(int) * (n + 5));
	now = 0;
	int m = 0;
	for(int i = 1; i <= n; ++i) {
		if(valid[i]) {
			dp[i] = lower_bound(b, b + m + 1, p[i]) - b;
			b[dp[i]] = p[i];
			m = max(m, dp[i]);
			pre[i] = pos[b[dp[i] - 1]];
		}
	}
	int pp = pos[b[m]];
	while(pp) {
		vis[pp] = 1;
		pp = pre[pp];
	}
	now = m;
}

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &p[i]);
			valid[i] = 1;
			pos[p[i]] = i;
		}
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &k[i]);
		}
		lis();
		for(int i = n; i; --i) {
			ans[i] = now;
			valid[k[i]] = 0;
			if(vis[k[i]] == 1) {
				lis();
			}
		}
		for(int i = 1; i <= n; ++i)
			printf("%d%c", ans[i], " \n"[i == n]);
	}
	return 0;
}