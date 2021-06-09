#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

int n;
long long a[N];
long long c, remain, ans;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
	}
	for(int i = 1; i <= n; ++i) {
		c = min(remain, a[i] / 2);
		a[i] -= 2 * c;
		ans += c;
		ans += a[i] / 3;
		remain -= c;
		remain += a[i] % 3;
	}
	printf("%lld\n", ans);
	return 0;
}