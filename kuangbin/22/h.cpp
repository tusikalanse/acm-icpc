#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
	char a[110], b[110];
	int dp[110][110], ans[110];
	while(~scanf("%s %s", a, b)) {
		memset(dp, 0, sizeof(dp));
		memset(ans, 0, sizeof(ans));
		int n = strlen(a);
		for(int i = 0; i <= n; ++i)
			dp[i][i] = 1;
		for(int len = 2; len <= n; ++len) {
			for(int i = 0; i < n; ++i) {
				int j = i + len - 1;
				dp[i][j] = dp[i + 1][j] + !(b[i] == b[i + 1] || b[i] == b[j]);
				for(int k = i + 1; k < j; ++k) {
					if(b[i] == b[k])
						dp[i][j] = min(dp[i][j], dp[i + 1][k] + dp[k + 1][j]);
				}
			}
		}
		ans[0] = !(a[0] == b[0]);
		for(int i = 1; i <= n; ++i) {
			if(a[i] == b[i])
				ans[i] = ans[i - 1];
			else {
				ans[i] = dp[0][i];
				for(int j = 0; j < i; ++j)
					ans[i] = min(ans[i], ans[j] + dp[j+1][i]);
			}
		}
		printf("%d\n", ans[n-1]);
	}
	return 0;
}