/*
 * @Description: 
 * @Version: 2.0
 * @Autor: tusikalanse
 * @Date: 2021-08-21 19:52:18
 * @LastEditors: tusikalanse
 * @LastEditTime: 2021-08-21 20:03:20
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

LL n, temp;
int ans;

int main() {
    cin >> n;
    ans = 0;
    temp = 1;
    while (temp <= n) {
        temp *= 2;
        ans++;
    }
    cout << ans - 1 << endl;
    return 0;
}