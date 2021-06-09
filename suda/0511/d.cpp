#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <utility>
#include <map>
#include <set>
using namespace std;

typedef long long ll;
const int MAXN = 1005;
ll dp[MAXN][MAXN];
int a[MAXN], pos[MAXN], sum[MAXN], cnt[MAXN];
char s[MAXN];

int main() {
	int T, n, nl, nr;
	ll temp;
	scanf("%d", &T);
	while(T--) {
		nl = nr = 0;
		scanf("%d", &n);
		memset(dp, 0, sizeof(dp));
		scanf("%s", s + 1);
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			if(s[i] == '(') {
				pos[++nl] = i;
				cnt[nl] = nr;
			}
			else {
				nr++;
				sum[nr] = sum[nr - 1] + a[i];
			}
		}
		for(int i = nl; i > 0; --i) {
			for(int j = n - (nl - i); j >= pos[i]; --j) {
				temp = 1LL * a[pos[i]] * (sum[cnt[i] + j - pos[i]] - sum[cnt[i]]);
				dp[i][j] = temp + dp[i+1][j+1];
				if(j != n - nl + i)
					dp[i][j] = max(dp[i][j], dp[i][j+1]);
			}
			for(int j = pos[i] - 1; j > pos[i - 1]; --j)
				dp[i][j] = dp[i][j+1];
		}
		ll ans = 0;
		for(int i = 1; i <= n; ++i)
			ans = max(ans, dp[1][i]);
		printf("%lld\n", ans);
	}
	return 0;
}