#include <bits/stdc++.h>
using namespace std;

const int N = 510;

int mp[N * 2][N * 2], sx, sy, ex, ey, x, y, n;
int dp[N * 2][N * 2];
int dir[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};

int main() {
    scanf("%d%d%d", &ex, &ey, &n);
    ex += N;
    ey += N;
    sx = sy = N;
    for(int i = 1; i <= n; ++i) {
        scanf("%d%d", &x, &y);
        mp[x + N][y + N] = 1;
    }
    queue<pair<int, int>> bfs;
    bfs.push(make_pair(sx, sy));
    memset(dp, -1, sizeof(dp));
    dp[sx][sy] = 0;
    while(!bfs.empty()) {
        pair<int, int> u = bfs.front();
        bfs.pop();
        if(u.first == ex && u.second == ey) break;
        //cout << u.first << " " << u.second << endl;
        for(int k = 0; k < 4; ++k) {
            x = u.first + dir[k][0];
            y = u.second + dir[k][1];
            if(x < 0 || x >= N * 2 || y < 0 || y >= N * 2 || mp[x][y] == 1 || dp[x][y] != -1) continue;
            dp[x][y] = dp[u.first][u.second] + 1;
            bfs.push(make_pair(x, y));
        }
    }
    printf("%d\n", dp[ex][ey]);
    return 0;
}