#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 9;

long long qp(int x, int n) {
	long long base = x, ans = 1;
	while(n) {
		if(n & 1) {
			ans *= base;
			ans %= mod;
		}
		base *= base;
		base %= mod;
		n >>= 1;
	}
	return ans%mod;
}

char s[100010];
int lst[100010];

int main() {
	int n, a, b, k;
	cin >> n >> a >> b >> k;
	long long res = 0;
	scanf("%s", s);
	for(int i = 0; i < k; ++i) {
		if(s[i] == '+')
			lst[i] = 1;
		else
			lst[i] = -1;
	}
	int t = (n+1) / k;
	for(int i = 0; i < k; i++) {
		res += ((1LL * lst[i] * qp(a, n - i))%mod) * qp(b, i);
		res = (res + mod) % mod;
	}
	long long tmp = res;
	res = (res + mod) % mod;
	int m = qp(a, mod - 2)%mod;
	int q = (qp(m, k) % mod) * qp(b, k) % mod;
	if(q != 1)
		res = ((tmp * (qp(q, t) - 1)) % mod) * qp(q - 1, mod - 2) + mod;
	else 
		res = mod + tmp * t;
	cout << res % mod << endl;
	return 0;
}