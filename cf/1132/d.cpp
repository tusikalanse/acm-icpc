#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 2e5 + 10;

int n, k;
LL a[N], b[N], l, r, ans, mid;
int vis[N];

bool check(LL x) {
	memset(vis, 0, sizeof(vis));
	int cnt = 0;
	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j <= k; ++j) {
			LL t = (j * x + a[i]) / b[i];
			if(t < k - 1) {
				vis[t + 1]++;
				if(++cnt > k)
					return false;
			}
			else
				break;
		}
	}
	for(int t = 1; t <= k; ++t) {
		vis[t] += vis[t - 1];
		if(vis[t] > t)
			return false;
	}
	return true;
}

int main() {
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i) 
		scanf("%lld", &a[i]);
	for(int i = 1; i <= n; ++i) 
		scanf("%lld", &b[i]);
	l = 0, r = 1e18, ans = -1;
	while(l <= r) {
		mid = l + r >> 1;
		if(check(mid)) {
			ans = mid, r = mid - 1;
		}
		else
			l = mid + 1;
	}
	printf("%lld\n", ans);
	return 0;
}