/*
 * @Author: tusikalanse
 * @Date: 2021-06-09 19:36:52
 * @LastEditTime: 2021-06-09 19:42:27
 * @LastEditors: tusikalanse
 * @Description: Smallest multiple
 * @FilePath: /undefined/mnt/e/algo/ProjectEuler/5.cpp
 */
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    LL ans = 1;
    for (int i = 2; i <= 20; ++i)
        ans = ans / gcd(ans, i) * i;
    cout << ans << endl;
    return 0;
}
