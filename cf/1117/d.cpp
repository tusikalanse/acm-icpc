#include <bits/stdc++.h>
using namespace std;

const int N = 110, mod = 1e9 + 7;

long long n, ans;
int m;

struct mat {
	long long a[N][N];
	int d;
	mat(int dd, bool f = false) {
		memset(a, 0, sizeof(a));
		d = dd;
		if(f) {
			for(int i = 0; i < d; ++i) {
				a[i][i] = 1;
			}
		}
	}
	long long* operator[](unsigned id) {
		return a[id];
	}
	mat operator*(mat &rhs) {
		mat res(d);
		for(int i = 0; i < d; ++i) {
			for(int j = 0; j < d; ++j) {
				for(int k = 0; k < d; ++k) {
					res[i][j] = (res[i][j] + a[i][k] * rhs[k][j] % mod) % mod;
				}
			}
		}
		return res;
	}
};

mat mat_qp(mat a, long long n) {
	mat res(a.d, true);
	while(n) {
		if(n & 1) {
			res = res * a;
		}
		a = a * a;
		n >>= 1;
	}
	return res;
}

int main() {
	scanf("%lld%d", &n, &m);
	if(n < m) {
		printf("1\n");
		return 0;
	}
	mat a(m);
	a[0][0] = a[0][m - 1] = 1;
	for(int i = 1; i < m; ++i)
		a[i][i - 1] = 1;
	a = mat_qp(a, n - m);
	ans = a[0][0] * 2 % mod;
	for(int i = 1; i < m; ++i)
		ans = (ans + a[0][i]) % mod;
	printf("%lld\n", ans);
	return 0;                                                                                                                                                                                    
}