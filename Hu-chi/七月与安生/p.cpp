#include <bits/stdc++.h>
using namespace std;

double dp[100010], p[100010];
double ans = 0;
int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> p[i];
		ans += p[i];
	}
	dp[1] = 0;
	for(int i = 2; i <= n; ++i) {
		dp[i] = (dp[i - 1] + p[i - 1]) * p[i];
		ans += 2 * dp[i];
	}
	cout << fixed << setprecision(15) << ans << endl;
	return 0;
}