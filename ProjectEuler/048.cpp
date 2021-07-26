/*
 * @Author: tusikalanse
 * @Date: 2021-07-09 21:07:38
 * @LastEditTime: 2021-07-09 21:17:18
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
const LL mod = 1e10;
//-------------------end head--------------

LL mul(LL a, LL n) {
    LL res = 0;
    while (n) {
        if (n & 1)
            res = (res + a) % mod;
        a = (a + a) % mod;
        n >>= 1;
    }
    return res;
}

LL qp(LL a, LL n) {
    LL res = 1;
    while (n) {
        if (n & 1)
            res = mul(res, a) % mod;
        a = mul(a, a) % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    LL ans = 0;
    for (int i = 1; i <= 1000; ++i) {
        ans = (ans + qp(i, i)) % mod;
        cout << i << endl;
    }
    cout << ans << endl;
    return 0;
}