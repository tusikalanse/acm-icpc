#include <bits/stdc++.h>
using namespace std;

using LL = long long;./

LL qp(LL a, LL n, int mod) {
	LL res = 1;
	while (n) {
		if (n & 1)
			res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}


void gao(int x) {
	int p = sqrt(x);
	LL mn = 1e9;
	for (int i = 2; i <= p; ++i)
		mn = min(mn, qp(i, x - 2, x));
	cout << x << " " << mn << endl;
}

int main() {
	gao(998244353);
	gao(998244853);
	gao(1000000007);
	gao(1000000009);
	return 0;
}