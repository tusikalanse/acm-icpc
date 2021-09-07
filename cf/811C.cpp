#include <bits/stdc++.h>
using namespace std;

const int N = 5010;
int n, dp[N], l[N], r[N], a[N], val[N], vis[N];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		if(l[a[i]] == 0)
			l[a[i]] = i;
		r[a[i]] = i;
	}
	for(int i = 1; i <= n; ++i) {
		int res = dp[i - 1];
		memset(vis, 0, sizeof(vis));
		int t = 0, f = i;
		for(int j = i; j; --j) {
			int x = a[j];
			if(r[x] > i) break;
			f = min(f, l[x]);
			if(!vis[x]) {
				vis[x] = 1;
				t ^= x;
			}
			if(f == j) {
				res = max(res, dp[j - 1] + t);
			}
		}
		dp[i] = res;
	}
	printf("%d\n", dp[n]);
	return 0;
}