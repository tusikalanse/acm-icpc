/*
 * @Description: 
 * @Version: 2.0
 * @Autor: tusikalanse
 * @Date: 2021-08-14 19:48:48
 * @LastEditors: tusikalanse
 * @LastEditTime: 2021-08-14 20:52:35
 */
#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 1e5 + 10;

int fa[N], sz[N];

int find(int x) {
    return x == fa[x] ? x : find(fa[x]);
}

void unite(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx == fy) return;
    if (sz[fx] < sz[fy]) {
        fa[fx] = fy;
        sz[fy] += sz[fx];
    }
    else {
        fa[fy] = fx;
        sz[fx] += sz[fy];
    }
}

struct edge {
    int x, y, w;
    bool operator < (const edge &rhs) const {
        return w < rhs.w;
    }
}e[N];

int n;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
        sz[i] = 1;
        if (i != n)
            scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].w); 
    }
    sort(e + 1, e + n);
    LL ans = 0;
    for (int i = 1; i < n; ++i) {
        int fx = find(e[i].x), fy = find(e[i].y);
        ans += 1LL * sz[fx] * sz[fy] * e[i].w;
        // cout << e[i].x << " " << e[i].y << " " << fx << " " << fy << " " << sz[fx] << " " << sz[fy] << endl;
        unite(fx, fy);
    }
    printf("%lld\n", ans);
    return 0;
}