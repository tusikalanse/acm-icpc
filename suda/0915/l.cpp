#include <bits/stdc++.h>
using namespace std;

const int N = 9, mod = 1e9 + 7;

struct Mat {
	int m[N][N];
	Mat() {
		memset(m, 0, sizeof(m));
	}
	Mat operator*(const Mat &rhs) const {
		Mat res;
		for(int i = 0; i < N; ++i) 
			for(int j = 0; j < N; ++j) 
				for(int k = 0; k < N; ++k)
					res.m[i][j] = (res.m[i][j] + 1LL * m[i][k] * rhs.m[k][j]) % mod;
		return res;
	}
};

Mat a;

Mat Mat_qp(Mat a, long long n) {
	Mat res;
	for(int i = 0; i < N; ++i)
		res.m[i][i] = 1;
	while(n) {
		if(n & 1)
			res = res * a;
		a = a * a;
		n >>= 1;
	}
	return res;
}


int main() {
	a.m[0][1] = a.m[0][6] = a.m[0][7] = 1;
	a.m[1][1] = a.m[1][6] = a.m[1][7] = 1;
	a.m[2][4] = 1;
	a.m[3][5] = a.m[3][8] = 1;
	a.m[4][0] = a.m[4][1] = a.m[4][3] = a.m[4][6] = a.m[4][7] = 1;
	a.m[5][2] = 2;
	a.m[6][5] = a.m[6][8] = 1;
	a.m[7][0] = a.m[7][3] = 1;
	a.m[8][4] = 1;
	int T;
	long long n;
	scanf("%d", &T);
	while(T--) {
		scanf("%lld", &n);
		if(n == 1) 
			printf("3\n");
		else if(n == 2)
			printf("9\n");
		else {
			Mat res = Mat_qp(a, n - 3);
			long long tot = 0;
			for(int i = 0; i < 9; ++i)
				for(int j = 0; j < 9; ++j)
					tot = (tot + res.m[i][j]) % mod;
			tot = tot * 2 % mod;
			for(int i = 0; i < 9; ++i)
				tot = (tot + 2 * res.m[i][4]) % mod;
			printf("%lld\n", tot);
		}
	}
	return 0;
}