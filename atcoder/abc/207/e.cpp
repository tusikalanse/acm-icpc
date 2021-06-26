/*
 * @Author: tusikalanse
 * @Date: 2021-06-26 19:49:09
 * @LastEditTime: 2021-06-26 20:46:48
 * @LastEditors: tusikalanse
 * @Description: 
 * @FilePath: /atcoder/abc/207/e.cpp
 */
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
//-------------------end head--------------

const int N = 3010;

LL dp[N][N];
LL sum[N][N];
LL a[N], n, s[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    } 
    for (int i = 1; i <= n; ++i) {
        dp[i][1] = 1;
        for (int j = 1; j < i; ++j) {
            dp[i][j + 1] = sum[s[i] % (j + 1)][j];
        }
        for (int j = 1; j <= i; ++j) {
            (sum[s[i] % (j + 1)][j] += dp[i][j]) %= mod;
        }
    }
    LL ans = 0;
    for (int j = 1; j <= n; ++j)
        (ans += dp[n][j]) %= mod;
    cout << ans << endl;
    return 0;
}
