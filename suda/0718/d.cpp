#include <bits/stdc++.h>
using namespace std;
#define LL long long

LL check(LL n) {
	LL k = 2;
	LL ans = 0;
	for(; k * k * k <= n; ++k) {
		ans += n / (k * k * k);
	}
	return ans;
} 

int main() {
	LL m;
	cin >> m;
	LL l = 1, r = 1e18, mid, ans = -1;
	while(l <= r) {
		mid = l + r >> 1;
		if(check(mid) < m)
			l = mid + 1;
		else if(check(mid) > m)
			r = mid - 1;
		else {
			ans = mid;
			r = mid - 1;
		}
	}
	cout << ans << endl;
	return 0;
}