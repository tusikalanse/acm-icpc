#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, m, _tot, head[N];
int fa[N][20], dep[N];
int tot, T[N], ls[N * 20], rs[N * 20], sum[N * 20];
vector<int> vec;

struct Edge {
  int v, w, nxt;
} edge[N << 1];

inline void add(int u, int v, int w) {
  edge[_tot].v = v;
  edge[_tot].w = w;
  edge[_tot].nxt = head[u];
  head[u] = _tot++;
}

void update(int pre, int &t, int l, int r, int p) {
  ls[t = ++tot] = ls[pre], rs[t] = rs[pre], sum[t] = sum[pre] + 1;
  if (l == r) return;
  int m = l + r >> 1;
  if (p <= m) update(ls[pre], ls[t], l, m, p);
  else update(rs[pre], rs[t], m + 1, r, p);
}

inline int id(int x) {
  return lower_bound(vec.begin(), vec.end(), x) - vec.begin() + 1;
}

void dfs(int u, int p, int k) {
  fa[u][0] = p; dep[u] = dep[p] + 1;
  update(T[p], T[u], 1, n, k);
  for (int i = 0; i < 19; ++i)
    fa[u][i + 1] = fa[fa[u][i]][i];
  for (int i = head[u]; ~i; i = edge[i].nxt) {
    int v = edge[i].v, w = edge[i].w;
    if (v != p) dfs(v, u, id(w));
  }
}

int lca(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  for (int i = 19; i >= 0; --i)
    if (dep[fa[x][i]] >= dep[y])
      x = fa[x][i];
  if (x == y) return x;
  for (int i = 19; i >= 0; --i)
    if (fa[x][i] != fa[y][i])
      x = fa[x][i], y = fa[y][i];
  return fa[x][0];
}

int query(int x, int y, int z, int L, int R, int l, int r) {
  if (L <= l && r <= R) return sum[x] + sum[y] - 2 * sum[z];
  int m = l + r >> 1, res = 0;
  if (L <= m) res += query(ls[x], ls[y], ls[z], L, R, l, m);
  if (R > m) res += query(rs[x], rs[y], rs[z], L, R, m + 1, r);
  return res;
}

int main() {
  scanf("%d%d", &n, &m);
  memset(head, -1, sizeof(head));
  for (int i = 1, u, v, w; i < n; ++i) {
    scanf("%d%d%d", &u, &v, &w);
    add(u, v, w);
    add(v, u, w);
    vec.push_back(w);
  }
  sort(vec.begin(), vec.end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
  n = vec.size();
  dfs(1, 0, 1);
  while (m--) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    w = upper_bound(vec.begin(), vec.end(), w) - vec.begin();
    if (w < 1) {
      printf("%d\n", 0);
      continue;
    }
    printf("%d\n", query(T[u], T[v], T[lca(u, v)], 1, w, 1, n));
  }
  return 0;  
}