#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct mat {
	mat(bool flag = 0) {
		m[0][1] = m[1][0] = 0;
		m[0][0] = m[1][1] = flag;
	}
	long long m[2][2];
};

mat mat_pow(mat a, mat b, int m) {
	mat ans(0);
	for(int i = 0; i < 2; ++i) {
		for(int j = 0; j < 2; ++j) {
			for(int k = 0; k < 2; ++k) {
				ans.m[i][j] += a.m[i][k] * b.m[k][j];
				ans.m[i][j] %= m;
			}
		}
	}
	return ans;
}

mat mat_quick_pow(mat a, int n, int m) {
	mat ans(1);
	while(n) {
		if(n & 1) {
			ans = mat_pow(ans, a, m);
		}
		a = mat_pow(a, a, m);
		n >>= 1;
	}
	return ans;
}

int main() {
	int a, b, n, m;
	while(cin >> a >> b >> n >> m) {
		mat p;
		p.m[0][0] = 2 * a % m;
		p.m[0][1] = (b - 1LL * a * a) % m;
		p.m[1][0] = 1;
		p.m[1][1] = 0;
		mat ans = mat_quick_pow(p, n - 1, m);
		long long res = (ans.m[0][0] * 2 * a) % m + ans.m[0][1] * 2;
		res %= m;
		cout << (res + m) % m << endl;
	}
	return 0;
}