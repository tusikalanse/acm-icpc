#include <bits/stdc++.h>
using namespace std;


long long n, k, a, b;
long long l, r, ans;


int main() {
	cin >> n >> k;
	l = 0, r = n;
	while(l <= r) {
		long long mid = l + r >> 1;
		a = mid, b = n - a;
		if(a * (a + 1) / 2 - b == k) {
			printf("%lld\n", b);
			return 0;
		}
		else if(a * (a + 1) / 2 - b > k) {
			r = mid - 1;
		}
		else
			l = mid + 1;
	}
	return 0;
}