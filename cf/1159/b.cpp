#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

int a[N], n, l, r, ans;

bool check(int k) {
	for(int i = 1; i <= n; ++i) {
		if(1LL * k * (i - 1) > a[i])
			return false;
		if(1LL * k * (n - i) > a[i])
			return false;
	}
	return true;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) 
		scanf("%d", &a[i]);
	l = 0, r = 1e9, ans = 0;
	while(l <= r) {
		int mid = l + r >> 1;
		if(check(mid)) {
			ans = mid;
			l = mid + 1;
		}
		else
			r = mid - 1;
	}
	printf("%d\n", ans);
	return 0;
}