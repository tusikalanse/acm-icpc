#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, mod = 1e9 + 7;

int lazy[N << 2], n, m, op, L, R, A, B;

char s[N];

struct M {
    int a[2][2];
    M operator*(const M &rhs) const {
        M res;
        memset(res.a, 0, sizeof(res.a));
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 2; ++k) {
                    res.a[i][j] = (res.a[i][j] + 1LL * a[i][k] * rhs.a[k][j]) % mod;
                }
            }
        }
        return res;
    }
}mat[N << 2];

void build(int rt, int l, int r) {
    lazy[rt] = 0;
    if (l == r) {
        mat[rt].a[0][0] = mat[rt].a[1][1] = 1;
        mat[rt].a[0][1] = mat[rt].a[1][0] = 0;
        if (s[l] == 'A')
            mat[rt].a[1][0] = 1;
        else 
            mat[rt].a[0][1] = 1;
        return;
    }
    int mid = l + r >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    mat[rt] = mat[rt << 1] * mat[rt << 1 | 1];
}

void pushdown(int rt) {
    if (lazy[rt]) {
        lazy[rt << 1] ^= 1;
        lazy[rt << 1 | 1] ^= 1;
        swap(mat[rt << 1].a[0][1], mat[rt << 1].a[1][0]);
        swap(mat[rt << 1].a[0][0], mat[rt << 1].a[1][1]);
        swap(mat[rt << 1 | 1].a[0][1], mat[rt << 1 | 1].a[1][0]);
        swap(mat[rt << 1 | 1].a[0][0], mat[rt << 1 | 1].a[1][1]);
        lazy[rt] = 0;
    }
}

void reverse(int rt, int l, int r, int L, int R) {
    if (L <= l && r <= R) {
        lazy[rt] ^= 1;
        swap(mat[rt].a[0][1], mat[rt].a[1][0]);
        swap(mat[rt].a[0][0], mat[rt].a[1][1]);
        return;
    }
    int mid = l + r >> 1;
    pushdown(rt);
    if (L <= mid)
        reverse(rt << 1, l, mid, L, R);
    if (R > mid)
        reverse(rt << 1 | 1, mid + 1, r, L, R);
    mat[rt] = mat[rt << 1] * mat[rt << 1 | 1];
}

M query(int rt, int l, int r, int L, int R) {
    if (L <= l && r <= R) 
        return mat[rt];
    M ans;
    ans.a[0][0] = ans.a[1][1] = 1;
    ans.a[0][1] = ans.a[1][0] = 0;
    int mid = l + r >> 1;
    pushdown(rt);
    if (L <= mid)
        ans = ans * query(rt << 1, l, mid, L, R);
    if (R > mid)
        ans = ans * query(rt << 1 | 1, mid + 1, r, L, R);
    return ans;
}

int main() {
    scanf("%d%d", &n, &m);
    scanf("%s", s + 1);
    build(1, 1, n);
    while (m--) {
        scanf("%d%d%d", &op, &L, &R);
        if (op == 1)
            reverse(1, 1, n, L, R);
        else {
            scanf("%d%d", &A, &B);
            M ans = query(1, 1, n, L, R);
            printf("%lld %lld\n", (1LL * ans.a[0][0] * A % mod + 1LL * ans.a[1][0] * B % mod) % mod, (1LL * ans.a[0][1] * A % mod + 1LL * ans.a[1][1] * B % mod) % mod);
        }
    }
    return 0;
}