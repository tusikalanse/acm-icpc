#include <bits/stdc++.h>
using namespace std;

const int N = 1010, mod = 1e9 + 7;

int dp[N], p[N], n;


int main() {
	cin >> n;
	for(int i = 1; i <= n; ++i) 
		cin >> p[i];
	dp[1] = 2;
	for(int i = 2; i <= n; ++i) {
		int cnt = 2;
		for(int j = p[i]; j < i; ++j)
			cnt = (cnt + dp[j]) % mod;
		dp[i] = cnt;
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		ans = (ans + dp[i]) % mod;
	}
	cout << ans << endl;
	return 0;
}