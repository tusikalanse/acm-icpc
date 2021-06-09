#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;

int dp[1005], a[1005];

int main() {
	int n;
	while(~scanf("%d", &n) && n) {
		memset(dp, 0xff, sizeof(dp));
		for(int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		int ans = -INF;
		for(int i = 0; i < n; i++) {
			int tmp = 0;
			for(int j = 0; j < i; j++) {
				if(a[j] < a[i]) {
					tmp = max(tmp, dp[j]);
				}
			}
			dp[i] = tmp + a[i];
			ans = max(ans, dp[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}