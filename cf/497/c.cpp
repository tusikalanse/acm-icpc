#include <bits/stdc++.h>
using namespace std;

int dp[100010];
int da[100010];

int main() {
	map<int, int> mp;
	int n, sum, t, ans = 0, q = 0, p, s;
	cin >> n;
	sum = n;
	for(int i = 0; i < n; ++i) {
		cin >> t;
		mp[t]++;
	}
	for(auto it = mp.begin(); it != mp.end(); ++it) {
		dp[q++] = it->second;
	}
	s = q - 2;
	sum -= dp[s + 1];
	memcpy(da, dp, sizeof(dp));
	dp[s + 1] = 0;
	while(s >= 0) {
		p = da[--q];
		while(dp[q]--)
			sum--;
		if(p >= sum) {
			ans += sum;
			break;
		}
		else {
			ans += p;
			while(p--) {
				sum--;
				if(dp[s] <= 0)
					s--;
				--dp[s];
			}
		}
	}
	cout << ans << endl;
	return 0;
}