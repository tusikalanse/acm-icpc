/*
 * @Author: tusikalanse
 * @Date: 2021-07-15 07:55:34
 * @LastEditTime: 2021-07-15 07:59:39
 * @LastEditors: tusikalanse
 * @Description: 
 * @FilePath: /ProjectEuler/71.cpp
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

int numerator = 2, denominator = 5;

int main() {
    for (int d = 9; d <= 1000000; ++d) {
        int x = 3 * d / 7;
        while (gcd(x, d) != 1)
            x--;
        if (1LL * x * denominator > 1LL * d * numerator) {
            numerator = x;
            denominator = d;
        }
    }
    cout << numerator << " / " << denominator << endl;
    return 0;
}
