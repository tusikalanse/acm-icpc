#include <bits/stdc++.h>
using namespace std;

int dp[200], a[200], b[200];

int main() {
    int n, m;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) 
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    scanf("%d", &m);
    for(int i = 1; i <= m; i++) 
        scanf("%d", &b[i]);
    sort(b + 1, b + m + 1);
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; i++) {
        int start = i - 1;
        while(dp[start] == 0 && start != 0) start--;
        for(int j = dp[start] + 1; j <= m; j++) {
            if(b[j] == a[i] - 1 || b[j] == a[i] || b[j] == a[i] + 1){
                dp[i] = j;
                break;
            }
            else if(b[j] > a[i] + 1)
                break;
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(dp[i])
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}
