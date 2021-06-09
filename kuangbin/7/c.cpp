#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100005;

int a[MAXN];

struct node {
    int l, r;
    long long sum, lazy;
}Tree[MAXN << 2];

void pushup(int rt) {
    Tree[rt].sum = Tree[rt << 1].sum + Tree[rt << 1 | 1].sum;
}

void pushdown(int rt) {
    if(Tree[rt].lazy) {
        Tree[rt << 1].lazy += Tree[rt].lazy;
        Tree[rt << 1 | 1].lazy += Tree[rt].lazy;
        Tree[rt << 1].sum += Tree[rt].lazy * (Tree[rt << 1].r - Tree[rt << 1].l + 1);
        Tree[rt << 1 | 1].sum += Tree[rt].lazy * (Tree[rt << 1 | 1].r - Tree[rt << 1 | 1].l + 1);
        Tree[rt].lazy = 0;
    }
}

void build(int rt, int l, int r) {
    Tree[rt].l = l;
    Tree[rt].r = r;
    Tree[rt].lazy = 0;
    if(l == r) {
        Tree[rt].sum = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    pushup(rt);
}

void update(int rt, int l, int r, int c) {
    if(l <= Tree[rt].l && r >= Tree[rt].r) {
        Tree[rt].lazy += c;
        Tree[rt].sum += 1LL * c * (Tree[rt].r - Tree[rt].l + 1);
        return;
    }
    pushdown(rt);
    int mid = (Tree[rt].l + Tree[rt].r) >> 1;
    if(mid >= l)
        update(rt << 1, l, r, c);
    if(mid < r) 
        update(rt << 1 | 1, l, r, c);
    pushup(rt);
}

long long query(int rt, int l, int r) {
    if(l <= Tree[rt].l && r >= Tree[rt].r) {
        return Tree[rt].sum;
    }
    pushdown(rt);
    int mid = (Tree[rt].r + Tree[rt].l) >> 1;
    long long res = 0;
    if(mid >= l) 
        res += query(rt << 1, l, r);
    if(mid < r)
        res += query(rt << 1 | 1, l, r);
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int n, q, A, B, C;
    char com[20];
    scanf("%d %d", &n, &q);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    build(1, 1, n);
    while(q--) {
        scanf("%s", com);
        if(com[0] == 'Q') {
            scanf("%d %d", &A, &B);
            printf("%lld\n", query(1, A, B));
        }
        else {
            scanf("%d %d %d", &A, &B, &C);
            update(1, A, B, C);
        }
    }
    return 0;
}
