/*
 * @Description: 
 * @Version: 2.0
 * @Autor: tusikalanse
 * @Date: 2021-10-23 14:11:45
 * @LastEditors: tusikalanse
 * @LastEditTime: 2021-10-23 14:13:28
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

const int N = 1e5 + 10;

int T, x, y;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> x >> y;
        if (x >= y) 
            cout << x - y << endl;
        else if ((y - x) % 2 == 0)
            cout << (y - x) / 2 << endl;
        else
            cout << (y + 3 - x) / 2 << endl;
    }
    return 0;
}