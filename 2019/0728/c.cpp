#include <bits/stdc++.h>
using namespace std;

int n, mod, fac[100010], lim;

int main() {
	fac[0] = 1;
	for(int i = 1; ; ++i) {
		if(1LL * i * fac[i - 1] > 1e9) 
			break;
		else {
			fac[i] = i * fac[i - 1];
			lim = i;
		}
	}
	cin >> n >> mod;
	if(n > lim || fac[n] > lim) {
		cout << 0 << endl;
	}
	else {
		int f = 1;
		for(int i = 1; i <= n; ++i)
			f = 1LL * i * f;
		n = f;
		f = 1;
		for(int i = 1; i <= n; ++i)
			f = 1LL * i * f;
		n = f;
		f = 1;
		for(int i = 1; i <= n; ++i)
			f = 1LL * i * f % mod;
		n = f;
		cout << f << endl;
	}
	return 0;
}