//segment tree beats
#include <bits/stdc++.h>
using namespace std;
#define lson rt << 1
#define rson rt << 1 | 1

const int N = 5e5 + 10;

int n, m, a[N];
int mx[N << 2], mn[N << 2], sx[N << 2], sn[N << 2], cx[N << 2], cn[N << 2], lazy[N << 2];
long long sum[N << 2];

void pushup(int rt) {
    sum[rt] = sum[lson] + sum[rson];
    if (mx[lson] > mx[rson]) {
        mx[rt] = mx[lson];
        cx[rt] = cx[lson];
        sx[rt] = max(sx[lson], mx[rson]);
    }
    else if (mx[lson] < mx[rson]) {
        mx[rt] = mx[rson];
        cx[rt] = cx[rson];
        sx[rt] = max(sx[rson], mx[lson]);
    }
    else {
        mx[rt] = mx[lson];
        cx[rt] = cx[lson] + cx[rson];
        sx[rt] = max(sx[lson], sx[rson]);
    }
    if (mn[lson] < mn[rson]) {
        mn[rt] = mn[lson];
        cn[rt] = cn[lson];
        sn[rt] = min(sn[lson], mn[rson]);
    }
    else if (mn[lson] > mn[rson]) {
        mn[rt] = mn[rson];
        cn[rt] = cn[rson];
        sn[rt] = min(sn[rson], mn[lson]);
    }
    else {
        mn[rt] = mn[lson];
        cn[rt] = cn[lson] + cn[rson];
        sn[rt] = min(sn[lson], sn[rson]);
    }
}

void pushdown(int rt, int l, int r) {
    int mid = l + r >> 1;
    if (lazy[rt]) {
        lazy[lson] += lazy[rt];
        lazy[rson] += lazy[rt];
        sum[lson] += 1LL * lazy[rt] * (mid - l + 1);
        sum[rson] += 1LL * lazy[rt] * (r - mid);
        mx[lson] += lazy[rt]; sx[lson] += lazy[rt]; mn[lson] += lazy[rt]; sn[lson] += lazy[rt];
        mx[rson] += lazy[rt]; sx[rson] += lazy[rt]; mn[rson] += lazy[rt]; sn[rson] += lazy[rt];
        lazy[rt] = 0;
    }
    if (mx[lson] > mx[rt]) {
        if (mn[lson] == mx[lson]) mn[lson] = mx[rt];
        if (sn[lson] == mx[lson]) sn[lson] = mx[rt];
        sum[lson] -= 1LL * (mx[lson] - mx[rt]) * cx[lson];
        mx[lson] = mx[rt];
    }
    if (mx[rson] > mx[rt]) {
        if (mn[rson] == mx[rson]) mn[rson] = mx[rt];
        if (sn[rson] == mx[rson]) sn[rson] = mx[rt];
        sum[rson] -= 1LL * (mx[rson] - mx[rt]) * cx[rson];
        mx[rson] = mx[rt];
    }
    if (mn[lson] < mn[rt]) {
        if (mx[lson] == mn[lson]) mx[lson] = mn[rt];
        if (sx[lson] == mn[lson]) sx[lson] = mn[rt];
        sum[lson] += 1LL * (mn[rt] - mn[lson]) * cn[lson];
        mn[lson] = mn[rt];
    }
    if (mn[rson] < mn[rt]) {
        if (mx[rson] == mn[rson]) mx[rson] = mn[rt];
        if (sx[rson] == mn[rson]) sx[rson] = mn[rt];
        sum[rson] += 1LL * (mn[rt] - mn[rson]) * cn[rson];
        mn[rson] = mn[rt];
    }
}

void build(int rt, int l, int r) {
    if (l == r) {
        sum[rt] = mx[rt] = mn[rt] = a[l];
        cx[rt] = cn[rt] = 1;
        sx[rt] = -1e9;
        sn[rt] = 1e9;
        lazy[rt] = 0;
        return;
    }
    int mid = l + r >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    pushup(rt);
}

