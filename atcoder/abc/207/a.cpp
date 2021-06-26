/*
 * @Author: tusikalanse
 * @Date: 2021-06-26 19:37:36
 * @LastEditTime: 2021-06-26 20:01:01
 * @LastEditors: tusikalanse
 * @Description: 
 * @FilePath: /atcoder/abc/207/a.cpp
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
    int a, b, c;
    cin >> a >> b >> c;
    cout << max(a + b, max(a + c, b + c)) << endl;


    return 0;
}
