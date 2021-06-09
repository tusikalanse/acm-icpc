#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

int dp[N], a[N], n, m;

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) 
		scanf("%d", &a[i]);
	for(int i = m + 1; i <= n; ++i) {
		dp[i] = max(dp[i - 1], dp[i - m] + a[i]);
	}
	printf("%d\n", dp[n]);
	return 0;
}