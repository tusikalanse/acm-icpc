#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 5e5 + 10;

struct tree {
    LL sum, rmx, lmx, mx, rmn, lmn, mn;
}sgt[N << 2];

int c[N], d[N], a, n, l[N], r[N];
long long ans;

void pushup(int rt) {
    sgt[rt].sum = sgt[rt << 1].sum + sgt[rt << 1 | 1].sum;
    sgt[rt].mx = max(sgt[rt << 1].mx, sgt[rt << 1 | 1].mx);
    sgt[rt].lmx = max(sgt[rt << 1].lmx, sgt[rt << 1].sum + sgt[rt << 1 | 1].lmx);
    sgt[rt].rmx = max(sgt[rt << 1 | 1].rmx, sgt[rt << 1 | 1].sum + sgt[rt << 1].rmx);
    sgt[rt].mx = max(sgt[rt].mx, sgt[rt << 1].rmx + sgt[rt << 1 | 1].lmx);
    sgt[rt].mn = min(sgt[rt << 1].mn, sgt[rt << 1 | 1].mn);
    sgt[rt].lmn = min(sgt[rt << 1].lmn, sgt[rt << 1].sum + sgt[rt << 1 | 1].lmn);
    sgt[rt].rmn = min(sgt[rt << 1 | 1].rmn, sgt[rt << 1 | 1].sum + sgt[rt << 1].rmn);
    sgt[rt].mn = min(sgt[rt].mx, sgt[rt << 1].rmn + sgt[rt << 1 | 1].lmn);
}

void build(int rt, int l, int r) {
    if(l == r) {
        sgt[rt].sum = sgt[rt].lmx = sgt[rt].rmx = sgt[rt].mx = c[l];
        sgt[rt].lmn = sgt[rt].rmn = sgt[rt].mn = c[l];
        return;
    }
    int mid = l + r >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    pushup(rt);
}

tree query(int rt, int l, int r, int L, int R) {
    if(L <= l && r <= R) return sgt[rt];
    int mid = l + r >> 1;
    if(R <= mid) return query(rt << 1, l, mid, L, R);
    if(L > mid)  return query(rt << 1 | 1, mid + 1, r, L, R);
    tree u = query(rt << 1, l, mid, L, R), v = query(rt << 1 | 1, mid + 1, r, L, R), o;
    o.sum = u.sum + v.sum;
    o.mx = max(u.mx, v.mx);
    o.mx = max(o.mx, u.rmx + v.lmx);
    o.lmx = max(u.lmx, u.sum + v.lmx);
    o.rmx = max(v.rmx, v.sum + u.rmx);
    o.mn = min(u.mn, v.mn);
    o.mn = min(o.mn, u.rmn + v.lmn);
    o.lmn = min(u.lmn, u.sum + v.lmn);
    o.rmn = min(v.rmn, v.sum + u.rmn);
    return o;
}

struct node {
    int val, id;
};

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &c[i]);
    }
    build(1, 1, n);
    stack<node> stk;
    stk.push({(int)-1e9, 0});
    for(int i = 1; i <= n; ++i) {
        while(stk.top().val >= c[i])
            stk.pop();
        l[i] = stk.top().id + 1;
        stk.push({c[i], i});
    }
    while(!stk.empty()) stk.pop();
    stk.push({(int)-1e9, n + 1});
    for(int i = n; i; --i) {
        while(stk.top().val >= c[i])
            stk.pop();
        r[i] = stk.top().id - 1;
        stk.push({c[i], i});
    }
    for(int i = 0; i < n; ++i) {
        long long mx = c[i], mn = c[i];
        if(r[i] > i) {
            tree o = query(1, 1, n, i + 1, r[i]);
            if(o.lmn < 0)
                mn += o.lmn;
            if(o.lmx > 0)
                mx += o.lmx;
        }
        if(l[i] < i) {
            tree o = query(1, 1, n, l[i], i - 1);
            if(o.rmn < 0)
                mn += o.rmn;
            if(o.rmx > 0)
                mx += o.rmx;
        }
        ans = max(ans, max(mx * c[i], mn * c[i]));
    }
    printf("%lld\n", ans);
    return 0;
}