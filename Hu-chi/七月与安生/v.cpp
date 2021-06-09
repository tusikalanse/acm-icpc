#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL dp[55][55][55];
int a[55], n, p, sum = 0, mmin = 60;

double permutation(int x) {
	if(x == 0)
		return 1;
	double ans = 1;
	for(int i = 2; i <= x; ++i)
		ans *= i;
	return ans;
}

int main() {
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		sum += a[i];
		mmin = min(mmin, a[i]);
	}
	cin >> p;
	if(sum < p) 
		return 0 * printf("%d\n", n);
	if(mmin > p)
		return 0 * printf("0");
	dp[0][0][0] = 1;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j <= i; ++j) {
			for(int s = 0; s <= p; ++s) {
				dp[i + 1][j][s] += dp[i][j][s];
				if(s + a[i + 1] <= p)
					dp[i + 1][j + 1][s + a[i + 1]] += dp[i][j][s];
			}
		}
	}
	double ans = 0;
	for(int j = 0; j <= n; ++j) {
		for(int s = 0; s <= p; ++s)
			ans += dp[n][j][s] * permutation(j) * permutation(n - j); 
	}
	printf("%.12f\n", ans / permutation(n) - 1);
	return 0;
}