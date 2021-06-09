#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int mod = 998244353, N = 1048576 + 10, g = 3;

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

const int inv2 = qp(2, mod - 2);

void FWT(int a[], int n) {  
    for(int d = 1; d < n; d <<= 1)  
        for(int m = d << 1, i = 0; i < n; i += m)  
            for(int j = 0; j < d; ++j) {  
                int x = a[i + j], y = a[i + j + d];  
                a[i + j] = (x + y) % mod, a[i + j + d] = (x - y + mod) % mod;   
            }  
}  

void IFWT(int a[], int n)   {  
    for(int d = 1; d < n; d <<= 1)  
        for(int m = d << 1, i = 0; i < n; i += m)  
            for(int j = 0; j < d; ++j) {  
                int x = a[i + j], y = a[i + j + d];  
                a[i + j] = 1LL * (x + y) * inv2 % mod, a[i + j + d] = (1LL * (x - y) * inv2 % mod + mod) % mod; 
            }  
} 

int n, a[N], m;
LL sum, ans;

int main() {
	while(~scanf("%d", &n)) {
		m = n;
		sum = ans = 0;
		for(; m & (m - 1); m += m & -m);
		for(int i = 0; i < m; ++i) 
			a[i] = 0;
		for(int i = 0; i < n; ++i)
			a[i] = 1;
		FWT(a, m);
		for(int i = 0; i < m; ++i)
			a[i] = 1LL * a[i] * a[i] % mod * a[i] % mod;
		IFWT(a, m);
		for(int i = 0; i < m; ++i)
			sum = (sum + 1LL * i * a[i]) % mod;
		for(int i = 0; i < m; ++i)
			ans = (ans + (1LL * i * a[i] % mod * (sum - i) % mod + mod) % mod) % mod;
		printf("%lld\n", ans * inv2 % mod);
	}
	return 0;
}