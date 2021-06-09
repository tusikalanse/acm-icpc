#include <bits/stdc++.h>
using namespace std;

int dir[4][2] = {0, 1, 0, -1, -1, 0, 1, 0};
int a[105][105], dp[105][105];
int n, k;

int Judge(int x, int y) {
    return x > 0 && x <= n && y > 0 && y <= n;
}

int dfs(int x, int y) {
    int mmax = 0;
    if(dp[x][y])
        return dp[x][y];
    for(int i = 0; i < 4; i++) {
        for(int j = 1; j <= k; j++) {
            int fx = x + j * dir[i][0], fy = y + j * dir[i][1];
            if(Judge(fx, fy) && a[fx][fy] > a[x][y]) {
                mmax = max(mmax, dfs(fx, fy));
            }
        }
    }
    return dp[x][y] = mmax + a[x][y];
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    while(~scanf("%d %d", &n, &k) && ~n) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                scanf("%d", &a[i][j]);
                dp[i][j] = 0;
            }
        }
    printf("%d\n", dfs(1, 1));
    }
    return 0;
}
