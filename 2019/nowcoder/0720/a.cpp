#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int mod = 1e9 + 7;

int T, n, m, ans = 1;

LL qp(LL a, LL n) {
	LL res = 1;
	while(n) {
		if(n & 1)
			res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}


int main() {
	cin >> T;
	while(T--) {
		cin >> n >> m;
		if(n == 1)
			ans *= 1;
		else if(m == 0)
			ans = 0;
		else
			ans = ans * qp(n - 1, mod - 2) % mod;
		cout << ans << endl;
	}
	return 0;
}