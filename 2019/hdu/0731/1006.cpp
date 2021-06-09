#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e4 + 10;

int T, n, m, k, a[N];
int que[N], head, tail;
LL dp[55][N], s[N], ss[N], f[N];

inline LL X(int i) {return s[i];}
inline LL Y(int t, int i) {return dp[t][i] - ss[i] + i * s[i];}

int main() {
	scanf("%d", &T);
	while(T--) {
		LL ans = 0;
		scanf("%d%d%d", &n, &k, &m);
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			s[i] = s[i - 1] + a[i];
			ss[i] = ss[i - 1] + s[i];
			f[i] = 1LL * (n - i + 1) * a[i];
		}
		sort(f + 1, f + n + 1);
		for(int i = n - m + 1; i <= n; ++i)
			ans += f[i];
		memset(dp, 0x3f, sizeof(dp));
		dp[0][0] = 0;
		for(int i = 1; i <= k + 1; ++i) {
			head = tail = 0;
			que[tail++] = 0;
			for(int j = 1; j <= n; ++j) {
				while(head + 1 < tail && (Y(i - 1, que[head + 1]) - Y(i - 1, que[head]) <= j * (X(que[head + 1]) - X(que[head])))) head++;
				dp[i][j] = dp[i - 1][que[head]] + ss[j] - ss[que[head]] - (j - que[head]) * s[que[head]];
				while(head + 1 < tail && (Y(i - 1, que[tail - 1]) - Y(i - 1, que[tail - 2])) * (X(j) - X(que[tail - 1])) >= (Y(i - 1, j) - Y(i - 1, que[tail - 1])) * (X(que[tail - 1]) - X(que[tail - 2]))) tail--;
				que[tail++] = j;
			}
		}	
		ans -= dp[k + 1][n];
		printf("%lld\n", ans);
	}
	return 0;
}