#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

struct node {
    int l, r, sum, lazy;
}Tree[MAXN << 2];

void pushup(int rt) {
    Tree[rt].sum = Tree[rt << 1].sum + Tree[rt << 1 | 1].sum;
}

void pushdown(int rt) {
    if(Tree[rt].lazy) {
        Tree[rt << 1].lazy = Tree[rt].lazy;
        Tree[rt << 1 | 1].lazy = Tree[rt].lazy;
        Tree[rt << 1].sum = Tree[rt].lazy * (Tree[rt << 1].r - Tree[rt << 1].l + 1);
        Tree[rt << 1 | 1].sum = Tree[rt].lazy * (Tree[rt << 1 | 1].r - Tree[rt << 1 | 1].l + 1);
        Tree[rt].lazy = 0;
    }
}

void build(int rt, int l, int r) {
    Tree[rt].l = l;
    Tree[rt].r = r;
    Tree[rt].lazy = 0;
    if(l == r){ 
        Tree[rt].sum = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    pushup(rt);
}

void update(int rt, int l, int r, int c) {
    if(Tree[rt].l >= l && Tree[rt].r <= r) {
        Tree[rt].lazy = c;
        Tree[rt].sum = c * (Tree[rt].r - Tree[rt].l + 1);
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

int query(int rt, int l, int r) {
    if(Tree[rt].l >= l && Tree[rt].r <= r) {
        return Tree[rt].sum;
    }
    pushdown(rt);
    int mid = (Tree[rt].l + Tree[rt].r) >> 1;
    int ans = 0;
    if(mid >= l)
        ans += query(rt << 1, l, r);
    if(mid < r)
        ans += query(rt << 1 | 1, l, r);
    return ans;
}

int main() {
    int t, n, q, x, y, z, cas = 0;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &q);
        build(1, 1, n);
        while(q--) {
            scanf("%d %d %d", &x, &y, &z);
            update(1, x, y, z);
        }
        printf("Case %d: The total value of the hook is %d.\n", ++cas, query(1, 1, n));
    }
    return 0;
}
