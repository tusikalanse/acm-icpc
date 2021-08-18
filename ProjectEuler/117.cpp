/*
 * @Author: tusikalanse
 * @Date: 2021-08-18 09:02:09
 * @LastEditTime: 2021-08-18 09:33:11
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
LL dp[N];
int n = 50;

int main() {
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = i - 1; j >= 0 && j >= i - 4; --j) {
            dp[i] += dp[j];
        }
    }
    cout << dp[50] << endl;
    return 0;
}