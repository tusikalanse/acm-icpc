#include <bits/stdc++.h>
using namespace std;

char g[1005][1005];
int dp[1005][1005];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, up, right, temp, mmax;
    while(~scanf("%d", &n) && n) {
        mmax = 0;
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i++) {
            scanf("%s", g[i] + 1);
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                dp[i][j] = 1;
                up = i, right = j;
                while(g[up][j] == g[i][right]) {
                    up--;
                    right++;
                    if(up < 1 || right > n) 
                        break;
                }
                temp = i - up;
                if(temp > dp[i-1][j+1])
                    dp[i][j] = dp[i-1][j+1] + 1;
                else
                    dp[i][j] = temp;
                mmax = max(mmax, dp[i][j]);
                }
        }
        printf("%d\n", mmax);
    }
    return 0;
}

