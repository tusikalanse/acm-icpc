#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

const int MAXN = 1005;

int dp[MAXN][MAXN][2];
int sum[MAXN];
int n, v, x;
struct node {
	int x, val;
	bool operator < (const node &rhs) const {
		return x < rhs.x;
	}
}s[MAXN];


int main() {
	while(~scanf("%d %d %d", &n, &v, &x)) {
		memset(dp, 0x3f, sizeof(dp));
		for(int i = 1; i <= n; ++i) {
			scanf("%d %d", &s[i].x, &s[i].val);
		}
		n++;
		s[n].x = x;
		s[n].val = 0;
		sum[0] = 0;
		sort(s + 1, s + n + 1);
		for(int i = 1; i <= n; ++i) {
			sum[i] = sum[i - 1] + s[i].val;
			if(s[i].x == x && s[i].val == 0) {
				//cout << i << endl;
				dp[i][i][0] = dp[i][i][1] = 0;
			}
		}
		for(int len = 2; len <= n; ++len) {
			for(int i = 1; i + len - 1 <= n; ++i) {
				int j = i + len - 1;
				dp[i][j][0] = min(dp[i][j][0], dp[i + 1][j][0] + (s[i + 1].x - s[i].x) * (sum[n] - sum[j] + sum[i]));
				dp[i][j][0] = min(dp[i][j][0], dp[i + 1][j][1] + (s[j].x - s[i].x) * (sum[n] - sum[j] + sum[i]));
				dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][1] + (s[j].x - s[j - 1].x) * (sum[n] - sum[j - 1] + sum[i - 1]));
				dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][0] + (s[j].x - s[i].x) * (sum[n] - sum[j - 1] + sum[i - 1]));
			}
		}
		printf("%d\n", min(dp[1][n][0], dp[1][n][1]) * v);
	}
	return 0;
}