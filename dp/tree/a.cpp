#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

struct Edge {
    int pnt, nxt, val;
}edge[20010];

int head[10010], cnt = 0, vis[10010];

void Add_Edge(int x, int y, int v) {
    edge[cnt].val = v;
    edge[cnt].pnt = y;
    edge[cnt].nxt = head[x];
    head[x] = cnt++;
    edge[cnt].val = v;
    edge[cnt].pnt = x;
    edge[cnt].nxt = head[y];
    head[y] = cnt++;
    return;
}

int dfs(int x, int &ans) {
    int mmax = 0;
    for(int i = head[x]; ~i; i = edge[i].nxt) {
        int j = edge[i].pnt;
        if(!vis[j]) {
            vis[j] = 1;
            int tmp = dfs(j, ans) + edge[i].val;
            vis[j] = 0;
            ans = max(ans, tmp + mmax);
            mmax = max(mmax, tmp);
        }
    }
    return mmax;
}

int main() {
    memset(head, -1, sizeof(head));
    memset(vis, 0, sizeof(vis));
    cnt = 0;
    int x, y, v;
    while(~scanf("%d %d %d", &x, &y, &v)) {
        Add_Edge(x, y, v);
    }
    int ans = 0;
    vis[1] = 1;
    dfs(1, ans);
    printf("%d\n", ans);
    return 0;
}
