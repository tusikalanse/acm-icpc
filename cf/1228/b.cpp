#include <bits/stdc++.h>
using namespace std;

const int N = 1010, mod = 1e9 + 7;

int n, m, G[N][N], ans = 1, c[N], r[N];

int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) cin >> r[i];
	for(int i = 1; i <= m; ++i) cin >> c[i];
	memset(G, -1, sizeof(G));
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= r[i]; ++j)
			G[i][j] = 1;
		G[i][r[i] + 1] = 0;
	}
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= c[i]; ++j) {
			if(G[j][i] == 0) ans = 0;
			G[j][i] = 1;
		}
		if(G[c[i] + 1][i] == 1) ans = 0;
		G[c[i] + 1][i] = 0;
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			if(G[i][j] == -1) {
				ans = ans * 2LL % mod;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}