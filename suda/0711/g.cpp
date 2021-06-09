#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[50010], b[50010], n, k;

bool check(long long val, int k) {
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		ans += b + n - lower_bound(b, b + n, 1 + (val - 1) / a[i]);
	}
	return ans >= k;
}


int main() {
	long long ans, mid, l, r;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; ++i)
		scanf("%d %d", &a[i], &b[i]);
	sort(a, a + n);
	sort(b, b + n);
	ans = l = 1LL * a[0] * b[0];
	r = 1LL * a[n - 1] * b[n - 1];
	while(l <= r) {
		mid = l + r >> 1;
		if(check(mid, k)) {
			l = mid + 1;
			ans = mid;
		}
		else
			r = mid - 1;
	}
	printf("%lld\n", ans);
	return 0;
}