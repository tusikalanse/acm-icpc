#include <bits/stdc++.h>
using namespace std;

double dp[210][210][410], pr[210], ans = 0;
int n, l, k, v[210];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> l >> k;
	dp[0][0][k + 200] = 1;
	for(int i = 1; i <= n; ++i) {
		cin >> pr[i];
		pr[i] /= 100;
	}
	for(int i = 1; i <= n; ++i)
		cin >> v[i];
	for(int i = 0; i < n; ++i)
		for(int j = 0; j <= i; ++j)
			for(int p = 0; p <= 400; ++p) {
				dp[i + 1][j][p] += dp[i][j][p] * (1 - pr[i + 1]);
				dp[i + 1][j + 1][min(400, p + v[i + 1])] += dp[i][j][p] * pr[i + 1];
			}
	for(int i = l; i <= n; ++i)
		for(int p = 200; p <= 400; ++p)
			ans += dp[n][i][p];
	cout << setprecision(15) << ans << endl;
	return 0;
}