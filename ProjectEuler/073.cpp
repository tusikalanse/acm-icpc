/*
 * @Author: tusikalanse
 * @Date: 2021-07-15 19:17:22
 * @LastEditTime: 2021-07-15 19:21:22
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

int main() {
    int ans = 0;
    for (int d = 5; d <= 12000; ++d) {
        int x = d / 3 + 1;
        int y = d / 2;
        for (int i = x; i <= y; ++i) {
            if (gcd(i, d) == 1)
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
