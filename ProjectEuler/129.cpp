/*
 * @Author: tusikalanse
 * @Date: 2021-09-01 09:25:49
 * @LastEditTime: 2021-09-01 09:30:36
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

int get(int n) {
    if (gcd(n, 10) != 1) return 0;
    int x = 1, digit = 1;
    while (x) {
        x = x * 10 + 1;
        x %= n;
        digit++;
    }
    return digit;
}

int main() {
    for (int i = 1000001; ; i += 2) {
        if (get(i) > 1000000) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}