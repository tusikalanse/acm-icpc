#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 2e6+10;

int dp[45][MAXN+3];
int k[MAXN+3];

int main() {
	int T, n, m, cas = 0;
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &n, &m);
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for(int i = 1; i <= n; i++) {
			scanf("%d", &k[i]);
			for(int j = 0; j <= MAXN; j++) {
				dp[i][j] += dp[i-1][j];
				if(k[i] ^ j < MAXN)
					dp[i][k[i] ^ j] += dp[i-1][j];
			}
		}
		long long ans = 0;
		for(int i = m; i <= MAXN; i++){
			ans += dp[n][i];
		}
		printf("Case #%d: %lld\n", ++cas, ans);
	}
	return 0;
}