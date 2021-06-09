#include <bits/stdc++.h>
using namespace std;

const int BIT = 22, MAXN = (1 << BIT) + 10, all = (1 << BIT) - 1;

int a[MAXN >> 2], dp[MAXN];


int main() {
	int n, x;
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &x);
		a[i] = x;
		dp[all ^ x] = x;
	}
	for(int i = 0; i < BIT; ++i) {
		for(int j = 0; j < MAXN; ++j) if(-1 == dp[j]) {
			if(!((1 << i) & j))
				dp[j] = dp[j ^ (1 << i)];
		}
	}
	for(int i = 1; i <= n; ++i)
		printf("%d%c", dp[a[i]], " \n"[i == n]);
	return 0;
}