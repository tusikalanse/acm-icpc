#include <bits/stdc++.h>
using namespace std;

const int N = 310;

string s[N];
int dp[N][N], eq[N][N];

int main() {
	int n;
	cin >> n;
	int all = n - 1;
	for(int i = 0; i < n; ++i) {
		cin >> s[i];
		all += s[i].size();
	}
	for(int i = 0; i < n; ++i) {
		eq[i][i] = 1;
		for(int j = 0; j < i; ++j)
			eq[i][j] = eq[j][i] = s[i] == s[j];
	}
	memset(dp, 0, sizeof(dp));
	for(int i = n - 1; i >= 0; --i) {
		for(int j = n - 1; j >= 0; --j) {
			if(eq[i][j]) {
				if(i + 1 < n && j + 1 < n) {
					dp[i][j] = dp[i + 1][j + 1] + 1;
				}
				else 
					dp[i][j] = 1;
			}
		}
	}
	int ans = all;
	for(int i = 0; i < n; ++i) {
		int sum = 0;
		for(int j = 0; i + j < n; ++j) {
			sum += s[i + j].size();
			int cnt = 1;
			for(int pos = i + j + 1; pos < n; ++pos) {
				if(dp[i][pos] > j) {
					cnt++;
					pos += j;
				}
			}
			int cur = all - sum * cnt + cnt;
			if(cnt > 1 && ans > cur)
				ans = cur;
		}
	}
	printf("%d\n", ans);
	return 0;
}