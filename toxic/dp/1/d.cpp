#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
int f[3];
char s[12];
int dp[26][26], n, l;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%s", s);
		l = strlen(s);
		f[0] = s[0] - 'a';
		f[1] = s[l - 1] - 'a';
		f[2] = l;
		for(int j = 0; j < 26; ++j) 
			if(dp[j][f[0]]) 
				dp[j][f[1]] = max(dp[j][f[1]], dp[j][f[0]] + f[2]);
		dp[f[0]][f[1]] = max(dp[f[0]][f[1]], f[2]);
	}
	int ans = 0;
	for(int i = 0; i < 26; ++i) 
		ans = max(ans, dp[i][i]);
	printf("%d\n", ans);
	return 0;
}