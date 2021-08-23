/*
 * @Description: 
 * @Version: 2.0
 * @Autor: tusikalanse
 * @Date: 2021-08-21 19:52:20
 * @LastEditors: tusikalanse
 * @LastEditTime: 2021-08-21 20:29:50
 */
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
//-------------------end head--------------

const int N = 1030;

int dp[N][12][N];

char s[N];
int n;

int main() {
    scanf("%d%s", &n, s + 1);
    dp[0][10][0] = 1;
    for (int i = 1; i <= n; ++i) {
        int v = s[i] - 'A';
        for (int j = 0; j <= 10; ++j) {
            for (int k = 0; k < (1 << 10); ++k) {
                dp[i][j][k] = dp[i - 1][j][k];
            }
        }
        for (int j = 0; j <= 10; ++j) {
            for (int k = 0; k < (1 << 10); ++k) {
                if (j != v && (((k >> v) & 1) == 1)) continue;
                dp[i][v][k | (1 << v)] += dp[i - 1][j][k];
                dp[i][v][k | (1 << v)] %= mod;
            }
        }
    }
    int ans = 0;
    for (int j = 0; j < 10; ++j) {
        for (int k = 0; k < (1 << 10); ++k) {
            ans += dp[n][j][k];
            ans %= mod;
        }
    }
    printf("%d\n", ans);
    return 0;
}