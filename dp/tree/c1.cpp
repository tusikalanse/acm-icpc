#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;

struct Edge {
    int x, y, z;
    bool operator < (const Edge &rhs) const {
        return z > rhs.z;
    }
}edge[MAXN];

int fa[MAXN], flag[MAXN];

int Find(int x) {
    return x == fa[x] ? x : fa[x] = Find(fa[x]);
}

void Unite(int x, int y) {
    int fx = Find(x), fy = Find(y);
    if(fx != fy)
        fa[fx] = fy;
    return;
}

int main() {
    int t, n, k, id;
    scanf("%d", &t);
    while(t--) {
        long long ans = 0;
        scanf("%d %d", &n, &k);
        for(int i = 0; i < MAXN; i++) {
            fa[i] = i;
            flag[i] = 0;
        }
        for(int i = 0; i < n - 1; i++) {
            scanf("%d %d %d", &edge[i].x, &edge[i].y, &edge[i].z);
        }
        sort(edge, edge + n - 1);
        for(int i = 0; i < k; i++) {
            scanf("%d", &id);
            flag[id] = 1;
        }
        for(int i = 0; i < n - 1; i++) {
            if(flag[Find(edge[i].x)] && flag[Find(edge[i].y)])
                ans += edge[i].z;
            else if(flag[Find(edge[i].x)])
                Unite(Find(edge[i].y), Find(edge[i].x));
            else 
                Unite(Find(edge[i].x), Find(edge[i].y));
        }
        printf("%lld\n", ans);
    }
    return 0;
}
