#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
const long long inf = 1e18;

long long mx[N][N], c[N][N], d[N], pre[N][N], suf[N][N], ans, sum[N][N], sd[N];
int T, n, m, cas;

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= m; ++j) {
				scanf("%lld", &c[i][j]);
				c[i][j] = -c[i][j];
				sum[i][j] = sum[i][j - 1] + c[i][j];
			}
		}
		for(int j = 1; j <= m; ++j) {
			scanf("%lld", &d[j]);
			sd[j] = sd[j - 1] + d[j];
		}
		for(int i = 1; i <= n; ++i) {
			mx[i][m + 1] = -inf;
			for(int j = m; ~j; --j) {
				mx[i][j] = max(mx[i][j + 1], sum[i][j]);
			}
		}
		for(int j = 0; j <= m; ++j) {
			pre[0][j] = suf[n + 1][j] = 0;
			for(int i = 1; i <= n; ++i) 
				pre[i][j] = pre[i - 1][j] + mx[i][j];
			for(int i = n; i; --i)
				suf[i][j] = suf[i + 1][j] + mx[i][j];
		}
		ans = 0;
		for(int low = 0; low <= m; ++low) {
			for(int i = 1; i <= n; ++i)
				ans = max(ans, sd[low] + pre[i - 1][low] + suf[i + 1][low] + sum[i][low]);
		}
		printf("Case #%d: %lld\n", ++cas, ans);
	}
	return 0;
}