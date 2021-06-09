#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10, M = 1e7 + 10;
const int LEFT = 0, RIGHT = 1e9 - 1;

int n, l[N], r[N], f[N], g[N];
int sum[M * 3], b[M * 2], c[M * 2];
long long ans;
int	main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) 
		scanf("%d%d", &l[i], &r[i]);
	f[1] = r[1] - l[1] + 1;
	for(int i = 2; i <= n; ++i)
		f[i] = max(0, f[i - 1] - (l[i] - r[i - 1] - 1)) + r[i] - l[i] + 1;
	g[n] = r[n] - l[n] + 1;
	for(int i = n - 1; i; --i)
		g[i] = max(0, g[i + 1] - (l[i + 1] - r[i] - 1)) + r[i] - l[i] + 1;
	for(int i = 1, j; i <= n; i = j + 1) {
		j = i + 1;
		while(j <= n && g[j] + f[j - 1] >= l[j] - r[j - 1] - 1) j++;
		j--;
		int le = max(LEFT, l[i] - g[i] + 1), ri = min(RIGHT, r[j] + f[j] - 1);
		int t = i, mn = RIGHT, mx = LEFT;
		for(int k = le; k <= ri; ++k) {
			if(l[t] <= k && k <= r[t])
				sum[k - le + 1] = sum[k - le] + 1;
			else
				sum[k - le + 1] = sum[k - le] - 1;
			if(k == r[t])
				++t;
			b[sum[k - le + 1] + M]++;
			mx = max(mx, sum[k - le + 1] + M);
			mn = min(mn, sum[k - le + 1] + M);
		}
		for(int k = mx - 1; k >= mn; --k)
			b[k] += b[k + 1];
		ans += b[M + 1];
		for(int k = le; k <= ri; ++k) {
			t = sum[k - le + 1] + M;
			b[t + 1] -= c[t + 1];
			c[t] += c[t + 1] + 1;
			c[t + 1] = 0;
			ans += b[t + 1];
		}
		for(int k = mn; k <= mx; ++k)
			b[k] = c[k] = 0;
	}
	printf("%lld\n", ans);
	return 0;
}
