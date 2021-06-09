#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

long long qp(long long a, long long n) {
	long long res = 1;
	while(n) {
		if(n&1)
			res *= a;
		a *= a;
		a %= MOD;
		res %= MOD;
		n >>= 1;
	}
	return res;
}


int main() {
	long long a, b, n, x, ans, an;
	cin >> a >> b >> n >> x;
	if(a == 1) {
		ans = (b*(n%MOD))%MOD;
		ans += x;
		ans %= MOD;
	}
	else {
		an = qp(a, n);
		ans = (an-1)*qp(a-1, MOD-2)%MOD;
		ans = (b*ans)%MOD;
		ans += x*an;
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}
