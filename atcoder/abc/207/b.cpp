/*
 * @Author: tusikalanse
 * @Date: 2021-06-26 19:48:54
 * @LastEditTime: 2021-06-26 20:04:29
 * @LastEditors: tusikalanse
 * @Description: 
 * @FilePath: /atcoder/abc/207/b.cpp
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
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b >= d * c) {
        cout << -1 << endl;
        return 0;
    }
    cout << 1 + (a - 1) / (d * c - b) << endl;

    return 0;
}
