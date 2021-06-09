#include <cstdio>
#define max(a, b) (a > b) ? a : b

int dp[1005], a[1005];

int main() { 
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int n, ans = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
        dp[i] = 1;
		scanf("%d", &a[i]);
	}
	for(int i = 2; i <= n; i++) {
		for(int j = 1; j < i; j++) {
			if(a[j] < a[i]) 
				dp[i] = max(dp[i], dp[j] + 1);
		}
		ans = max(ans, dp[i]);
	}
	printf("%d\n", ans);
	return 0;
}
