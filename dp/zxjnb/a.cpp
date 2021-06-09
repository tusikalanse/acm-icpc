#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 10;
const int mod = 1e9 + 7;

int n;
long long bin[MAXN], ans, dp[MAXN], x, cnt[MAXN];


int main() {
	bin[0] = 1;
	for(int i = 1; i < MAXN; ++i) {
		cnt[i] = cnt[i ^ (i & -i)] + 1;
		bin[i] = bin[i - 1] * 2 % mod;
	}
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%lld", &x);
		dp[x]++;
	}
	for(int j = 0; j < 20; ++j)
		for(int i = 0; i < MAXN; ++i)
			if(i & (1 << j))
				dp[i ^ (1 << j)] += dp[i];
	for(int i = 0; i < MAXN; ++i)
		if(cnt[i] & 1)	
			ans = (ans + mod - (bin[dp[i]] - 1)) % mod;
		else
			ans = (ans + mod + (bin[dp[i]] - 1)) % mod;
	printf("%lld\n", ans);
	return 0;
}