/*
 * @Author: tusikalanse
 * @Date: 2021-07-08 12:40:28
 * @LastEditTime: 2021-07-08 12:43:12
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /undefined/root/acm-icpc/ProjectEuler/30.cpp
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

int fifthpower(int x) {
    return x * x * x * x * x;
}

int main() {
    int ans = 0;
    for (int i = 2; i <= 354294; ++i) {
        int x = i, sum = 0;
        while (x) {
            sum += fifthpower(x % 10);
            x /= 10;
        }
        if (sum == i)
            ans += i;
    }
    cout << ans << endl;
    return 0;
}
