#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[110][110], diaosi[110], sum[110];

int main() {
	int T, n;
	scanf("%d", &T);
	for(int cas = 1; cas <= T; ++cas) {
		memset(dp, 0, sizeof(dp));
		memset(sum, 0, sizeof(sum));
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			dp[i][i] = 0;
			scanf("%d", &diaosi[i]);
			sum[i] = sum[i - 1] + diaosi[i];
		}
		for(int i = 1; i < n; i++) {
			dp[i][i + 1] = min(diaosi[i], diaosi[i + 1]);
		}
		for(int len = 3; len <= n; ++len) {
			for(int i = 1; i + len - 1 <= n; ++i) {
				int j = i + len - 1;
				dp[i][j] = 0x3f3f3f3f;
				for(int k = i; k <= j; ++k) {
					dp[i][j] = min(dp[i][j], dp[i+1][k] + dp[k+1][j] + (sum[j] - sum[k]) * (k - i + 1) + diaosi[i] * (k - i));
				}
			}
		}
		printf("Case #%d: %d\n", cas, dp[1][n]);
	}
	return 0;
}