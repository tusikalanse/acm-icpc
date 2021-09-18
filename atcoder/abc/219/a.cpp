/*
 * @Description: 
 * @Version: 2.0
 * @Autor: tusikalanse
 * @Date: 2021-08-21 19:52:17
 * @LastEditors: tusikalanse
 * @LastEditTime: 2021-09-18 20:00:45
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
    int x;
    cin >> x; 
    if (x >= 90) {
        puts("expert");
    }
    else if (x >= 70) {
        cout << 90 - x << endl;
    }
    else if (x >= 40) {
        cout << 70 - x << endl;
    }
    else {
        cout << 40 - x << endl;
    }
    
    return 0;
}