#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
using LL = long long;

struct FastIO {
    using ll = long long;
    static const int S = 1e7;
    int wpos;
    char wbuf[S];
    FastIO() : wpos(0) {}
    inline int xchar() {
        static char buf[S];
        static int len = 0, pos = 0;
        if (pos == len)
            pos = 0, len = fread(buf, 1, S, stdin);
        if (pos == len) exit(0);
        return buf[pos++];
    }
    inline int xuint() {
        int c = xchar(), x = 0;
        while (c <= 32) c = xchar();
        for (; '0' <= c && c <= '9'; c = xchar()) x = x * 10 + c - '0';
        return x;
    }
    inline int xint()
    {
        int s = 1, c = xchar(), x = 0;
        while (c <= 32) c = xchar();
        if (c == '-') s = -1, c = xchar();
        for (; '0' <= c && c <= '9'; c = xchar()) x = x * 10 + c - '0';
        return x * s;
    }
    inline void xstring(char *s)
    {
        int c = xchar();
        while (c <= 32) c = xchar();
        for (; c > 32; c = xchar()) * s++ = c;
        *s = 0;
    }
    inline void wchar(int x)
    {
        if (wpos == S) fwrite(wbuf, 1, S, stdout), wpos = 0;
        wbuf[wpos++] = x;
    }
    inline void wint(ll x)
    {
        if (x < 0) wchar('-'), x = -x;
        char s[24];
        int n = 0;
        while (x || !n) s[n++] = '0' + x % 10, x /= 10;
        while (n--) wchar(s[n]);
        wchar('\n');
    }
    inline void wstring(const char *s)
    {
        while (*s) wchar(*s++);
    }
    ~FastIO()
    {
        if (wpos) fwrite(wbuf, 1, wpos, stdout), wpos = 0;
    }
} io;


const int mod = 1e9 + 7;
LL A, B, C, D, T, p, n, ans, l, r, suml, sumr, cnt, lim;

const int N = 1e6 + 10;

struct mat {
    LL m[3][3];
    mat() {memset(m, 0, sizeof(m));}
    mat operator*(const mat &rhs) const {
        mat ans;
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                for(int k = 0; k < 3; ++k)
                    ans.m[i][j] = (ans.m[i][j] + m[i][k] * rhs.m[k][j]) % mod;
            }
        }
        return ans;
    }
    void output() {
        for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j) 
            printf("%lld%c", m[i][j], " \n"[j == 2]);
    }
};

mat mat_qp(mat a, LL n) {
    mat res;
    res.m[0][0] = res.m[1][1] = res.m[2][2] = 1;
    while(n) {
        if(n & 1)
            res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}

int main() {
    T = io.xint();
    mat res;
    while(T--) {
        A = io.xint();
        B = io.xint();
        C = io.xint();
        D = io.xint();
        p = io.xint();
        n = io.xint();
        mat a;
        a.m[0][2] = a.m[1][0] = a.m[2][2] = 1;
        a.m[0][0] = D;
        a.m[0][1] = C;
        ans = 0;
        int i = 1;
        if(n == 1)
            ans = A;
        else if(n == 2)
            ans = B;
        else {
            lim = 6 * log2(n);
            for(i = 3; i <= n; i = r + 1) {
                if(p < i) 
                    r = n;
                else
                    r = min(n, p / (p / i));
                if(r - i < lim) {
                    for(int j = i; j <= r; ++j) {
                        ans = C * A + B * D + p / i;
                        ans %= mod;
                        A = B;
                        B = ans;
                    }
                }
                else {
                    res = mat_qp(a, r - i + 1);
                    ans = res.m[0][0] * B % mod + res.m[0][1] * A % mod + res.m[0][2] * (p / i) % mod;
                    ans %= mod;
                    A = res.m[1][0] * B + res.m[1][1] * A + res.m[1][2] * (p / i);
                    A %= mod;
                    B = ans;
                }
            }     
        }  
        ans %= mod;
        ans = (ans + mod) % mod;
        io.wint(ans);
    }
    return 0;
}