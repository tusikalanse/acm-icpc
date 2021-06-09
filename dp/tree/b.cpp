#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100010;

struct Edge {
    int pnt, nxt;
}edge[MAXN*2];

int vis[MAXN], head[MAXN], dp[MAXN][2], cnt = 0;

void AddEdge(int x, int y) {
    edge[cnt].pnt = y;
    edge[cnt].nxt = head[x];
    head[x] = cnt++;
    edge[cnt].pnt = x;
    edge[cnt].nxt = head[y];
    head[y] = cnt++;
}

void dfs(int u, int p) {
    if(vis[u]) 
        return;
    vis[u] = 1;
    dp[u][0] = 0;
    dp[u][1] = 1;
    for(int i = head[u]; ~i; i = edge[i].nxt) {
        int j = edge[i].pnt;
        if(j == p)
            continue;
        dfs(j, u);
        dp[u][0] += dp[j][1];
        dp[u][1] += min(dp[j][0], dp[j][1]);
    }
    return;
}

int main() {
    int n, x, y;
    cnt = 0;
    memset(head, -1, sizeof(head));
    memset(vis, 0, sizeof(vis));
    scanf("%d", &n);
    while(--n) {
        scanf("%d %d", &x, &y);
        AddEdge(x, y);
    }
    dfs(1, 0);
    printf("%d\n", min(dp[1][0], dp[1][1]));
    return 0;
}
