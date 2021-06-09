#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353, lim = 1e5;

struct Mat {
	long long a[2][2];
	Mat(bool flag = false) {
		memset(a, 0, sizeof(a));
		if(flag)
			a[0][0] = a[1][1] = 1;
	}
	Mat operator*(const Mat& rhs) const {
		Mat result;
		for(int i = 0; i < 2; ++i) {
			for(int j = 0; j < 2; ++j) {
				for(int k = 0; k < 2; ++k) {
					result.a[i][j] = (result.a[i][j] + a[i][k] * rhs.a[k][j]) % mod;
				}
			}
		}
		return result;
	}
};

Mat Mat_qp(Mat a, long long n) {
	Mat result(1);
	while(n) {
		if(n & 1)
			result = result * a;
		a = a * a;
		n >>= 1;
	}
	return result;
}

Mat base[65];
int Q;
long long N, ans, anss;

long long get(long long n) {
	if(n-- == 0) return 0;
	Mat res(1);
	for(int i = 62; ~i; --i) {
		if(n >> i & 1)
			res = res * base[i];
	}
	return res.a[0][0];
}

int main() {
	base[0].a[0][0] = 3; base[0].a[0][1] = 2;
	base[0].a[1][0] = 1; base[0].a[1][1] = 0;
	for(int i = 1; i <= 64; ++i) {
		base[i] = base[i - 1] * base[i - 1];
	}
	scanf("%d%lld", &Q, &N);
	if(Q <= lim) {
		for(int i = 1; i <= Q; ++i) {
			ans = get(N);
			anss ^= ans;
			N = N ^ (ans * ans);
		}
	}
	else {
		for(int i = 1; i <= lim; ++i) {
			ans = get(N);
			anss ^= ans;
			N = N ^ (ans * ans);
		}
		if(Q % 2 == 1) {
			ans = get(N);
			anss ^= ans;
		}
	}
	printf("%lld\n", anss);
	return 0;
}