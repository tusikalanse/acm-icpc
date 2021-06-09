#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int a[N], n, tmp;
long long ans;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) 
		scanf("%d", &a[i]);
	tmp = 2e9;
	for(int i = n; i > 0; --i) {
		tmp = max(0, min(tmp - 1, a[i]));
		ans += tmp;
	}
	printf("%lld\n", ans);
	return 0;
}