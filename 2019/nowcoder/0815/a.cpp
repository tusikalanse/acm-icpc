#include <bits/stdc++.h>
using namespace std;

const int N = 8e6 + 10;
const int mod[2] = {512, 125 * 125 * 125};

int f[N];
int ans[2];
int n, m;

int qp(int a, int n, int mod = 1000000000) {
	int res = 1;
	while(n) {
		if(n & 1)
			res = 1LL * res * a % mod;
		a = 1LL * a * a % mod;
		n >>= 1;
	}
	return res;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int k = 0; k < 2; ++k) {
		f[0] = 0; f[1] = 1;
		int j = 2;
		for(; ; ++j) {
			f[j] = f[j - 1] + f[j - 2];
			if(f[j] >= mod[k]) f[j] -= mod[k];
			if(f[j] == 0 && f[j - 1] == 1) break;
		}
		for(int i = 0; i < j; ++i) {
			int cnt = n / j + (n % j >= i);
			ans[k] = (ans[k] + 1LL * cnt * qp(f[i], m)) % mod[k];
		}
	}
	while(ans[1] % mod[0] != ans[0]) ans[1] += mod[1];
	printf("%d\n", ans[1]);
	return 0;
}