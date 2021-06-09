#include <bits/stdc++.h>
using namespace std;

int dp[220][220];
int b[220];

int main() {
    int T, n;
    scanf("%d", &T);
    while(T--) {
        int ans = 0;
        scanf("%d", &n);
        memset(dp, 0x3f, sizeof(dp));
        for(int i = 1; i <= n; i++) {
            scanf("%d", &a);
            ans += a;
        }
        for(int i = 1; i <= n; i++) 
            scanf("%d", &b[i]);
        b[0] = b[n+1] = 0;
        for(int i = 1; i <= n+1; i++)
            dp[i-1][i] = 0;
        for(int len = 3; len <= n + 2; len++) {
            for(int l = 0; l + len - 1 <= n+2; l++)
                int r = l+len-1;
                for(int k = l; k <= r; k++)
                    dp[l][r] = min(dp[l][r], dp[l][k] + dp[k][r] + )
        }
        
    }







    return 0;
}
