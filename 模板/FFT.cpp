#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int MAXN = (100000 << 3) + 10;

struct cp {
	double a, b;
	cp(double _a = 0, double _b = 0) : a(_a), b(_b) {}
	cp operator+(const cp &rhs) const {
		return cp(a + rhs.a, b + rhs.b);
	}
	cp operator-(const cp &rhs) const {
		return cp(a - rhs.a, b - rhs.b);
	}
	cp operator*(const cp &rhs) const {
		return cp(a * rhs.a - b * rhs.b, a * rhs.b + b * rhs.a);
	}
	cp operator!() const {
		return cp(a, -b);
	}
};

cp a[MAXN], b[MAXN];
int n, m, N;
int rev[MAXN];
void get_rev(int bit) {
	for(int i = 0; i < (1 << bit); ++i) {
		rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (bit - 1));
	}
}

void FFT(cp a[], int len, int dft) {
	for(int i = 0; i < N; ++i) if(i < rev[i]) swap(a[i], a[rev[i]]);
	for(int i = 2, mid = 1; i <= N; i <<= 1, mid <<= 1) {
		cp wn(cos(2 * PI / i), sin(2 * dft * PI / i));
		for(int j = 0; j < N; j += i) {
			cp w(1, 0);
			for(int k = j; k < j + mid; ++k) {
				cp u = a[k], v = w * a[k + mid];
				a[k] = u + v;
				a[k + mid] = u - v;
				w = w * wn;
			}
		}
	}
	if(dft == -1)
		for(int i = 0; i < N; ++i)
			a[i].a /= N, a[i].b /= N;
}
char A[100010], B[100010];
int main() {
	scanf("%s%s", A, B);
	n = strlen(A);
	m = strlen(B);
	int bit = 1;
	N = n + m - 1;
	while((1 << bit) < N) bit++;
	N = 1 << bit;
	get_rev(bit);
	for(int i = 0; i < n; ++i)
		a[i].a = A[n - 1 - i] - '0';
	for(int i = 0; i < m; ++i) 
		b[i].a = B[m - 1 - i] - '0';
	FFT(a, N, 1);
	FFT(b, N, 1);
	for(int i = 0; i < N; ++i) 
		a[i] = a[i] * b[i];
	FFT(a, N, -1);
	N = n + m - 1;
	for(int i = 0; i < N; ++i) {
		a[i + 1].a += (int)(a[i].a + 0.5) / 10;
		a[i].a = (int)(a[i].a + 0.5) % 10;
	}
	while(abs(a[N].a) > 0.3) {
		a[N + 1].a += (int)(a[N].a + 0.5) / 10;
		a[N].a = (int)(a[N].a + 0.5) % 10;
		N++;
	}
	for(int i = N - 1; ~i; --i)
		putchar('0' + (int)(a[i].a + 0.5));
	puts("");
	for(int i = 0; i < N; ++i)
		a[i] = b[i] = cp(0, 0);
	return 0;
}