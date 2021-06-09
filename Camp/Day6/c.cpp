#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int mod = 998244353;

struct Mat {
	int a[3][3];
	Mat(int f = 0) {
		memset(a, 0, sizeof(a));
		if(f == 1)
			a[0][0] = a[1][1] = a[2][2] = 1;
	}
	int* operator[](int id) {
		return a[id];
	}
	Mat operator*(Mat &rhs) {
		Mat res;
		for(int i = 0; i < 3; ++i) 
			for(int j = 0; j < 3; ++j) 
				for(int k = 0; k < 3; ++k) 
					res[i][j] = (res[i][j] + 1LL * a[i][k] * rhs[k][j]) % mod;
		return res;
	}
};

Mat qp(Mat a, LL n) {
	Mat res(1);
	while(n) {
		if(n & 1) 
			res = res * a;
		a = a * a;
		n >>= 1;
	}
	return res;
}

int T;
LL n, ans;

int main() {
	Mat b;
	b[0][0] = b[0][1] = b[1][0] = b[2][0] = b[2][1] = b[2][2] = 1;
	scanf("%d", &T);
	while(T--) {
		scanf("%lld", &n);
		Mat tmp = qp(b, n - 1);
		ans = (tmp[2][0] + tmp[2][2]) % mod;
		LL t = 2;
		ans = (ans - (n - n / 3) % mod + mod) % mod;
		n /= 3;
		while(n) {
			ans = (ans - t * ((n - n / 2) % mod) % mod + mod) % mod;
			n >>= 1;
			if(t == 2)
				t = 4;
			t = 2 * t % mod;
		}
		printf("%lld\n", ans);
	}
	return 0;
}