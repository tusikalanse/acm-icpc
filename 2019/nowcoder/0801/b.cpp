#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int x0, x1, a, b, mod, l;
char s[N];

struct Mat {
	long long a[2][2];
	Mat() {memset(a, 0, sizeof(a));}
	Mat operator*(const Mat &rhs) const {
		Mat res;
		for(int i = 0; i < 2; ++i) {
			for(int j = 0; j < 2; ++j) {
				for(int k = 0; k < 2; ++k) {
					res.a[i][j] = (res.a[i][j] + a[i][k] * rhs.a[k][j]) % mod;
				}
			}
		}
		return res;
	}
	void print() {
		for(int i = 0; i < 2; ++i) for(int j = 0; j < 2; ++j) printf("%lld ", a[i][j]); puts("");
	}
	bool operator==(const Mat &rhs) const {
		for(int i = 0; i < 2; ++i) 
			for(int j = 0; j < 2; ++j) 
				if(a[i][j] != rhs.a[i][j]) return false;
		return true;
	}
}f[1100];

Mat Mat_qp(const Mat &a, long long n) {
	Mat res, c = a;
	res.a[0][0] = res.a[1][1] = 1;
	while(n) {
		if(n & 1)
			res = res * c;
		c = c * c;
		n >>= 1;
	}
	return res;
}

Mat Base;

Mat get(Mat &a) {
	Mat res;
	res.a[0][0] = res.a[1][1] = 1;
	for(int i = l - 1; ~i; --i) {
		if(s[i] != '0')
			res = res * Mat_qp(a, s[i] - '0');
		a = Mat_qp(a, 10);
	}
	return res;
}
int main() {
	while(~scanf("%d%d%d%d%s%d", &x0, &x1, &a, &b, s, &mod)) {
		l = strlen(s);
		Base.a[0][0] = a; Base.a[0][1] = b; 
		Base.a[1][0] = 1; Base.a[1][1] = 0;
		Mat res = get(Base);
		printf("%lld\n", (res.a[1][0] * x1 % mod + res.a[1][1] * x0 % mod) % mod);
	}
	return 0;
}