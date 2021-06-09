#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 2005;

int a[MAXN], b[MAXN], dp[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    int mmin;
    for(int i = 1; i <= n; i++) {
        mmin = 0x3f3f3f3f;
        for(int j = 1; j <= n; j++) {
            mmin = min(mmin, dp[j]);
            dp[j] = abs(b[j] - a[i]) + mmin;
        }
    }
    mmin = dp[1];
    for(int i = 2; i <= n; i++)
        mmin = min(mmin, dp[i]);
    printf("%d\n", mmin);
    return 0;
}
