/*
 * @Author: tusikalanse
 * @Date: 2021-07-09 08:50:23
 * @LastEditTime: 2021-07-09 08:53:12
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

int fact[10];

int gao(int x) {
    int ret = 0;
    while (x) {
        ret += fact[x % 10];
        x /= 10;
    }
    return ret;
}

int main() {
    fact[0] = 1;
    for (int i = 1; i <= 9; ++i)
        fact[i] = i * fact[i - 1];
    LL ans = 0;
    for (int i = 10; i <= 10000000; ++i) {
        if (gao(i) == i)
            ans += i;
    }
    cout << ans << endl;
    return 0;
}