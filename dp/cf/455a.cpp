#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;

int a[MAXN]; 
long long dp[MAXN];
int cnt[MAXN];

int main() {
    int n;
    scanf("%d", &n);
    int nmax = 0;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        nmax = max(nmax, a[i]);
        cnt[a[i]]++;
    }
    long long mmax = 0;
    dp[1] = cnt[1];
    for(int i = 2; i <= nmax; i++) {
        dp[i] = mmax + 1LL * cnt[i] * i;
        mmax = max(dp[i-1], mmax);
    }
    printf("%lld\n", max(dp[nmax], dp[nmax-1]));

    return 0;
}

