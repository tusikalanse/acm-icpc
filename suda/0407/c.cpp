#include <cstdio>
#include <algorithm>
#include <cstring>
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
	long long n, k;
	int cnt = 0;
	while(~scanf("%lld %lld", &n, &k)) {
		printf("Case #%d: %lld\n", ++cnt, qp(n%MOD, k)%MOD);
	}
}