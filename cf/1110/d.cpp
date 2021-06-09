#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int n, m, cnt[N], dp[N][3][3], a;

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a);
		cnt[a]++;
	}
	for(int i = 1; i <= m; ++i) {
		for(int v1 = 0; v1 < 3; ++v1) {
			for(int v2 = 0; v2 < 3; ++v2) {
				for(int v3 = 0; v3 < 3; ++v3) {
					if(v1 + v2 + v3 <= cnt[i]) {
						dp[i][v2][v3] = max(dp[i][v2][v3], dp[i - 1][v1][v2] + v3 + (cnt[i] - v1 - v2 - v3) / 3);
					}
				}
			}
		}
	}
	printf("%d\n", dp[m][0][0]);
	return 0;
}