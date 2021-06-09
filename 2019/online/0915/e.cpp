#include <bits/stdc++.h>
using namespace std;

int qp(int a, int n) {
	int res = 1;
	while(n) {
		if(n & 1)
			res *= a;
		a *= a;
		n >>= 1;
	}
	return res;
}

int main() {
	int f[18];
	for(int i = 1; i <= 12; ++i) {
		f[i] = qp(6, i - 1) + 41 * qp(2, i - 1) - 2 * qp(4, i - 1);
		cout << f[i] << endl;
	}

	return 0;
}