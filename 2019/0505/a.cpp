#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int a[N], n;

bool check(long long x) {
	long long cnt = 0;
	for(int i = 0; i <= n; ++i) {
		if(i >= x)
			cnt += a[i];
	}
	return cnt >= x;
}

int main() {
	while(~scanf("%d", &n)) {
		long long l = 0, r = n + 1, ans = 0;
		for(int i = 0; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		while(l <= r) {
			long long mid = l + r >> 1;
			if(check(mid)) {
				ans = mid;
				l = mid + 1;
			}
			else
				r = mid - 1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}