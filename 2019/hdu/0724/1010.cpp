#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10, mod = 1e6 + 3;

int fac[N], n;

void init() {
	fac[0] = 1;
	for(int i = 1; i < N; ++i)
		fac[i] = 1LL * i * fac[i - 1] % mod;
}

int main() {
	init();
	while(~scanf("%d", &n)) {
		if(n >= mod)
			printf("0\n");
		else if(n == 1)
			printf("2\n");
		else
			printf("%d\n", fac[n]);
	}
	
	return 0;
}