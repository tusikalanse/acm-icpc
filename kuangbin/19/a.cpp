#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int mod = 1e9 + 7;

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

struct Mat {
	LL a[2][2];
	Mat() {memset(a, 0, sizeof(a));}
	Mat operator*(const Mat &rhs) const {
		Mat res;
		for(int i = 0; i < 2; ++i)
			for(int j = 0; j < 2; ++j)
				for(int k = 0; k < 2; ++k)
					res.a[i][j] = ((res.a[i][j] + a[i][k] * rhs.a[k][j]) % mod + mod) % mod;
		return res;
	}
};

Mat Mat_qp(Mat a, LL n) {
	Mat res;
	res.a[0][0] = res.a[1][1] = 1;
	while(n) {
		if(n & 1)
			res = res * a;
		a = a * a;
		n >>= 1;
	}
	return res;
}

int main() {
	int x, y, n;
	cin >> x >> y >> n;
	if(n == 1) {
		cout << (x % mod + mod) % mod << endl;
		return 0;
	}
	Mat a;
	a.a[0][0] = a.a[1][0] = 1;
	a.a[0][1] = -1;
	a = Mat_qp(a, n - 2);
	cout << ((a.a[0][0] * y + a.a[0][1] * x) % mod + mod) % mod << endl;

	return 0;
}