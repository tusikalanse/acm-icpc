/*
 * @Author: tusikalanse
 * @Date: 2021-07-07 22:19:08
 * @LastEditTime: 2021-07-07 22:20:41
 * @LastEditors: tusikalanse
 * @Description:
 * @FilePath: /ProjectEuler/28.cpp
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

const int N = 1001;

LL ans = 0;
int p = 2, x = 1;

int main() {
    ans = 1;
    for (int i = 3; i <= 1001; i += 2) {
        for (int _ = 0; _ < 4; ++_) {
            x += p;
            ans += x;
        }
        p += 2;
    }
    cout << ans << endl;
    return 0;
}
