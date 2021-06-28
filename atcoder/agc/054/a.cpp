/*
 * @Author: tusikalanse
 * @Date: 2021-06-28 23:28:35
 * @LastEditTime: 2021-06-28 23:34:10
 * @LastEditors: tusikalanse
 * @Description: 
 * @FilePath: /atcoder/agc/054/a.cpp
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
    int n;
    string s;
    cin >> n >> s;
    if (s[0] != s[n - 1]) {
        cout << "1" << endl;
        return 0;
    }
    for (int i = 1; i + 2 < n; ++i) {
        if (s[i] != s[0] && s[i + 1] != s[0]) {
            cout << "2" << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
    return 0;
}
