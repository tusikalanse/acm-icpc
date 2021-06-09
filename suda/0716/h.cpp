#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#define LL long long
using namespace std;

LL qp(LL a, LL n, LL mod) {
	LL ans = 1;
	while(n) {
		if(n & 1) {
			ans *= a;
			ans %= mod;
		}
		a *= a;
		a %= mod;
		n >>= 1;
	}
	return ans;
}

int euler(int n) {
	int ans = n;
	for(int i = 2; i * i <= n; ++i) {
		if(n % i == 0)
			ans = ans / i * (i - 1);
		while(n % i == 0)
			n /= i;
	}
	if(n > 1)
		ans = ans / n * (n - 1);
	return ans;
}

char s[1000010];

int main() {
	LL a, b, c;
	while(~scanf("%lld %s %lld", &a, s, &c)) {
		a %= c;
		b = 0;
		int l = strlen(s);
		int phi = euler(c);
		for(int i = 0; i < l; ++i) {
			b = b * 10 + s[i] - '0';
			b %= phi;
		}
		b += phi;
		printf("%lld\n", qp(a, b, c));
	}
	return 0;
}