#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int mod = 8191;

struct mat {
	int num[2][2];
	void init() {
		memset(num, 0, sizeof(num));
	}
};

mat mat_multiple(mat a, mat b) {
	mat c;
	c.init();
	for(int i = 0; i < 2; ++i) {
		for(int j = 0; j < 2; ++j) {
			for(int k = 0; k < 2; ++k)
				c.num[i][j] = (c.num[i][j] + a.num[i][k] * b.num[k][j]) % mod;
		}
	}
	return c;
}

mat mat_qp(mat a, int n) {
	mat res;
	res.num[0][0] = res.num[1][1] = 1;
	res.num[0][1] = res.num[1][0] = 0;
	while(n) {
		if(n & 1)
			res = mat_multiple(res, a);
		a = mat_multiple(a, a);
		n >>= 1;
	}
	return res;
}

int main() {	
	int n, k;
	while(~scanf("%d %d", &n, &k)) {
		int t = sqrt(n);
		if(t * t == n) {
			puts("No answers can meet such conditions");
			continue;
		}
		int x0, y0 = 0; 
		do {
			y0++;
			x0 = sqrt(1 + n * y0 * y0);
		}while(x0 * x0 - n * y0 * y0 != 1);
		mat n0;
		n0.num[0][0] = n0.num[1][1] = x0 % mod;
		n0.num[0][1] = n * y0 % mod;
		n0.num[1][0] = y0 % mod;
		mat ans = mat_qp(n0, k - 1);
		int res = ans.num[0][0] * x0 + ans.num[0][1] * y0;
		res %= mod;
		printf("%d\n", res);
	}
	return 0;
}