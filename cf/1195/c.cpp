#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int a[N], b[N], n;
long long ans, dp[N][2], mx[N][2];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &b[i]);
	}
	for(int i = 1; i <= n; ++i) {
		dp[i][0] = mx[i - 1][1] + a[i];
		dp[i][1] = mx[i - 1][0] + b[i];
		mx[i][0] = max(mx[i - 1][0], dp[i][0]);
		mx[i][1] = max(mx[i - 1][1], dp[i][1]);
	}
	printf("%lld\n", max(mx[n][0], mx[n][1]));
	return 0;
}