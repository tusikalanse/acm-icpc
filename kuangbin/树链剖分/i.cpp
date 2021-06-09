#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10010;

int size[MAXN], top[MAXN], fa[MAXN], son[MAXN], dep[MAXN], dfn[MAXN], rnk[MAXN], cnt, root;
int head[MAXN], pnt[MAXN << 1], nxt[MAXN << 1], val[MAXN << 1], num;
int mx[MAXN << 2];
int seg[MAXN][3];
int T, n, a, b, c;
char ch[20];

void add(int x, int y, int v) {
    pnt[num] = y;
    val[num] = v;
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
    mx[rt] = max(mx[rt << 1], mx[rt << 1 | 1]);
}

void build(int rt, int l, int r) {
    if(l == r) {
        mx[l] = 0;
        return;
    }
    int mid = l + r >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    // pushup(rt);
}

int query(int rt, int l, int r, int L, int R) {
    if(L <= l && r <= R) {
        return mx[rt];
    }
    int ans = 0, mid = l + r >> 1;
    if(mid >= L) 
        ans = max(ans, query(rt << 1, l, mid, L, R));
    if(mid < R)
        ans = max(ans, query(rt << 1 | 1, mid + 1, r, L, R));
    return ans;
}

void update(int rt, int l, int r, int pos, int val) {
    if(l == r) {
        mx[rt] = val;
        return;
    }
    int mid = l + r >> 1;
    if(mid >= pos)
        update(rt << 1, l, mid, pos, val);
    else
        update(rt << 1 | 1, mid + 1, r, pos, val);
    pushup(rt);
}

void init() {
    scanf("%d", &n);
    num = cnt = 1;
    root = 1;
    memset(head, -1, sizeof(head));
    build(1, 1, n);
    for(int i = 1; i < n; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        seg[i][0] = a;  seg[i][1] = b; seg[i][2] = c;
        add(a, b, c); add(b, a, c);
    }
    dfs1(root, 0, 1);
    dfs2(root, root);
    for(int i = 1; i < n; ++i) {
        if(dep[seg[i][0]] > dep[seg[i][1]])
            swap(seg[i][0], seg[i][1]);
        update(1, 1, cnt - 1, dfn[seg[i][1]], seg[i][2]);
    }
}

int find(int va, int vb) {
    int f1 = top[va], f2 = top[vb], ans = 0;
    while(f1 != f2) {
        if(dep[f1] < dep[f2]) 
            swap(va, vb), swap(f1, f2);
        ans = max(ans, query(1, 1, n, dfn[f1], dfn[va]));
        va = fa[f1];
        f1 = top[va];
    }
    if(va == vb) return ans;
    if(dep[va] > dep[vb]) swap(va, vb);
    return max(ans, query(1, 1, n, dfn[son[va]], dfn[vb]));
}

void solve() {
    while(1) {
        scanf("%s", ch);
        if(ch[0] == 'D')
            break;
        scanf("%d%d", &a, &b);
        if(ch[0] == 'Q') {
            printf("%d\n", find(a, b));
        }
        else {
            update(1, 1, n, dfn[seg[a][1]], b);
        }
    }
}

int main() {
    scanf("%d", &T);
    while(T--) {
        init();
        solve();
    }
    return 0;
}