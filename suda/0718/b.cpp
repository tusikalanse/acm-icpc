#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
long long dp[710][710][3][3]; 
int match[710];
char s[710];

void dfs(int l, int r) {
	if(l == r - 1) {
		dp[l][r][0][1] = dp[l][r][0][2] = dp[l][r][1][0] = dp[l][r][2][0] = 1;
	}
	else if(match[l] == r) {
		dfs(l + 1, r - 1);
		for(int i = 0; i < 3; ++i) {
			for(int j = 0; j < 3; ++j) {
				if(i * j || i == j) continue;
				for(int k = 0; k < 3; ++k) {
					for(int p = 0; p < 3; ++p) {
						if(i && i == k) continue;
						if(j && j == p) continue;
						dp[l][r][i][j] += dp[l+1][r-1][k][p];
						dp[l][r][i][j] %= mod;
					}
				} 
			}
		}
	}
	else {
		dfs(l, match[l]);
		dfs(match[l]+1, r);
		for(int i = 0; i < 3; ++i) {
			for(int j = 0; j < 3; ++j) {
				if(i * j || i == j) continue;
				for(int k = 0; k < 3; ++k) {
					for(int p = 0; p < 3; ++p) {
						if(k && k == j) continue;
						dp[l][r][i][p] += dp[l][match[l]][i][j] * dp[match[l]+1][r][k][p];
						dp[l][r][i][p] %= mod;
					}
				}
			}
		}
	}
}


int main() {
	scanf("%s", s);
	int l = strlen(s);
	stack<int> ss;
	for(int i = 0; i < l; ++i) {
		if(s[i] == '(')
			ss.push(i);
		else {
			match[i] = ss.top();
			match[ss.top()] = i;
			ss.pop();
		}
	}
	dfs(0, l - 1);
	long long ans = 0;
	for(int i = 0; i < 3; ++i) 
		for(int j = 0; j < 3; ++j)
			ans += dp[0][l - 1][i][j];
	ans %= mod;
	printf("%lld\n", ans);
	return 0;
}
