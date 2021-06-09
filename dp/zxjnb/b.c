#include <stdio.h>
#include <string.h>


const int BIT = 15;
const int N = 55;
const int MAXN = (1 << 15) + 10;
const int mod = 1e9;

int dp[(1 << 15) + 10], n, m, T, a[55], ans;

int main() {
	scanf("%d", &T);
	while(T--) {
		ans = 0;
		scanf("%d %d", &n, &m);
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		int mx = 1 << m;
		for(int i = 1; i <= n; ++i)
			scanf("%d", &a[i]);
		for(int i = 1; i <= n; ++i) {
			for(int j = 0; j < mx; j += 2)
				dp[j] ^= dp[j ^ (mx - 1)] ^= dp[j] ^= dp[j ^ (mx - 1)];
			for(int j = 0; j < m; ++j) {
				for(int k = 0; k < mx; ++k) {
					if((~k & (1 << j)))
						dp[k] = (dp[k] + dp[k ^ (1 << j)]) % mod;
				}
			}
			for(int j = 0; j < mx; j += a[i])
				dp[j] = 0;
		}
		for(int i = 0; i < mx; ++i)
			ans = (ans + dp[i]) % mod;
		printf("%d\n", ans);
	}
	return 0;
}