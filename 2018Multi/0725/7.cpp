#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define LL long long
using namespace std;

const int MAXN = 100005;

char com[20];
int n,q,A,B;
int b[MAXN], c[MAXN], lazy[MAXN << 2], mn[MAXN << 2];

inline int lowbit(int x) {return x & -x;}

void update(int x, int val) {
    for(int i = x; i <= n; i += lowbit(i)) {
        c[i] += val;
    }
}

int sum(int x) {
    int ans = 0;
    for(int i = x; i > 0; i -= lowbit(i)) {
        ans += c[i];
    }
    return ans;
}

void pushup(int rt) {
    mn[rt] = min(mn[rt << 1], mn[rt << 1 | 1]);
}

void build(int rt, int l, int r) {
    lazy[rt] = 0;
    if(l == r) {
        mn[rt] = b[l];
        return;
    }
    int mid = l + r >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    pushup(rt);
}

void pushdown(int rt) {
    if(lazy[rt]) {
        lazy[rt << 1] += lazy[rt];
        lazy[rt << 1 | 1] += lazy[rt];
        mn[rt << 1] += lazy[rt];
        mn[rt << 1 | 1] += lazy[rt];
        lazy[rt] = 0;
    }
}

void update(int rt, int l, int r, int L, int R) {
    if(l >= L && r <= R) {
        lazy[rt] -= 1;
        mn[rt] -= 1;
        return ;
    }
    pushdown(rt);
    int mid = l + r >> 1;
    if(mid >= L)
        update(rt << 1, l, mid, L, R);
    if(mid + 1 <= R)
        update(rt << 1 | 1, mid + 1, r, L, R);
    pushup(rt);
}

void dfs(int rt, int l, int r) {
    if(mn[rt] > 0)
        return;
    if(l == r) {
        update(l, 1);
        mn[rt] = b[l];
        return;
    }
    pushdown(rt);
    int mid = l + r >> 1;
    dfs(rt << 1, l, mid);
    dfs(rt << 1 | 1, mid + 1, r);
    pushup(rt);
}

int main() {
    while(~scanf("%d%d",&n,&q)) {
        memset(c, 0, sizeof(c));
        for(int i = 1; i <= n; i++) {
            scanf("%d",&b[i]);
        }
        build(1, 1, n);
        while(q--) {
            scanf("%s%d%d",com,&A,&B);
            if(com[0] == 'q') {
                printf("%d\n", sum(B) - sum(A - 1));
            }
            else {
                update(1, 1, n, A, B);
                dfs(1, 1, n);
            }
        }
    }
    return 0;
}
