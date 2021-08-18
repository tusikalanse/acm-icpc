/*
 * @Author: tusikalanse
 * @Date: 2021-08-18 09:02:09
 * @LastEditTime: 2021-08-18 09:14:19
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

int m = 50, limit = 1'000'000;

LL getval(int n, int m) {
    vector<vector<LL>> dp(n + 1, vector<LL>(2, 0));
    dp[0][1] = 1;
    for (int i = 1; i <= n; ++i) {
        dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
        for (int j = i - m; j >= 0; --j) {
            dp[i][0] += dp[j][1];
        }
    }
    return dp[n][0] + dp[n][1];
}

int main() {
    int l = 50, r = 200, ans = 0;
    while (l <= r) {
        int mid = l + r >> 1;
        if (getval(mid, m) >= limit) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << endl;
    cout << getval(ans, 50) << endl;
    return 0;
}