#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7, N = 1e5 + 10;

long long qp(long long a, long long n) {
	n %= mod - 1;
	long long res = 1;
	while(n) {
		if(n & 1)
			res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

char s[N];
int n, l;
long long ans, c0, s0, s1;

int main() {
	while(~scanf("%d%s", &n, s)) {
		s0 = s1 = 0;
		ans = 1;
		l = strlen(s);
		if(l == 1 && s[0] == '0') {
			puts("1");
			continue;
		}
		c0 = n - l;
		for(int i = 0; i < l; ++i) {
			if(s[i] == '0') {
				++c0;
				continue;
			}
			ans = ans * qp(2, c0 * s1) % mod * qp(2, s1) % mod * (qp(2, c0 + s0) + mod - 1) % mod;
			s0 += c0;
			++s1;
			c0 = 0;
		}
		if(c0 != 0)
			ans = ans * qp(2, c0 * s1) % mod;
		printf("%lld\n", ans);
	}
	return 0;
}