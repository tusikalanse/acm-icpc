#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int n, a[N], dp[N], pos[N];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		pos[a[i]] = i;
		dp[a[i]] = 1;
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		ans = max(ans, dp[a[i]]);
		for(int j = a[i] << 1; j <= a[n]; j += a[i]) if(pos[j]) {
			dp[j] = max(dp[j], dp[a[i]] + 1);
		}
	}
	printf("%d\n", ans);
	return 0;
}