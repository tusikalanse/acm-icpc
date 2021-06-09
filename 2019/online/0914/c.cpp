#include <bits/stdc++.h>
using namespace std;

const int N = 20010;

long long dp[N];
int n, m, a[N], b[N], id;

int main() {
	while(~scanf("%d%d", &n, &m)) {
		memset(dp, 0x3f, sizeof(dp));
		dp[0] = 0;
		for(int i = 1; i <= n; ++i) {
			scanf("%d%d", &a[i], &b[i]);
			for(int j = b[i]; j <= m + 10000; ++j)
				dp[j] = min(dp[j], dp[j - b[i]] + a[i]);
		}
		id = m;
		for(int i = m + 1; i <= m + 10000; ++i) {
			if(dp[i] <= dp[id])
				id = i;
		}
		printf("%lld %d\n", dp[id], id);
	}
	return 0;
}