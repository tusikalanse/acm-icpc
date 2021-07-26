/*
 * @Author: tusikalanse
 * @Date: 2021-07-09 20:23:01
 * @LastEditTime: 2021-07-09 20:25:13
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


int main() {
    string x = ".";
    int cnt = 1;
    while (x.size() <= 1000000) {
        x += to_string(cnt++);
    }
    cout << x[1] << endl;
    cout << x[10] << endl;
    cout << x[100] << endl;
    cout << x[1000] << endl;
    cout << x[10000] << endl;
    cout << x[100000] << endl;
    cout << x[1000000] << endl;
    return 0;
}