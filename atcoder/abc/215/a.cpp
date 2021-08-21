/*
 * @Description: 
 * @Version: 2.0
 * @Autor: tusikalanse
 * @Date: 2021-08-21 19:52:17
 * @LastEditors: tusikalanse
 * @LastEditTime: 2021-08-21 20:01:45
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

string s, t;
int main() {
    cin >> s;
    t = "Hello,World!";
    if (s == t) 
        cout << "AC" << endl;
    else
        cout << "WA" << endl;
    return 0;
}