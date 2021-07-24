/*
 * @Description: 
 * @Version: 2.0
 * @Autor: tusikalanse
 * @Date: 2021-07-24 19:55:37
 * @LastEditors: tusikalanse
 * @LastEditTime: 2021-07-24 20:16:57
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10, mod = 1e9 + 7;

vector<int> G[N];
int n, m, a, b;
int dp[N], dis[N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dp[1] = 1;
    queue<int> bfs;
    bfs.push(1);
    dis[1] = 1;
    while(!bfs.empty()) {
        int u = bfs.front();
        bfs.pop();
        for (int to: G[u]) {
            if (dis[to] == 0 || dis[to] == dis[u] + 1) {
                if (dp[to] == 0) {
                    bfs.push(to);
                }
                dis[to] = dis[u] + 1;
                dp[to] += dp[u];
                dp[to] %= mod;
            }
        }
    }
    for (int i = n; i <= n; ++i)
        printf("%d\n", dp[i]);
    return 0;
}