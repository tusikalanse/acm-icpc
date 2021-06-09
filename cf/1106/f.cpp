#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int mod = 998244353, N = 110;
int n, m, k;
int b[N];


struct Mat {
	LL a[N][N];
	Mat(bool flag = 0) {
		memset(a, 0, sizeof(a));
		if(flag)
			for(int i = 0; i < N; ++i)
				a[i][i] = 1;
	}
	LL* operator[](unsigned id) {
		return a[id];
	}
	Mat operator*(Mat &rhs) {
		Mat res;
		for(int i = 0; i < k; ++i) {
			for(int j = 0; j < k; ++j) {
				for(int p = 0; p < k; ++p) {
					res[i][j] = (res[i][j] + a[i][p] * rhs[p][j]) % (mod - 1);
				}
			}
		}
		return res;
	}
}base;

Mat Mat_qp(Mat a, LL n) {
	Mat res(1);
	while(n) {
		if(n & 1)
			res = res * a;
		a = a * a;
		n >>= 1;
	}
	return res;
}

LL qp(LL a, LL n, LL m = mod) {
	LL res = 1;
	while(n) {
		if(n & 1)
			res = res * a % m;
		a = a * a % m;
		n >>= 1;
	}
	return res;
}

LL BSGS(LL A, LL B, LL C) { //find minium x satisfy A ** x % C = B % C 
	map<LL, LL> mp;
	if(A % C == 0) return -1;
	LL m = ceil(sqrt(C)); //x = i * m - j, A ** (i * m - j) = B, A ** (i * m) = B * A ** j
	LL ans = B % C;
	for(int j = 0; j <= m; ++j) { //enum j
		mp[ans] = j;
		ans = ans * A % C;		
	}
	LL t = qp(A, m, C);
	ans = t;
	for(int i = 1; i <= m; ++i) { //enum i, find j
		if(mp.count(ans)) 
			return ((i * m - mp[ans]) % C + C) % C;
		ans = ans * t % mod;
	}
	return -1;
}

LL exgcd(LL a, LL b, LL &x, LL &y) {//x, y must be reference, ax + by = gcd(a, b)
    if(b == 0) {
    	x = 1, y = 0;
    	return a;
    }
    LL d = exgcd(b, a % b, x, y);
    LL t = x;
    x = y, y = t - (a / b) * y;
    return d; //d = gcd(a, b)
}

LL solve(LL t, LL p) {
	LL x, y;
	LL d = exgcd(t, mod - 1, x, y);
	if(p % d) return -1;
	x = ((x * p / d) % (mod - 1) + (mod - 1)) % (mod - 1);
	return qp(3, x, mod);
}

int main() {
	scanf("%d", &k);
	for(int i = 0; i < k; ++i) {
		scanf("%lld", &base[0][i]);
		base[i + 1][i] = 1;
	}
	scanf("%d%d", &n, &m);
	Mat jar = Mat_qp(base, n - k);
	printf("%lld\n", solve(jar[0][0], BSGS(3, m, mod)));
	return 0;
}