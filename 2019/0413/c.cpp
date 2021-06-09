#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

long long dp[N][N];
int t[N], c[N], x, n, m, tt, a, b;

vector<int> edges[N];

int main() {
	scanf("%d%d%d%d", &x, &n, &m, &tt);
	for(int i = 1; i <= m; ++i) {
		scanf("%d%d", &a, &b);
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	for(int i = 1; i <= n; ++i) {
		scanf("%d%d", &t[i], &c[i]);
	}
	memset(dp, 0x3f, sizeof(dp));
	dp[t[1]][1] = c[1];
	for(int i = t[1]; i < x; ++i) {
		for(int j = 1; j <= n; ++j) {
			if(i + t[j] <= x)
				dp[i + t[j]][j] = min(dp[i + t[j]][j], dp[i][j] + c[j]);
			for(int k : edges[j]) {
				if(i + tt + t[k] > x) continue;
				dp[i + tt + t[k]][k] = min(dp[i + tt + t[k]][k], dp[i][j] + c[k]);
			}
		}
	}
	if(dp[x][1] == 0x3f3f3f3f3f3f3f3f) {
		puts("It is a trap.");
	}
	else 
		printf("%lld\n", dp[x][1]);
	return 0;
}