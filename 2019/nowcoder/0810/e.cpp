#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 10;
 
int u[N], v[N], l[N], r[N], b[N << 1], n, m, tot, fa[N], sz[N];
vector<int> g[N << 3];
stack<pair<int*, int>> stk[22];
long long ans;
 
int find(int x) {
    return x== fa[x] ? x : find(fa[x]);
}
 
void update(int rt, int l, int r, int L, int R, int id) {
    if(L <= l && r <= R) {g[rt].push_back(id); return;}
    int mid = l + r >> 1;
    if(L <= mid) update(rt << 1, l, mid, L, R, id);
    if(R > mid) update(rt << 1 | 1, mid + 1, r, L, R, id);
}
 
void dfs(int rt, int l, int r, int dep) {
    while(!stk[dep].empty()) stk[dep].pop();
    for(auto i: g[rt]) {
        int x = find(u[i]), y = find(v[i]);
        if(x == y) continue;
        if(sz[x] < sz[y]) swap(x, y);
        stk[dep].push(make_pair(&sz[x], sz[x]));
        stk[dep].push(make_pair(&fa[y], fa[y]));
        sz[x] += sz[y];
        fa[y] = x;
    }
    if(l == r) {
        if(find(1) == find(n))
            ans += b[r + 1] - b[l];
    }
    else {
        int mid = l + r >> 1;
        dfs(rt << 1, l, mid, dep + 1);
        dfs(rt << 1 | 1, mid + 1, r, dep + 1);
    }
    while(!stk[dep].empty()) {
        *(stk[dep].top().first) = stk[dep].top().second;
        stk[dep].pop();
    }
}
 
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; ++i) {
        scanf("%d%d%d%d", &u[i], &v[i], &l[i], &r[i]);
        b[2 * i - 1] = l[i];
        b[2 * i] = ++r[i];
    }
    sort(b + 1, b + 2 * m + 1);
    tot = unique(b + 1, b + 2 * m + 1) - b - 1;
    for(int i = 1; i <= m; ++i) {
        l[i] = lower_bound(b + 1, b + tot + 1, l[i]) - b;
        r[i] = lower_bound(b + 1, b + tot + 1, r[i]) - b - 1;
        update(1, 1, tot, l[i], r[i], i);
    }
    for(int i = 1; i <= n; ++i) fa[i] = i, sz[i] = 1;
    dfs(1, 1, tot, 0);
    printf("%lld\n", ans);
    return 0;
}