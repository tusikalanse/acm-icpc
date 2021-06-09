#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 10010;

int a[N], pos[N][N >> 1], n, m, T, cas;
int dp[N][N >> 1];

int cost(int i, int j) {
	return (a[j] - a[i]) * (a[j] - a[i]);
}

int main() {
	//cout << 400000 * 8LL * 1024 << endl;
	//cout << sizeof(a) + sizeof(pos) + sizeof(cost) + sizeof(dp) << endl;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; ++i) 
			scanf("%d", &a[i]);
		if(m >= n) {
			printf("Case %d: 0\n", ++cas);
			continue;
		}
		memset(dp, 0x3f, sizeof(dp));
		sort(a + 1, a + n + 1);
		for(int i = 1; i <= n; ++i) {
			dp[i][1] = cost(1, i);
			pos[i][1] = 0;
		}
		for(int j = 2; j <= m; ++j) {
			pos[n + 1][j] = n;
			for(int i = n; i; --i) 
				for(int k = pos[i][j - 1]; k <= pos[i + 1][j]; ++k) 
					if(dp[i][j] > dp[k][j - 1] + cost(k + 1, i)) {
						dp[i][j] = dp[k][j - 1] + cost(k + 1, i);
						pos[i][j] = k;
					}
		}
		printf("Case %d: %d\n", ++cas, dp[n][m]);
	}
	return 0;
}