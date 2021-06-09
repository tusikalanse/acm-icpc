#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int mod = 1e6 + 3;

LL qp(LL a, LL n) {
	a %= mod;
	LL ans = 1;
	while(n) {
		if(n & 1) 
			(ans *= a) %= mod;
		(a *= a) %= mod;
		n >>= 1;
	}
	return ans;
}

LL m2(LL m) {
	LL ans = 0;
	while(m) {
		ans += m / 2;
		m >>= 1;
	}
	return ans;
}

LL mul(LL n, LL k) {
	LL ans = 1;
	LL t = qp(2, n);
	for(LL i = 0; i < k; ++i) {
		ans = ans * (t - i) % mod;
	}
	return (ans + mod) % mod;
}

bool test(LL n, LL k) {
	k--;
	while(n--) {
		k >>= 1;
		if(k == 0)
			return false;
	}
	return true;
}

int main() {
	LL n, k, a, b, cnt2;
	scanf("%lld %lld", &n, &k);
	if(test(n, k)) {
		puts("1 1");
		return 0;
	}
	cnt2 = m2(k - 1);
	cnt2 += n;
	if(k >= mod) {
		a = qp(qp(2, n), k) * qp(qp(2, cnt2), mod - 2) % mod;
		printf("%lld %lld\n", a, a);
	}
	else {
		a = qp(qp(2, n), k) * qp(qp(2, cnt2), mod - 2) % mod;
		b = mul(n, k) * qp(qp(2, cnt2), mod - 2) % mod;
		b = (((a - b) % mod) + mod) % mod;
		printf("%lld %lld\n", b, a);
	}
	return 0;
}