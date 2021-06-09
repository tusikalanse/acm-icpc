#include <bits/stdc++.h>
using namespace std;

int dp[4010];

int main() {
    int n, a, b, c;
    scanf("%d%d%d%d", &n, &a, &b, &c);
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        if(i >= a && ~dp[i-a])
            dp[i] = max(dp[i], dp[i-a]+1);
        if(i >= b && ~dp[i-b])
            dp[i] = max(dp[i], dp[i-b]+1);
        if(i >= c && ~dp[i-c])
            dp[i] = max(dp[i], dp[i-c]+1);
    }
    printf("%d\n", dp[n]);

    return 0;
}
