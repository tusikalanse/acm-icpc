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
};

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


//----------segment query
/*
struct Base {
    int a[30], pos[30];
    int m;
    Base() {
        memset(a, 0, sizeof(a));
        memset(pos, 0, sizeof(pos));
        m = 0;
    }
    bool insert(int x, int p) {
        for(int i = 29; ~i; --i) {
            if((x >> i) & 1) {
                if(a[i] == 0) {
                    a[i] = x;
                    pos[i] = p;
                    m++;
                    return 1;
                }
                else if(pos[i] < p) {
                    swap(pos[i], p);
                    swap(a[i], x);
                    x ^= a[i];
                }
                else {
                    x ^= a[i];
                }
            }
        }
        return 0;
    }
    int query(int x, int l) {
        for(int i = 29; ~i; --i) {
            if(pos[i] >= l)
                x = max(x, x ^ a[i]);
        }
        return x;
    }
}f[N];

merge:c = a, for i in b, c.insert(b.a[i]), return c;
*/