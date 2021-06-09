#include <bits/stdc++.h>
using namespace std;

const int N = 310;

int T, n, m, x, y, w, s, t;

long long G[N][N];

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j)
				G[i][j] = 1e15;
			G[i][i] = 0;
		}
		for(int i = 1; i <= m; ++i) {
			scanf("%d%d%d", &x, &y, &w);
			x++; y++;
			G[x][y] = w;
		}
		for(int k = 1; k <= n; ++k) {
			for(int i = 1; i <= n; ++i) {
				for(int j = 1; j <= n; ++j)
					G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
			}
		}
		for(int ca = 1; ca <= 6; ++ca) {
			scanf("%d%d", &s, &t);
			s++; t++;
			printf("%lld\n", -G[t][s]);
			G[s][t] = min(G[s][t], -G[t][s]);
			for(int i = 1; i <= n; ++i) {
				for(int j = 1; j <= n; ++j)
					G[i][j] = min(G[i][j], G[i][s] + G[s][t] + G[t][j]);
			}
		}
	}
	return 0;
}