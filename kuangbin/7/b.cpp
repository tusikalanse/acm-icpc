#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 200005;

int a[MAXN];

struct node {
    int l, r, mmax;
}Tree[MAXN << 2];

void pushup(int rt) {
    Tree[rt].mmax = max(Tree[rt << 1].mmax, Tree[rt << 1 | 1].mmax);
}

void build(int rt, int l, int r) {
    Tree[rt].l = l;
    Tree[rt].r = r;
    if(Tree[rt].l == Tree[rt].r) {
        Tree[rt].mmax = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    pushup(rt);
}

void update(int rt, int pos, int val) {
    if(Tree[rt].l == Tree[rt].r) {
        Tree[rt].mmax = val;
        return;
    }
    int mid = (Tree[rt].l + Tree[rt].r) >> 1;
    if(pos <= mid) 
        update(rt << 1, pos, val);
    else
        update(rt << 1 | 1, pos, val);
    pushup(rt);
}

int query(int rt, int l, int r) {
    if(Tree[rt].l >= l && Tree[rt].r <= r) {
        return Tree[rt].mmax;
    }
    int mid = (Tree[rt].l + Tree[rt].r) >> 1;
    int res = 0;
    if(mid >= l) 
        res = max(res, query(rt << 1, l, r));
    if(mid < r)
        res = max(res, query(rt << 1 | 1, l, r));
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int n, m, A, B;
    char C[5];
    while(~scanf("%d %d", &n, &m)) {
        for(int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        build(1, 1, n);
        while(m--) {
            scanf("%s %d %d", C, &A, &B);
            if(C[0] == 'Q') 
                printf("%d\n", query(1, A, B));
            else
                update(1, A, B);
        }
    }
    return 0;
}
