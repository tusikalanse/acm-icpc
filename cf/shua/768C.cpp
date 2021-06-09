#include <bits/stdc++.h>
using namespace std;

int n, k, x, a[100010], dp[2][1030], now, cnt;


int main() {
	scanf("%d%d%d", &n, &k, &x);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		dp[0][a[i]]++;
	}
	now = 0;
	for(int i = 1; i <= k; ++i) {
		now ^= 1;
		cnt = 0;
		memset(dp[now], 0, sizeof(dp[now]));
		for(int v = 0; v < 1024; ++v) {
			if(cnt % 2 == 0) {
				dp[now][v ^ x] += (1 + dp[now ^ 1][v]) / 2;
				dp[now][v] += dp[now ^ 1][v] - (1 + dp[now ^ 1][v]) / 2;
				cnt += dp[now ^ 1][v];
			}
			else {
				dp[now][v ^ x] += (dp[now ^ 1][v]) / 2;
				dp[now][v] += dp[now ^ 1][v] - (dp[now ^ 1][v]) / 2;
				cnt += dp[now ^ 1][v];	
			}
		}
	}
	for(int i = 1023; ~i; --i) {
		if(dp[now][i] != 0) {
			printf("%d ", i);
			break;
		}
	}
	for(int i = 0; i < 1024; ++i) {
		if(dp[now][i] != 0) {
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}