void update(int rt, int l, int r, int L, int R, int val)  {
    if (r < l) return;
    if (L <= l && r <= R) {
        mx[rt] += val; sx[rt] += val; mn[rt] += val; sn[rt] += val;
        lazy[rt] += val;
        sum[rt] += 1LL * (r - l + 1) * val;
        return;
    }
    int mid = l + r >> 1;
    pushdown(rt, l, r);
    if (L <= mid) update(lson, l, mid, L, R, val);
    if (R > mid) update(rson, mid + 1, r, L, R, val);
    pushup(rt);
}

void modifymax(int rt, int l, int r, int L, int R, int val) {
    if (r < l || mn[rt] >= val) return;
    if (L <= l && r <= R && sn[rt] > val) {
        sum[rt] += 1LL * (val - mn[rt]) * cn[rt];
        if (mx[rt] == mn[rt]) mx[rt] = val;
        if (sx[rt] == mn[rt]) sx[rt] = val;
        mn[rt] = val;
        return;
    }
    int mid = l + r >> 1;
    pushdown(rt, l, r);
    if (L <= mid) modifymax(lson, l, mid, L, R, val);
    if (R > mid) modifymax(rson, mid + 1, r, L, R, val);
    pushup(rt);
}

void modifymin(int rt, int l, int r, int L, int R, int val) {
    if (r < l || mx[rt] <= val) return;
    if (L <= l && r <= R && sx[rt] < val) {
        sum[rt] -= 1LL * (mx[rt] - val) * cx[rt];
        if (mn[rt] == mx[rt]) mn[rt] = val;
        if (sn[rt] == mx[rt]) sn[rt] = val;
        mx[rt] = val;
        return;
    }
    int mid = l + r >> 1;
    pushdown(rt, l, r);
    if (L <= mid) modifymin(lson, l, mid, L, R, val);
    if (R > mid) modifymin(rson, mid + 1, r, L, R, val);
    pushup(rt);
}

int querymax(int rt, int l, int r, int L, int R) {
    if (L <= l && r <= R) return mx[rt];
    int mid = l + r >> 1, ans = -1e9;
    pushdown(rt, l, r);
    if (L <= mid) ans = querymax(lson, l, mid, L, R);
    if (R > mid) ans = max(ans, querymax(rson, mid + 1, r, L, R));
    pushup(rt);
    return ans;
}

int querymin(int rt, int l, int r, int L, int R) {
    if (L <= l && r <= R) return mn[rt];
    int mid = l + r >> 1, ans = 1e9;
    pushdown(rt, l, r);
    if (L <= mid) ans = querymin(lson, l, mid, L, R);
    if (R > mid) ans = min(ans, querymin(rson, mid + 1, r, L, R));
    pushup(rt);
    return ans;
}

long long querysum(int rt, int l, int r, int L, int R) {
    if (L <= l && r <= R) return sum[rt];
    int mid = l + r >> 1;
    long long ans = 0;
    pushdown(rt, l, r);
    if (L <= mid) ans = querysum(lson, l, mid, L, R);
    if (R > mid) ans += querysum(rson, mid + 1, r, L, R);
    pushup(rt);
    return ans;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) 
        scanf("%d", &a[i]);
    build(1, 1, n);
    scanf("%d", &m);
    while (m--) {
        int Tp, l, r, x;
        scanf("%d%d%d", &Tp, &l, &r);
        if (Tp == 1) {
            scanf("%d", &x);
            update(1, 1, n, l, r, x);
        }
        else if (Tp == 2) {
            scanf("%d", &x);
            modifymax(1, 1, n, l, r, x);
        }
        else if (Tp == 3) {
            scanf("%d", &x);
            modifymin(1, 1, n, l, r, x);
        }
        else if (Tp == 4) {
            printf("%lld\n", querysum(1, 1, n, l, r));
        }
        else if (Tp == 5) {
            printf("%d\n", querymax(1, 1, n, l, r));
        }
        else if (Tp == 6) {
            printf("%d\n", querymin(1, 1, n, l, r));
        }
    }
    return 0;
}