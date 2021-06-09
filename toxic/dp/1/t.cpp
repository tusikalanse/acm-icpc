#include <bits/stdc++.h>
using namespace std;

int dp[32][32][52];
int T, n, m, k;
int main() {
	for(int i = 0; i <= 30; ++i) {
		for(int j = 0; j <= 30; ++j) {
			for(int k = 0; k <= 50; ++k) {
				if(k == 0 || k == i * j) {
					dp[i][j][k] = 0;
					continue;
				}
				dp[i][j][k] = 0x3f3f3f3f;
				for(int h = 0; h <= k; ++h) {
					for(int m = 0; m <= j; ++m) 
						dp[i][j][k] = min(dp[i][j][k], dp[i][m][h] + dp[i][j - m][k - h] + i * i);
					for(int m = 0; m <= i; ++m)
						dp[i][j][k] = min(dp[i][j][k], dp[m][j][h] + dp[i - m][j][k - h] + j * j);
				}
			}
		}
	}
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d%d", &n, &m, &k);
		printf("%d\n", dp[n][m][k]);
	}
	return 0;
}