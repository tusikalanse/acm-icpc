#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int N = 3e5 + 10, mod = 998244353, g = 3;
typedef long long LL;

LL a[N], c[N], ans[N];
int T, n, m, tot, inv, cnt[5], op, bit;
int invfac[1000010], fac[1000010];
int rev[N];
void get_rev(int bit) {
	for(int i = 0; i < (1 << bit); ++i) {
		rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (bit - 1));
	}
}

LL qp(LL a, LL n) {
    LL ans = 1;
    while(n) {
    	if(n & 1)
    		ans = ans * a % mod;
    	a = a * a % mod;
    	n >>= 1;
    }
    return ans;
}

void NTT(LL a[], int N, int on) {
	for(int i = 0; i < tot; ++i) if(i < rev[i]) swap(a[i], a[rev[i]]);
    for(int i = 2, mid = 1; i <= tot; i <<= 1, mid <<= 1) {
        LL wn = qp(g, (mod - 1) / i);
        if(on == -1) wn = qp(wn, mod - 2);
        for(int j = 0; j < N; j += i) {
            LL w = 1;
            for(int k = j; k < j + mid; ++k) {
                LL u = a[k], v = w * a[k + mid] % mod;
          		a[k] = (u + v) % mod;
          		a[k + mid] = ((u - v) % mod + mod) % mod;
                w = w * wn % mod;
            }
        }
    }
    if(on == -1) {
        for(int i = 0; i < tot; ++i)
            a[i] = 1LL * a[i] * inv % mod;
    }
} 

void solve(LL a[], LL b[]) {
	get_rev(bit);
	NTT(a, tot, 1);
	NTT(b, tot, 1);
	for(int i = 0; i < tot; ++i) {
		ans[i] = 1LL * a[i] * b[i] % mod;
		a[i] = b[i] = 0;
	}
	NTT(ans, tot, -1);
}

void init() {
	fac[0] = 1;
	for(int i = 1; i <= 1000000; ++i)
		fac[i] = 1LL * fac[i - 1] * i % mod;
	invfac[1000000] = qp(fac[1000000], mod - 2);
	for(int i = 1000000 - 1; ~i; --i)
		invfac[i] = 1LL * invfac[i + 1] * (i + 1) % mod;
}

int C(int n, int m) {
	if(n < m) return 0;
	return 1LL * fac[n] * invfac[m] % mod * invfac[n - m] % mod;
}

int main() {
	init();
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		tot = n + n;
		for(int i = 1; i <= n; ++i) 
			scanf("%lld", &a[i]);
		cnt[1] = cnt[2] = cnt[3] = 0;
		for(int i = 1; i <= m; ++i) {
			scanf("%d", &op);
			cnt[op]++;
		}
		bit = 1;
		while((1 << bit) < tot) bit++;
		tot = 1 << bit;
		inv = qp(tot, mod - 2);
		for(int i = 1; i <= 3; ++i) {
			memset(c, 0, sizeof(c));
			for(int j = 0; j * i < n; ++j) {
				c[j * i] = C(cnt[i] - 1 + j, j);
			}
			if(cnt[i] == 0) c[0] = 1;
			solve(a + 1, c);		
			for(int i = 0; i < n; ++i)
				a[i + 1] = ans[i];	
		}
		LL out = 0;
		for(int i = 1; i <= n; ++i)
			out ^= 1LL * i * a[i];
		printf("%lld\n", out);
	}
	return 0;
}