#include <bits/stdc++.h>
using namespace std;

int n, k, a, ll;
long long ans, res;
int main() {
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a);
		ll = res / k + !!(res % k);
		res += a;
		ans += ll;
		res -= ll * k;
		if(res < 0)
			res = 0;
	}
	ans += res / k + !!(res % k);
	printf("%lld\n", ans);
	return 0;
}