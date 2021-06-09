/*
 * @Author: tusikalanse
 * @Date: 2021-06-09 19:43:09
 * @LastEditTime: 2021-06-09 19:44:49
 * @LastEditors: tusikalanse
 * @Description: Sum square difference
 * @FilePath: /undefined/mnt/e/algo/ProjectEuler/6.cpp
 */
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}

LL sum(LL x) {
    return x * (x + 1) * (2 * x + 1) / 6;
}

LL sum1(LL x) {
    LL y = x * (x + 1) / 2;
    return y * y;
}

int main() {
    cout << sum(10) << " " << sum1(10) << endl;
    cout << sum(100) << " " << sum1(100) << endl;
    cout << sum1(100) - sum(100) << endl;

    return 0;
}
