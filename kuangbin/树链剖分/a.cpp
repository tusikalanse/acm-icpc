#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50010;

int size[MAXN], top[MAXN], fa[MAXN], son[MAXN], dep[MAXN], dfn[MAXN], rnk[MAXN], cnt, root;
int head[MAXN], pnt[MAXN << 1], nxt[MAXN << 1], value[MAXN], num;
int sum[MAXN << 2], lazy[MAXN << 2];
int T, n, a, b, c, m;
char ch[20];

void add(int x, int y) {
    pnt[num] = y;
    nxt[num] = head[x];
    head[x] = num++;
}

void dfs1(int u, int pre, int depth) {
    size[u] = 1;
    fa[u] = pre;
    son[u] = -1;
    dep[u] = depth;
    for(int i = head[u]; ~i; i = nxt[i]) if(pnt[i] != pre) {
        int v = pnt[i];
        dfs1(v, u, depth + 1);
        size[u] += size[v];
        if(son[u] == -1 || size[v] > size[son[u]]) 
            son[u] = v;
    }
}

void dfs2(int u, int t) {
    top[u] = t;
    dfn[u] = cnt;
    rnk[cnt] = u;
    cnt++;
    if(son[u] == -1)
        return;
    dfs2(son[u], t);
    for(int i = head[u]; ~i; i = nxt[i]) {
        int v = pnt[i];
        if(v != fa[u] && v != son[u])
            dfs2(v, v);
    }
}

void pushup(int rt) {
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void pushdown(int rt, int l, int r) {
    if(lazy[rt]) {
        int mid = l + r >> 1;
        lazy[rt << 1] += lazy[rt];
        lazy[rt << 1 | 1] += lazy[rt];
        sum[rt << 1] += lazy[rt] * (mid - l + 1);
        sum[rt << 1 | 1] += lazy[rt] * (r - mid);
        lazy[rt] = 0;
    }
}

void build(int rt, int l, int r) {
    lazy[rt] = 0;
    if(l == r) {
        sum[rt] = value[rnk[l]];
        return;
    }
    int mid = l + r >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    // pushup(rt);
}

int query(int rt, int l, int r, int pos) {
    if(l == r) {
        return sum[rt];
    }
    pushdown(rt, l, r);
    int mid = l + r >> 1;
    if(mid >= pos)
        return query(rt << 1, l, mid, pos);
    else
        return query(rt << 1 | 1, mid + 1, r, pos);
}

void update(int rt, int l, int r, int L, int R, int val) {
    if(L <= l && r <= R) {
        lazy[rt] += val;
        sum[rt] += val * (r - l + 1);
        return;
    }
    pushdown(rt, l, r);
    int mid = l + r >> 1;
    if(mid >= L)
        update(rt << 1, l, mid, L, R, val);
    if(mid < R)
        update(rt << 1 | 1, mid + 1, r, L, R, val);
}

void init() {   
    num = cnt = 1;
    root = 1;
    memset(head, -1, sizeof(head));
    for(int i = 1; i <= n; ++i)
        scanf("%d", &value[i]);
    for(int i = 1; i < n; ++i) {
        scanf("%d%d", &a, &b);
        add(a, b); add(b, a);
    }
    dfs1(root, 0, 1);
    dfs2(root, root);
    build(1, 1, n);
}

void change(int va, int vb, int val) {
    int f1 = top[va], f2 = top[vb], ans = 0;
    while(f1 != f2) {
        if(dep[f1] < dep[f2]) 
            swap(va, vb), swap(f1, f2);
        update(1, 1, n, dfn[f1], dfn[va], val);
        va = fa[f1];
        f1 = top[va];
    }
    if(dep[va] > dep[vb]) swap(va, vb);
    return update(1, 1, n, dfn[va], dfn[vb], val);
}

void solve() {
    while(m--) {
        scanf("%s", ch);
        if(ch[0] == 'Q') {
            scanf("%d", &a);
            printf("%d\n", query(1, 1, n, dfn[a]));
        }
        else {
            scanf("%d%d%d", &a, &b, &c);
            change(a, b, (ch[0] == 'I' ? 1 : -1) * c);
        }
    }
}

int main() {
    while(~scanf("%d%*d%d", &n, &m)) {
        init();
        solve();
    }
    return 0;
}