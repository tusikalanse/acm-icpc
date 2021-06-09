#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 50005;

int a[MAXN];

struct node {
    int l, r, sum;
}Tree[MAXN << 2];

void pushup(int rt) {
    Tree[rt].sum = Tree[rt << 1].sum + Tree[rt << 1 | 1].sum;
}

void build(int rt, int l, int r) {
    Tree[rt].l = l;
    Tree[rt].r = r;
    if(l == r) {
        Tree[rt].sum = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    pushup(rt);
}

void update(int rt, int pos, int val) {
    if(Tree[rt].l == Tree[rt].r) {
        Tree[rt].sum += val;
        return;
    }
    int mid = Tree[rt].l + Tree[rt].r >> 1;
    if(pos <= mid) 
        update(rt << 1, pos, val);
    else
        update(rt << 1 | 1, pos, val);
    pushup(rt);
}

int query(int rt, int l, int r) {
    if(Tree[rt].l >= l && Tree[rt].r <= r) {
        return Tree[rt].sum;
    }
    int mid = Tree[rt].l + Tree[rt].r >> 1;
    int ans = 0;
    if(l <= mid) 
        ans += query(rt << 1, l, r);
    if(mid < r)
        ans += query(rt << 1 | 1, l, r);
    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int t, n, x, y, cas = 0;
    char com[20];
    scanf("%d", &t);
    while(t--) {
        printf("Case %d:\n", ++cas);
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        build(1, 1, n);
        while(~scanf("%s", com) && strcmp(com, "End") && scanf("%d %d", &x, &y)) {
            switch(com[0]) {
            case 'A':
                update(1, x, y);
                break;
            case 'S':
                update(1, x, -y);
                break;
            case 'Q':
                printf("%d\n", query(1, x, y));
                break;
            }    
        }
    }
    return 0;
}
