#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
long long sum[N][4], ans, tmp, pos[4];
long long a[N], dp[N][4];
int n;
char s[N];
vector<int> f[4];

int main() {
	scanf("%d%s", &n, s + 1);
	for(int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
	}
	memset(pos, -1, sizeof(pos));
	for(int i = 1; i <= n; ++i) {
		if(s[i] == 'h') {
			pos[0] = i;
			break;
		}
	}
	if(pos[0] == -1) {
		puts("0");
		return 0;
	}
	for(int i = 1; i < pos[0]; ++i) {
		s[i] = 'p';
		a[i] = 0;
	}
	for(int i = n; i > 0; --i) {
		if(s[i] == 'd') {
			pos[3] = i;
			break;
		}
	}
	if(pos[3] == -1 || pos[3] < pos[0]) {
		puts("0");
		return 0;
	}
	for(int i = pos[3] + 1; i <= n; ++i) {
		s[i] = 'p';
		a[i] = 0;
	}
	for(int i = pos[1] + 1; i < pos[3]; ++i) {
		if(s[i] == 'a') {
			pos[1] = i;
			break;
		}
	}
	if(pos[1] == -1) {
		puts("0");
		return 0;
	}
	for(int i = pos[0] + 1; i < pos[1]; ++i) {
		if(s[i] != 'h')
			a[i] = 0;
		else {
			a[pos[0]] += a[i];
			a[i] = 0;
		}
		s[i] = 'p';
	}
	for(int i = pos[3] - 1; i > pos[1]; --i) {
		if(s[i] == 'r') {
			pos[2] = i;
			break;
		}
	}
	if(pos[2] == -1) {
		puts("0");
		return 0;
	}
	for(int i = pos[2] + 1; i < pos[3]; ++i) {
		if(s[i] != 'd')
			a[i] = 0;
		else {
			a[pos[3]] += a[i];
			a[i] = 0;
		}
		s[i] = 'p';
	}
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = 0;
	for(int i = 1; i <= n; ++i) {
		if(s[i] == 'h') {
			dp[i][0] = min(dp[i][0], dp[i - 1][0] + a[i]);
			for(int j = 1; j < 4; ++j) 
				for(int k = 0; k <= j; ++k)
					dp[i][j] = min(dp[i][j], dp[i - 1][k]);
		}
		else if(s[i] == 'a') {
			for(int j = 0; j < 4; ++j) {
				if(j != 1)
					for(int k = 0; k <= j; ++k)
						dp[i][j] = min(dp[i][j], dp[i - 1][k]);
			}
			dp[i][1] = min(dp[i][1], dp[i - 1][1] + a[i]);
			dp[i][1] = min(dp[i][1], dp[i - 1][0]);
		}
		else if(s[i] == 'r') {
			for(int j = 0; j < 4; ++j) {
				if(j != 2)
					for(int k = 0; k <= j; ++k)
						dp[i][j] = min(dp[i][j], dp[i - 1][k]);
			}
			dp[i][2] = min(dp[i][2], dp[i - 1][2] + a[i]);
			dp[i][2] = min(dp[i][2], dp[i - 1][1]);
			dp[i][2] = min(dp[i][2], dp[i - 1][0]);
		}
		else if(s[i] == 'd') {
			for(int j = 0; j < 4; ++j) {
				if(j != 3)
					for(int k = 0; k <= j; ++k)
						dp[i][j] = min(dp[i][j], dp[i - 1][k]);
			}
			dp[i][3] = min(dp[i][3], dp[i - 1][3] + a[i]);
			dp[i][3] = min(dp[i][3], dp[i - 1][2]);
			dp[i][3] = min(dp[i][3], dp[i - 1][1]);
			dp[i][3] = min(dp[i][3], dp[i - 1][0]);
		}
		else {
			for(int j = 0; j < 4; ++j) {
					for(int k = 0; k <= j; ++k)
						dp[i][j] = min(dp[i][j], dp[i - 1][k]);
			}
		}
	}
	ans = 0x3f3f3f3f3f3f3f3f;
	for(int i = 0; i < 4; ++i)
		ans = min(ans, dp[n][i]);
	printf("%lld\n", ans);
	return 0;
}