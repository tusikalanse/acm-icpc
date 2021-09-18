/*
 * @Author: tusikalanse
 * @Date: 2021-09-18 19:51:42
 * @LastEditTime: 2021-09-18 20:02:39
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

string s[5], T;

int main() {
    cin >> s[1] >> s[2] >> s[3] >> T;
    for (int i = 0; i < T.size(); ++i) {
        cout << s[T[i] - '0'];
    }
    cout << endl;
    return 0;
}