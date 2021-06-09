#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
	int dp[250][250], c[250], dp2[250][250];
	int T, n;
	scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++) {
		scanf("%d", &n);
		memset(dp, 0, sizeof(dp));
		memset(dp2, 0, sizeof(dp2));
		for(int i = 1; i <= n; i++) {
			dp[i][i] = 1;
			dp2[i][i] = 1;
			scanf("%d", &c[i]);
		}
		// for(int j = 1; j < n; j++) {
		// 	for(int i = 1; i + j <= n; i++) {
		// 		dp[i][i + j] = dp[i+1][i+j] + 1;
		// 		for(int k = i + 1; k <= i + j; k++)
		// 			if(c[i] == c[k])
		// 				dp[i][i+j] = min(dp[i][i+j], dp[i][k-1] + dp[k+1][i+j]);
		// 	}
		// }
		for(int j = 1; j < n; j++) {
			for(int i = 1; i + j <= n; i++) {
				dp2[i][i + j] = dp2[i][i+j-1] + 1;
				for(int k = i; k < i + j; k++)
					if(c[i+j] == c[k])
						dp2[i][i+j] = min(dp2[i][i+j], dp2[i][k-1] + dp2[k+1][i+j]);
			}
		}
		//printf("Case %d: %d\n", cas, dp[1][n]);
		printf("Case %d: %d\n", cas, dp2[1][n]);
	}


	return 0;
}