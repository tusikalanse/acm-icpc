/*
 * @Author: tusikalanse
 * @Date: 2021-06-13 19:31:42
 * @LastEditTime: 2021-06-13 20:02:10
 * @LastEditors: tusikalanse
 * @Description: 
 * @FilePath: /undefined/mnt/e/algo/atcoder/abc/205/a.cpp
 */
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int a, b;
    cin >> a >> b;
    if (b)
        cout << a * b / 100.0 << endl;
    else
        cout << 0 << endl;
    return 0;
}
