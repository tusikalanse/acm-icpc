#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 8005;

int vis[MAXN << 2], ans[MAXN << 2];

struct node {
    int l, r, col;
}Tree[MAXN << 2];

void pushdown(int rt) {
    if(Tree[rt].col != -1) {
        Tree[rt << 1].col = Tree[rt << 1 | 1].col = Tree[rt].col;
        Tree[rt].col = -1;
    }
}

void build(int rt, int l, int r) {
    Tree[rt].l = l;
    Tree[rt].r = r;
    Tree[rt].col = -1;
    if(l == r){ 
        return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
}

void update(int rt, int l, int r, int c) {
    pushdown(rt);
    if(Tree[rt].l >= l && Tree[rt].r <= r) {
        Tree[rt].col = c;
        return;
    }
    if(Tree[rt].col == c) 
        return;
    pushdown(rt);
    int mid = (Tree[rt].l + Tree[rt].r) >> 1;
    if(mid >= l)
        update(rt << 1, l, r, c);
    if(mid < r)
        update(rt << 1 | 1, l, r, c);
}

void query(int rt, int l, int r) {
    if(Tree[rt].col >= 0) {
        for(int i = Tree[rt].l; i <= Tree[rt].r; i++) {
            vis[i] = Tree[rt].col;
        }
        return;
    }
    if(Tree[rt].l == Tree[rt].r || Tree[rt].col != -1) 
        return;
    query(rt << 1, l, r);
    query(rt << 1 | 1, l, r);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int n, x1, x2, c;
    while(~scanf("%d", &n)) {
        build(1, 1, 8000);
        while(n--) {
            scanf("%d %d %d", &x1, &x2, &c);
            if(x1 >= x2)
                continue;
            update(1, x1 + 1, x2, c);
        }
        memset(vis, -1, sizeof(vis));
        memset(ans, 0, sizeof(ans));
        query(1, 1, 8000);
        int i = 0; 
        while(i < MAXN) {
            int color = vis[i], j = i;
            if(vis[i] == -1) {
                i++;
                continue;
            }
            while(vis[j] != -1 && vis[j] == color && j < MAXN) j++;
            ++ans[color];
            i = j;
        }
        for(int i = 0; i < MAXN; i++) {
            if(ans[i])
                printf("%d %d\n", i, ans[i]);
        }
        puts("");
    }
    return 0;
}

