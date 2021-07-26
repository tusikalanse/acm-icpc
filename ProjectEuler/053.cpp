/*
 * @Author: tusikalanse
 * @Date: 2021-07-10 10:06:19
 * @LastEditTime: 2021-07-10 10:08:26
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
    for (int n = 1; n <= 100; ++n) {
        int now = 1;
        for (int r = 1; 2 * r <= n; ++r) {
            now *= n - r + 1;
            now /= r;
            if (now > 1000000) {
                ans += n - r - r + 1;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}