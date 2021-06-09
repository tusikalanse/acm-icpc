#include <bits/stdc++.h>
using namespace std;

const int N = 3010;
int a[N], b[N], c[N], dp[N][2], n;

int main() {
	scanf("%d:", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for(int i = 1; i <= n; ++i) scanf("%d", &b[i]);
	for(int i = 1; i <= n; ++i) scanf("%d", &c[i]);
	if(n == 1) {
		printf("%d\n", a[1]);
		return 0;
	}
	dp[1][0] = a[1];
	dp[1][1] = b[1];
	for(int i = 2; i < n; ++i) {
		dp[i][0] = max(dp[i - 1][0] + b[i], dp[i - 1][1] + a[i]);
		dp[i][1] = max(dp[i - 1][0] + c[i], dp[i - 1][1] + b[i]);
	}
	printf("%d\n", max(dp[n - 1][0] + b[n], dp[n - 1][1] + a[n]));
	return 0;
}