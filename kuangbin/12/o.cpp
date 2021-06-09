#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[2005], dp[2005][2005];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        dp[i][i] = a[i] * n;        
    }
    for(int len = 1; len < n; len++) {
        for(int i = 1; i + len <= n; i++) {
            int j = i + len;
            dp[i][j] = max(dp[i+1][j] + a[i] * (n - len), dp[i][j-1] + a[j] * (n - len));
        }
    }
    printf("%d\n", dp[1][n]);
    return 0;
}
