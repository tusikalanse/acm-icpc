#include <bits/stdc++.h>
using namespace std;
#define LL long long

LL dp[1010][6][2];
int a[1010], k, m, n, T;
char s[10];

inline long long opt(long long a, long long b, char op) {
	if(op == '+') 
		return a + b;
	if(op == '-')
		return a - b;
	if(op == '*')
		return a * b;
	if(op == '/')
		return a / b;
}

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d%d", &n, &m, &k);
		for(int i = 1; i <= n; ++i) 
			scanf("%d", &a[i]);
		scanf("%s", s + 1);
		for(int i = 0; i <= n; ++i)
			dp[i][0][0] = dp[i][0][1] = k;
		for(int j = 1; j <= m; ++j) {
			dp[j][j][0] = max(opt(dp[j - 1][j - 1][0], a[j], s[j]), opt(dp[j - 1][j - 1][1], a[j], s[j]));
			dp[j][j][1] = min(opt(dp[j - 1][j - 1][0], a[j], s[j]), opt(dp[j - 1][j - 1][1], a[j], s[j]));
			for(int i = j + 1; i <= n; ++i) {
				dp[i][j][0] = max(dp[i - 1][j][0], max(opt(dp[i - 1][j - 1][0], a[i], s[j]), opt(dp[i - 1][j - 1][1], a[i], s[j])));
				dp[i][j][1] = min(dp[i - 1][j][1], min(opt(dp[i - 1][j - 1][0], a[i], s[j]), opt(dp[i - 1][j - 1][1], a[i], s[j])));
			}
		}
		printf("%lld\n", dp[n][m][0]);
	}
	return 0;
}