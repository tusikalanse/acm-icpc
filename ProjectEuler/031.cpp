/*
 * @Author: tusikalanse
 * @Date: 2021-07-08 21:05:41
 * @LastEditTime: 2021-07-08 21:09:19
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

int a[10] = {0, 1, 2, 5, 10, 20, 50, 100, 200};

int dp[210];

int main() {
    dp[0] = 1;
    for (int i = 1; i <= 8; ++i) {
        for (int j = a[i]; j <= 200; ++j)
            dp[j] += dp[j - a[i]];
    }
    cout << dp[1] << endl;
    cout << dp[2] << endl;
    cout << dp[200] << endl;
    return 0;
}
