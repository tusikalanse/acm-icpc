#include <bits/stdc++.h>
using namespace std;
inline char read() {
    static const int IN_LEN = 1000000;
    static char buf[IN_LEN], *s, *t;
    if (s == t) {
        t = (s = buf) + fread(buf, 1, IN_LEN, stdin);
        if (s == t) return -1;
    }
    return *s++;
}
template<class T>
inline void read(T &x) {
    static char c;
    static bool iosig;
    for (c = read(), iosig = false; !isdigit(c); c = read()) {
        if (c == '-') iosig = true;
        if (c == -1) return;
    }
    for (x = 0; isdigit(c); c = read())
        x = (x + (x << 2) << 1) + (c ^ '0');
    if (iosig) x = -x;
}
const int OUT_LEN = 1000000;
char obuf[OUT_LEN], *oh = obuf;
inline void writeChar(char c) {
    if (oh == obuf + OUT_LEN) fwrite(obuf, 1, OUT_LEN, stdout), oh = obuf;
    *oh++ = c;
}
template<class T>
inline void print(T x) {
    static int buf[30], cnt;
    if (x == 0) {
        writeChar(48);
    } else {
        if (x < 0) writeChar('-'), x = -x;
        for (cnt = 0; x; x /= 10)  buf[++cnt] = x % 10 + 48;
        while (cnt) writeChar(buf[cnt--]);
    }
}
template<class T>
inline void println(T x) {
    print(x), writeChar('\n');
}
inline void flush() {
    fwrite(obuf, 1, oh - obuf, stdout);
}
template<size_t size>
struct SuffixArray {
    bool t[size << 1];
    int sa[size], height[size], rnk[size];
    inline bool islms(const int i, const bool *t) { 
        return i > 0 && t[i] && !t[i - 1]; 
    }
    template<class T>
    inline void sort(T s, int *sa, const int len, const int sigma, const int sz, bool *t, int *b, int *cb, int *p) {
        memset(b, 0, sizeof(int) * sigma);
        memset(sa, -1, sizeof(int) * len);
        for (register int i = 0; i < len; i++) b[s[i]]++;
        cb[0] = b[0];
        for (register int i = 1; i < sigma; i++) cb[i] = cb[i - 1] + b[i];
        for (register int i = sz - 1; i >= 0; i--) sa[--cb[s[p[i]]]] = p[i];
        for (register int i = 1; i < sigma; i++) cb[i] = cb[i - 1] + b[i - 1];
        for (register int i = 0; i < len; i++) if (sa[i] > 0 && !t[sa[i] - 1]) sa[cb[s[sa[i] - 1]]++] = sa[i] - 1;
        cb[0] = b[0];
        for (register int i = 1; i < sigma; i++) cb[i] = cb[i - 1] + b[i];
        for (register int i = len - 1; i >= 0; i--) if (sa[i] > 0 && t[sa[i] - 1]) sa[--cb[s[sa[i] - 1]]] = sa[i] - 1;
    }
    template<class T>
    inline void sais(T s, int *sa, const int len, bool *t, int *b, int *b1, const int sigma) {
        register int i, j, x, p = -1, cnt = 0, sz = 0, *cb = b + sigma;
        for (t[len - 1] = 1, i = len - 2; i >= 0; i--) t[i] = s[i] < s[i + 1] || (s[i] == s[i + 1] && t[i + 1]);
        for (i = 1; i < len; i++) if (t[i] && !t[i - 1]) b1[sz++] = i;
        sort(s, sa, len, sigma, sz, t, b, cb, b1);
        for (i = sz = 0; i < len; i++) if (islms(sa[i], t)) sa[sz++] = sa[i];
        for (i = sz; i < len; i++) sa[i] = -1;
        for (i = 0; i < sz; i++) {
            for (x = sa[i], j = 0; j < len; j++) {
                if (p == -1 || s[x + j] != s[p + j] || t[x + j] != t[p + j]) { cnt++, p = x; break; }
                else if (j > 0 && (islms(x + j, t) || islms(p + j, t))) break;
            }
            sa[sz + (x >>= 1)] = cnt - 1;
        }
        for (i = j = len - 1; i >= sz; i--) if (sa[i] >= 0) sa[j--] = sa[i];
        register int *s1 = sa + len - sz, *b2 = b1 + sz;
        if (cnt < sz) sais(s1, sa, sz, t + len, b, b1 + sz, cnt);
        else for (i = 0; i < sz; i++) sa[s1[i]] = i;
        for (i = 0; i < sz; i++) b2[i] = b1[sa[i]];
        sort(s, sa, len, sigma, sz, t, b, cb, b2);
    }
    template<class T>
    inline void getHeight(T s, int n) {
        for (register int i = 1; i <= n; i++) rnk[sa[i]] = i;
        register int j = 0, k = 0;
        for (register int i = 0; i < n; height[rnk[i++]] = k)
            for (k ? k-- : 0, j = sa[rnk[i] - 1]; s[i + k] == s[j + k]; k++);
    }
    template<class T>
    inline void init(T s, const int len, const int sigma) {
        sais(s, sa, len, t, rnk, height, sigma), rnk[0] = 0;
    }
};
const int MAXN = 1e6 + 10;
char s[MAXN];
int len;
SuffixArray<MAXN> sf;
int main() {
    len = fread(s, 1, MAXN, stdin);
    sf.init(s, len + 1, 256);
    for (register int i = 1; i <= len; i++) print(sf.sa[i]), writeChar(' ');
    flush();
    return 0;
}