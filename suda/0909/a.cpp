#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int T, n, k, ans;

int qp(int a, int n) {
	long long res = 1;
	while(n) {
		if(n & 1)
			res = 1LL * res * a % mod;
		a = 1LL * a * a % mod;
		n >>= 1;
	}
	return res;
}

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &k);
		int a, b;
		int d = qp(2, k); 
		if(k == 1)
			b = 2;
		else {
			if(n == 1)
				b = d;
			else if(n == 2)
				b = 1LL * d * (d - 1) % mod;
			else {
				a = 1LL * d * (d - 1) % mod;
				for(int i = 3; i <= n; ++i) {
					b = 1LL * d * qp((d - 1), i - 1) % mod;
					b = (b - a) % mod;
					b = (b + mod) % mod;
					a = b;
				}
			}
		}
		b = (b + mod) % mod;
		printf("%d\n", b);
	}
	return 0;
}