#include <bits/stdc++.h>
using namespace std;
#define LL long long

int a[100010], b[100010];
int n, m;

LL check(int k) {
	LL ans = 0;
	for(int i = 0; i < n; ++i) {
		if(a[i] < k)
			ans += k - a[i];
	}
	for(int i = 0; i < m; ++i) {
		if(b[i] > k)
			ans += b[i] - k;
	}
	return ans;
} 

int main() {
	scanf("%d %d", &n, &m);
	int mmin = 0x3f3f3f3f, mmax = 0;
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		mmin = min(mmin, a[i]);
		mmax = max(mmax, a[i]);
	}
	for(int i = 0; i < m; ++i) {
		scanf("%d", &b[i]);		
		mmin = min(mmin, b[i]);
		mmax = max(mmax, b[i]);
	}
	int l = mmin, r = mmax, ans = mmin;
	while(l <= r) {
		int h1 = l + (r - l) / 3;
		int h2 = r - (r - l) / 3;
		if(check(h1) < check(h2)) {
			r = h2 - 1;
			ans = h2;
		}
		else {
			l = h1 + 1;
			ans = h1;
		}
	}
	printf("%lld\n", check(ans));
	return 0;
}