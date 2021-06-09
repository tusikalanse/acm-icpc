#include <bits/stdc++.h>
using namespace std;

#define LL long long
const int mod = 1e9 + 7;

LL dp[5010][5010], sum[5010][5010];
int lcp[5010][5010];
char s[5010];
int n;

void pre() {
	for(int i = n; i > 0; --i) 
		for(int j = n; j > 0; --j) 
			lcp[i][j] = s[i] == s[j] ? lcp[i + 1][j + 1] + 1 : 0;
}

bool check(int a, int b, int len) {
	int t = lcp[a][b];
	if(t < len && s[a + t] < s[b + t])
		return 1;
	return 0;
}

void solve() {
	pre();
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= i; ++j) {
            if(s[j] == '0') {
    	        sum[i][j] = sum[i][j - 1] % mod;
            	continue;
            }
            if(j == 1) 
            	dp[i][j] = 1;
            int len = i - j + 1;
            int l = max(j + 1 - len, 1), r = j - 1;
            if(l <= r) 
            	dp[i][j] = (sum[j - 1][r] - sum[j - 1][l - 1]) % mod;
            if(j - len >= 1 && check(j - len, j, len)) {
                dp[i][j] = (dp[i][j] + dp[j - 1][j - len]) % mod;
            }
            sum[i][j] = (sum[i][j - 1] + dp[i][j]) % mod;
		}
	}
	LL ans = 0;
	for(int i = 1; i <= n; ++i)
		ans = (ans + dp[n][i]) % mod;
	printf("%lld\n", (ans + mod) % mod);
}



int main() {
	while(~scanf("%d %s", &n, s + 1))
		solve();	
	return 0;
}