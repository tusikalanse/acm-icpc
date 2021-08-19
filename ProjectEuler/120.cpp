/*
 * @Author: tusikalanse
 * @Date: 2021-08-19 19:27:33
 * @LastEditTime: 2021-08-19 19:31:54
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
    for (int i = 3; i <= 1000; ++i) {
        ans += 2 * i * ((i - 1) / 2) % (i * i);
    }
    cout << ans << endl;
    return 0;
}