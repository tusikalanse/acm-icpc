/*
 * @Author: tusikalanse
 * @Date: 2021-10-25 09:18:51
 * @LastEditTime: 2021-10-25 09:34:36
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


// f(x) = x / (1 - x - x * x)

LL f[40];

int main() {
    f[1] = f[2] = 1;
    for (int i = 3; i < 40; ++i) {
        f[i] = f[i - 1] + f[i - 2];
    }
    for (int k = 1; k <= 15; ++k) {
        cout << f[2 * k] * f[2 * k + 1] << endl;
    }
    return 0;
}