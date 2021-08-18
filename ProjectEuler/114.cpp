/*
 * @Author: tusikalanse
 * @Date: 2021-08-18 09:02:09
 * @LastEditTime: 2021-08-18 09:06:41
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
LL dp[N][2];
int n = 50;

int main() {
    dp[0][1] = 1;
    for (int i = 1; i <= n; ++i) {
        dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
        for (int j = i - 3; j >= 0; --j) {
            dp[i][0] += dp[j][1];
        }
    }
    cout << dp[7][0] << " " << dp[7][1] << " " << dp[7][0] + dp[7][1] << endl;
    cout << dp[50][0] << " " << dp[50][1] << " " << dp[50][0] + dp[50][1] << endl;
    return 0;
}