#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int mod = 1e9 + 7;
typedef long long ll;

ll qpmod(ll a, ll n) {
	a %= mod;
	ll ans = 1;
	while(n) {
		if(n & 1)
			(ans *= a) %= mod;
		(a *= a) %= mod;
		n >>= 1;
	}
	return ans;
}


ll n;
char s[100005];

ll cal(ll num, ll k) {
	ll res = (k*(k-1)/2 + ((n-k)*(n-k+1))/2) % mod;
	(res *= qpmod(10, n - k)) %= mod;
	ll a = (((qpmod(10, n - k + 1) - 1 + mod) * qpmod(10, k - 1)) % mod) * qpmod(9, mod - 2) % mod;
	ll t = ((a * (qpmod(10, k) - 1 + mod) % mod) * qpmod(9 * qpmod(10, k - 1), mod - 2)) % mod;
	return (res+t)%mod*num % mod;
}


int main() {
	while(~scanf("%lld", &n)) {
		ll ans = 0;
		scanf("%s", s + 1);
		for(int i = 1; i <= n; ++i) {
			(ans += cal(s[i] - '0', i)) %= mod;
		}
		printf("%lld\n", ans % mod);
	}
	return 0;
}

