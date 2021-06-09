#include <bits/stdc++.h>
using namespace std;

const int N = 300 * 510, mod = 1e9 + 7;

int dp[N];
int T, n, a[310], cas, tot, ans;

int main() {
	scanf("%d", &T);
	while(T--) {
		tot = 0;
		ans = 0;
		scanf("%d", &n);
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			tot += a[i];
			for(int j = tot; j >= a[i]; --j)
				dp[j] = (dp[j] + dp[j - a[i]]) % mod;
		}
		sort(a + 1, a + n + 1);
		for(int i = 1; i <= n; ++i) {
			for(int j = a[i]; j <= tot; ++j)
				dp[j] = (dp[j] - dp[j - a[i]]) % mod;
			for(int j = max(0, 1 + (tot - 1) / 2 - a[i]); 2 * j <= tot - a[i]; ++j) {
				ans = (ans + dp[j]) % mod;
			}
		}
		printf("%d\n", (ans + mod) % mod);
	}
	return 0;
}