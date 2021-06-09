#include <bits/stdc++.h>
using namespace std;


const int MOD = 1e9+7;
int dp[100005], sum[100005], t, k, a, b;

int main(){
	memset(dp, 0, sizeof(dp));
	memset(sum, 0, sizeof(sum));
	scanf("%d %d", &t, &k);
	dp[0] = 1;
	for(int i = 1; i<k; ++i){
		dp[i] = 1;
		sum[i] = sum[i-1] + dp[i];
		sum[i] %= MOD;
	}
	for(int i = k; i<=100000; ++i){
		dp[i] = dp[i-1] + dp[i-k];
		dp[i] %= MOD;
		sum[i] = sum[i-1] + dp[i];
		sum[i] %= MOD;
	}
	while(t--){
		scanf("%d %d", &a, &b);
		printf("%d\n", (sum[b] - sum[a-1] + MOD) % MOD);
	}

	return 0;
}