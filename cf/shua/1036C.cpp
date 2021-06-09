#include <bits/stdc++.h>
using namespace std;

int T, t, cnt;
long long L, R;

long long dp[20][2][4];

long long calc(long long n) {
	if(n == 0) return 0;
	cnt = 1;
	memset(dp, 0, sizeof(dp));
	stack<int> s;
	while(n) {
		s.push(n % 10);
		n /= 10;
	}
	t = s.top();
	s.pop();
	dp[1][0][0] = 1;
	dp[1][0][1] = t - 1;
	dp[1][1][1] = 1;
	while(!s.empty()) {
		cnt++;
		t = s.top();
		s.pop();
		dp[cnt][0][0] = 1;
		dp[cnt][0][1] = dp[cnt - 1][0][1] + (t != 0) * dp[cnt - 1][1][1] + dp[cnt - 1][0][0] * 9;
		dp[cnt][1][1] = (t == 0) * dp[cnt - 1][1][1];
		dp[cnt][0][2] = dp[cnt - 1][0][2] + (t != 0) * dp[cnt - 1][1][2] + dp[cnt - 1][0][1] * 9 + dp[cnt - 1][1][1] * max(0, t - 1);
		dp[cnt][1][2] = (t != 0) * dp[cnt - 1][1][1] + (t == 0) * dp[cnt - 1][1][2];
		dp[cnt][0][3] = dp[cnt - 1][0][3] + (t != 0) * dp[cnt - 1][1][3] + dp[cnt - 1][0][2] * 9 + dp[cnt - 1][1][2] * max(0, t - 1);
		dp[cnt][1][3] = (t != 0) * dp[cnt - 1][1][2] + (t == 0) * dp[cnt - 1][1][3];
	}
	return dp[cnt][0][1] + dp[cnt][1][1] + dp[cnt][0][2] + dp[cnt][1][2] + dp[cnt][0][3] + dp[cnt][1][3];
}


int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%lld%lld", &L, &R);
		printf("%lld\n", calc(R) - calc(L - 1));
	}
	return 0;
}