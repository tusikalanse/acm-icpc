#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int mod = 1000000007;
 
LL qp(LL a, LL n) {
	LL ans = 1;
	while(n) {
		if(n & 1) 
			ans = ans * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return ans;
}

int a[100010], b[100010];

int main() {
	int n, m;
	LL ans = 0, tmp = 1;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i)
		scanf("%d", &b[i]);
	for(int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	LL mo = qp(m, mod - 2);
	for(int i = 0; i < n; ++i) {
		if(a[i] > b[i] && b[i])
			break;
		if(a[i] && a[i] < b[i]) {
			ans = ans + tmp % mod;
			break;
		}
		if(a[i] == b[i] && b[i])
			continue;
		if(a[i] == b[i]) {
			ans = (ans + (tmp * (m - 1) % mod * mo % mod * qp(2, mod - 2) % mod) % mod) % mod;
			tmp = tmp * mo % mod;
			continue;
		}
		if(a[i] == 0) {
			ans = (ans + tmp * (b[i] - 1) % mod * mo % mod) % mod;
			tmp = tmp * mo % mod;
		}
		if(b[i] == 0) {
			ans = (ans + tmp * (m - a[i]) % mod * mo % mod) % mod;
			tmp = tmp * mo % mod;
		}
	}
	printf("%lld\n", ans % mod);
	return 0;
}f