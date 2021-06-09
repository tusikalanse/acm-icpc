#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 10;

struct Base {
    unsigned a[32];
    Base() {
        memset(a, 0, sizeof(a));
    }
    void insert(unsigned x) {
        for(int i = 31; ~i; --i) {
            if(x >> i & 1) {
                if(!a[i]) {
                    a[i] = x;
                    return;
                }
                else {
                    x ^= a[i];
                }
            }
        }
    }
    bool query(unsigned x) {
        for(int i = 31; ~i; --i) {
            if(x >> i & 1) {
                x ^= a[i];
            }
        }
        return x == 0;
    }
}seg[N << 2];

Base intersect(const Base &a, const Base &b) {
    Base all = a, c, d;
    for(int i = 31; ~i; --i) d.a[i] = 1LL << i;
    for(int i = 31; ~i; --i) {
        if(b.a[i]) {
            unsigned v = b.a[i], k = 0;
            bool can = true;
            for(int j = 31; ~j; --j) {
                if(v >> j & 1) {
                    if(all.a[j]) {
                        v ^= all.a[j];
                        k ^= d.a[j];
                    }
                    else {
                        can = false;
                        all.a[j] = v;
                        d.a[j] = k;
                        break;
                    }
                }
            }
            if(can) {
                unsigned v = 0;
                for(int j = 31; ~j; --j) {
                    if(k >> j & 1)
                        v ^= a.a[j];
                }
                c.insert(v);
            }
        }
    }
    return c;
}

int n, m, sz, l, r;
unsigned x;

void pushup(int rt) {
    seg[rt] = intersect(seg[rt << 1], seg[rt << 1 | 1]);
}

void build(int rt, int l, int r) {
    if(l == r) {
        scanf("%d", &sz);
        while(sz--) {
            scanf("%u", &x);
            seg[rt].insert(x);
        }
        return;
    }
    int mid = l + r >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    pushup(rt);
}

bool query(int rt, int l, int r, int L, int R, unsigned val) {
    if(L <= l && r <= R) return seg[rt].query(val);
    int mid = l + r >> 1;
    if(L <= mid) if(!query(rt << 1, l, mid, L, R, val)) return false;
    if(R > mid) if(!query(rt << 1 | 1, mid + 1, r, L, R, val)) return false;
    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    build(1, 1, n);
    while(m--) {
        scanf("%d%d%u", &l, &r, &x);
        puts(query(1, 1, n, l, r, x) ? "YES" : "NO");
    }
    return 0;
}