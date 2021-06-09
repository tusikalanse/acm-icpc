#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

int a[N], n, tmp;
long long ans;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; 2 * i <= n; ++i) {
		tmp = a[i] + a[n + 1 - i];
		ans += 1LL * tmp * tmp;
	}
	printf("%lld\n", ans);
	return 0;
}