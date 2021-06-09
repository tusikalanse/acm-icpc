#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;

#define ll long long 
const int N = (1 << 13) + 10;

int dp[N][15][15], n, w[15];
bool G[15][15];
ll ways[N][15][15];

void init() {
	memset(dp, -1, sizeof(dp));
	memset(G, 0, sizeof(G));
	memset(ways, 0, sizeof(ways));
}

void DP() {
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if(G[i][j]) {
				dp[(1 << i) | (1 << j)][i][j] = w[i] + w[j] + w[i] * w[j];
				ways[(1 << i) | (1 << j)][i][j] = 1;
			}
		}
	}
	for(int p = 0; p < (1 << n); ++p) {
		for(int i = 0; i < n; ++i) if(p & (1 << i)) {
			for(int j = 0; j < n; ++j) if((p & (1 << j))) {
				if(G[i][j] && dp[p][i][j] != -1) {
					for(int k = 0; k < n; ++k) if(!(p & (1 << k)) && k != i && G[j][k]) {
						int tmp = dp[p][i][j] + w[k] + w[j] * w[k];
						if(G[i][k]) 
							tmp += w[i] * w[j] * w[k];
						if(dp[p | (1 << k)][j][k] < tmp) {
							dp[p | (1 << k)][j][k] = tmp;
							ways[p | (1 << k)][j][k] = ways[p][i][j];
						}
						else if(dp[p | (1 << k)][j][k] == tmp)
							ways[p | (1 << k)][j][k] += ways[p][i][j];
					}
				}
			}
		}
	}
}


int main() {
	int T, m, u, v;
	scanf("%d", &T);
	while(T--) {
		init();
		scanf("%d %d", &n, &m);
		for(int i = 0; i < n; ++i)
			scanf("%d", &w[i]);
		if(n == 1) {
			printf("%d %d\n", w[0], 1);
			continue;
		}
		while(m--) {
			scanf("%d %d", &u, &v);
			u--, v--;
			G[u][v] = G[v][u] = 1;
		}
		DP();
		int p = (1 << n) - 1, mmax = 0;
		ll ans = 0;		
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				if(G[i][j]) {
					if(mmax < dp[p][i][j]) {
						mmax = dp[p][i][j];
						ans = ways[p][i][j];
					}
					else if(mmax == dp[p][i][j]) {
						ans += ways[p][i][j];
					}
				}
			}
		}
		printf("%d %lld\n", mmax, ans / 2);
	}
	return 0;
}