#include <bits/stdc++.h>
using namespace std;

const int N = 1010, mod = 998244353;

int w, h;
int qp(int a, int n) {
	int res = 1;
	while(n) {
		if(n & 1) {
			res = 1LL * res * a % mod;
		}
		a = 1LL * a * a % mod;
		n >>= 1;
	}
	return res;
}


int main() {
	scanf("%d%d", &w, &h);
	printf("%d\n", qp(2, w + h));
	return 0;
}