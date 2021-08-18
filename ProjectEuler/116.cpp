/*
 * @Author: tusikalanse
 * @Date: 2021-08-18 09:02:09
 * @LastEditTime: 2021-08-18 09:34:43
 * @LastEditors: tusikalanse
 * @Description:
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

const int N = 55;
LL dp[N][3];
int n = 50;

int main() {
    dp[0][0] = dp[0][1] = dp[0][2] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 3; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (i - j - 2 >= 0) {
                dp[i][j] += dp[i - j - 2][j];
            }
        }
    }
    cout << dp[50][0] + dp[50][1] + dp[50][2] - 3 << endl;
    return 0;
}