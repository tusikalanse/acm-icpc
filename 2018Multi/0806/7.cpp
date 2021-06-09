#include <bits/stdc++.h>
using namespace std;
unsigned x = 100, y = 1000, z = 10000;
int T, n, m;

typedef unsigned long long ull;

unsigned foo() {
    x = (ull)x ^ (ull)(x << 11);
    x = x ^ (x >> 4);
    x = (ull)x ^ (ull)(x << 5);
    x = x ^ (x >> 14);
    unsigned w = x ^ y ^ z;
    x = y;
    y = z;
    z = w;
    return z;
}

const int MAXN = 1e5 + 10;
unsigned lazy[MAXN << 2], mn[MAXN << 2], num[MAXN << 2], mx[MAXN << 2];

void pushup(int rt) {
    mn[rt] = min(mn[rt << 1], mn[rt << 1 | 1]);
    mx[rt] = max(mx[rt << 1], mx[rt << 1 | 1]);
}

void build(int rt, int l, int r) {
    lazy[rt] = mn[rt] = num[rt] = mx[rt] = 0;
    if(l == r)
        return;
    int mid = l + r >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
}

void pushdown(int rt, int l, int r) {
    if(lazy[rt]) {
        if(l == r) {
            num[rt] = max(num[rt], mx[rt]);
            return;
        }
        mn[rt << 1] =  mx[rt << 1] = lazy[rt << 1] = lazy[rt];
        mn[rt << 1 | 1] = mx[rt << 1 | 1] = lazy[rt << 1 | 1] = lazy[rt];
        lazy[rt] = 0;
    }
}

void update(int rt, int l, int r, int L, int R, unsigned val) {
    if(mn[rt] >= val)
        return;
    if(l == r) {
        mx[rt] = mn[rt] = num[rt] = max(val, num[rt]);
        return;
    }
    if(L <= l && r <= R) {
        if(mx[rt] <= val) {
            mx[rt] = lazy[rt] = mn[rt] = val;
            return;
        }
        int mid = l + r >> 1;
        pushdown(rt, l, r);
        update(rt << 1, l, mid, L, R, val);
        update(rt << 1 | 1, mid + 1, r, L, R, val); 
        pushup(rt);
        return;
    }
    int mid = l + r >> 1;
    pushdown(rt, l, r);
    if(mid >= L)
        update(rt << 1, l, mid, L, R, val);
    if(mid < R)
        update(rt << 1 | 1, mid + 1, r, L, R, val);
    pushup(rt);
}

unsigned long long sum(int rt, int l, int r) {
    unsigned long long ans = 0;
    pushdown(rt, l, r);
    if(l == r) {
 //       cout << "a[" << l << "] = " << num[rt] << endl;
        return (ull)l * num[rt];
    }
    int mid = l + r >> 1;
    ans ^= sum(rt << 1, l, mid);
    ans ^= sum(rt << 1 | 1, mid + 1, r);
    return ans;    
}

int main() {
    int l, r;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%u%u%u", &n, &m, &x, &y, &z);
        build(1, 1, n);
        while(m--) {
            l = 1 + foo() % n;
            r = 1 + foo() % n;
            if(l > r)
                swap(l, r);
   //         cout << l << ' ' << r << endl;
            update(1, 1, n, l, r, foo() % (1 << 30));
        }
        printf("%llu\n", sum(1, 1, n));
    }
    return 0;
}