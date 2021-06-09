#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

long long s[N], d[N], sum[N], l, r;

int n, q;

long long query(long long len) {
	int l = 0, r = n - 1, aa = 0;
	while(l <= r) {
		int mid = l + r >> 1;
		if(d[mid] <= len) {
			aa = mid;
			l = mid + 1;
		}
		else
			r = mid - 1;
	}
	return 1LL * (n - aa) * len + sum[aa];
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%lld", &s[i]);
	}
	sort(s + 1, s + n + 1);
	for(int i = 1; i < n; ++i) {
		d[i] = s[i + 1] - s[i];
	}
	sort(d + 1, d + n);
	for(int i = 1; i < n; ++i)
		sum[i] = d[i] + sum[i - 1];
	scanf("%d", &q);
	while(q--) {
		scanf("%lld%lld", &l, &r);
		r = r - l + 1;
		printf("%lld ", query(r));
	}
	puts("");
	return 0;
}