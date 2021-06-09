#include <bits/stdc++.h>
using namespace std;

int T, n, a[110], dp[110][3][3], ans, cas = 0;
//0, -1, +1
int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i)
			scanf("%d", &a[i]);
		sort(a + 1, a + n + 1);
		memset(dp, -0x3f, sizeof(dp));
		ans = dp[1][0][0] = 1;
		dp[1][1][1] = dp[1][1][2] = 1;
		for(int i = 2; i <= n; ++i) {
			dp[i][0][0] = 1;
			dp[i][1][1] = dp[i][1][2] = 1;
			if(a[i] - a[i - 1] <= 2) {
				dp[i][0][0] = max(dp[i][0][0], dp[i - 1][0][0] + 1);
				dp[i][1][0] = max(dp[i][1][0], dp[i - 1][1][0] + 1);
				dp[i][2][0] = max(dp[i][2][0], dp[i - 1][2][0] + 1);
				dp[i][2][1] = max(dp[i][2][1], dp[i - 1][1][1] + 1);
				dp[i][2][2] = max(dp[i][2][2], dp[i - 1][1][2] + 1);
			}
			if(a[i] - a[i - 1] <= 1) {
				dp[i][1][0] = max(dp[i][1][0], dp[i - 1][1][1] + 1);
				dp[i][2][0] = max(dp[i][2][0], dp[i - 1][2][1] + 1);
				dp[i][1][2] = max(dp[i][1][2], dp[i - 1][0][0] + 1);
				dp[i][2][2] = max(dp[i][2][2], dp[i - 1][1][0] + 1);
			}
			if(a[i] - a[i - 1] <= 3) {
				dp[i][1][0] = max(dp[i][1][0], dp[i - 1][1][2] + 1);
				dp[i][2][0] = max(dp[i][2][0], dp[i - 1][2][2] + 1);
				if(a[i] != a[i - 1]) {
					dp[i][1][1] = max(dp[i][1][1], dp[i - 1][0][0] + 1);
					dp[i][2][1] = max(dp[i][2][1], dp[i - 1][1][0] + 1);
				}
			}
			if(a[i] == a[i - 1])
				dp[i][2][2] = max(dp[i][2][2], dp[i - 1][1][1] + 1);
			if(a[i] - a[i - 1] <= 4 && a[i] - a[i - 1] >= 2)
				dp[i][2][1] = max(dp[i][2][1], dp[i - 1][1][2] + 1);
			for(int j = 0; j < 3; ++j)
				for(int k = 0; k < 3; ++k) {
					ans = max(ans, dp[i][j][k]);
					//printf("dp[%d][%d][%d] = %d\n", i, j, k, dp[i][j][k]);
				}
		}
		printf("Case %d: %d\n", ++cas, ans);
	}
	return 0;
}


