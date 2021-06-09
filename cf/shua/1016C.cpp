#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 3e5 + 10;

int a[N], b[N], n;
LL ans, tmp, sa[N], sb[N], nsa[N], nsb[N], isa[N], isb[N];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		sa[i] = sa[i - 1] + a[i];
		nsa[i] = nsa[i - 1] + 1LL * i * a[i];
	}
	for(int i = n; i; --i) {
		isa[i] = isa[i + 1] + 1LL * (n - i + 1) * a[i];
	}
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &b[i]);
		sb[i] = sb[i - 1] + b[i];
		nsb[i] = nsb[i - 1] + 1LL * i * b[i];
	}
	for(int i = n; i; --i) {
		isb[i] = isb[i + 1] + 1LL * (n - i + 1) * b[i];
	}
	for(int i = 1; i <= n; ++i) {
		if(i % 2) {
			tmp += 1LL * (2 * i - 1) * a[i];
			ans = max(ans, tmp + nsa[n] - nsa[i] + (i - 1) * (sa[n] - sa[i]) + isb[i] + (n + i - 1) * (sb[n] - sb[i - 1]));
			tmp += 1LL * (2 * i) * b[i];
			ans = max(ans, tmp + nsb[n] - nsb[i] + i * (sb[n] - sb[i]) + (n + i) * (sa[n] - sa[i]) + isa[i + 1]);			
		}
		else {
			tmp += 1LL * (2 * i - 1) * b[i];
			ans = max(ans, tmp + nsb[n] - nsb[i] + (i - 1) * (sb[n] - sb[i]) + isa[i] + (n + i - 1) * (sa[n] - sa[i - 1]));
			tmp += 1LL * (2 * i) * a[i];
			ans = max(ans, tmp + nsa[n] - nsa[i] + i * (sa[n] - sa[i]) + (n + i) * (sb[n] - sb[i]) + isb[i + 1]);
		}
	}
	printf("%lld\n", ans - sa[n] - sb[n]);
	return 0;
}