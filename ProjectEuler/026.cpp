/*
 * @Author: tusikalanse
 * @Date: 2021-07-01 20:26:55
 * @LastEditTime: 2021-07-13 17:49:43
 * @LastEditors: tusikalanse
 * @Description:
 * @FilePath: /ProjectEuler/26.cpp
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

int getperiodlength(int d) {
    map<pair<int, int>, int> m;
    int quotient = 0;
    int remainder = 1;
    int digit = 0;
    while (++digit) {
        remainder *= 10;
        quotient = remainder / d;
        remainder %= d;
        if (m[{quotient, remainder}])
            return digit - m[{quotient, remainder}];
        m[{quotient, remainder}] = digit;
    }
    return 0;
}

int main() {
    int ans = 0, id = 0;
    for (int i = 2; i < 1000; ++i) {
        if (getperiodlength(i) > ans) {
            ans = getperiodlength(i);
            id = i;
        }
    }
    cout << id << endl;
    return 0;
}
