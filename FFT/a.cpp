#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int MAXN = (100000 << 2) + 10;

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
long long num[200010], sum[200010];
int l[100010], T, len, bit;
int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) 
            scanf("%d", &l[i]);
        memset(num, 0, sizeof(num));
        sort(l, l + n);
        for(int i = 0; i < n; ++i)
            num[l[i]]++;
        len = l[n - 1] + 1;
        len = len + len - 1;
        bit = 1;
        while((1 << bit) < len) bit++;
        get_rev(bit);
        N = 1 << bit;
        for(int i = 0; i < len; ++i) 
            a[i] = b[i] = cp(num[i], 0);
        FFT(a, N, 1);
        FFT(b, N, 1);
        for(int i = 0; i < N; ++i)
            a[i] = a[i] * b[i];
        FFT(a, N, -1);
        for(int i = 0; i < len; ++i)
            num[i] = (long long)(a[i].a + 0.5);
        for(int i = 0; i < n; ++i)
            num[l[i] + l[i]]--;
        for(int i = 0; i < len; ++i)
            num[i] /= 2;
        for(int i = 1; i <= len; ++i)
            sum[i] = sum[i - 1] + num[i];
        long long ans = 0;
        for(int i = 0; i < n; ++i) {
            ans += sum[len] - sum[l[i]];
            ans -= n - 1;
            ans -= 1LL * i * (n - i - 1);
            ans -= 1LL * (n - i - 1) * (n - i - 2) / 2;
        }
        double out = ans;
        out = out * 6 / (1LL * n * (n - 1) * (n - 2));
        printf("%.7f\n", out);
        if(T)
            for(int i = 0; i < MAXN; ++i)
                a[i] = b[i] = cp();
    }
    return 0;
}