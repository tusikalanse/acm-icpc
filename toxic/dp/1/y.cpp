#include <bits/stdc++.h>
using namespace std;

const int N = 707;
int dp[N][N][2], a[N], ok[N][N], n, g[N][N];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) 
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= i; ++j) 
			g[i][j] = g[j][i] = __gcd(a[i], a[j]) > 1;
		ok[i][i] = dp[i][i][0] = dp[i][i][1] = 1;
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = i; j >= 1; --j) {
			for(int k = j; k <= i; ++k) {
				if(dp[j][k][0] && dp[k][i][1]) {
					ok[j][i] = ok[i][j] = 1;
					dp[j - 1][i][1] |= g[k][j - 1];
					dp[j][i + 1][0] |= g[k][i + 1];
				}
			}
		}
	}
	puts(ok[1][n] ? "YES" : "NO");
	return 0;
}