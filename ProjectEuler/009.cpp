/*
 * @Author: tusikalanse
 * @Date: 2021-06-25 21:38:43
 * @LastEditTime: 2021-06-25 21:39:54
 * @LastEditors: tusikalanse
 * @Description: a+b+c=1000, aa+bb=cc
 * @FilePath: /ProjectEuler/9.cpp
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
    for (int a = 0; a <= 1000; ++a) {
        for (int b = a + 1; b <= 1000; ++b) {
            int c = 1000 - a - b;
            if (a * a + b * b == c * c)
                cout << a << " " << b << " " << c << " " << a * b * c << endl;
        }
    }

    return 0;
}
