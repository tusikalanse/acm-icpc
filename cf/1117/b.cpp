#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n, m, k, mx, cnt, a[N], mx2;
long long ans;


int main() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		mx = max(mx, a[i]);
	}
	for(int i = 1; i <= n; ++i) {
		cnt += mx == a[i];
		if(mx != a[i])
			mx2 = max(mx2, a[i]);
	}
	if(cnt != 1) {
		ans = 1LL * m * mx;
	}
	else {
		cnt = m / (k + 1);
		ans = 1LL * mx * (m - cnt) + 1LL * mx2 * cnt;
	}
	printf("%lld\n", ans);
	return 0;
}