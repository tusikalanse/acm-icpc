/*
 * @Description: 
 * @Version: 2.0
 * @Autor: tusikalanse
 * @Date: 2021-07-24 19:55:37
 * @LastEditors: tusikalanse
 * @LastEditTime: 2021-07-24 20:10:44
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, mod = 1e9 + 7;

char s[N];
long long dp[N][10];

char t[12] = " chokudai";
int n;

int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = 1;
        for (int j = 1; j <= 8; ++j)
            dp[i][j] = dp[i - 1][j];
        for (int j = 1; j <= 8; ++j)
            if (s[i] == t[j]) {
                dp[i][j] += dp[i][j - 1];
                dp[i][j] %= mod;
            }
    }
    printf("%lld\n", dp[n][8]);
    return 0;
}