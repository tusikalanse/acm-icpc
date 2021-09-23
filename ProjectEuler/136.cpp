/*
 * @Author: tusikalanse
 * @Date: 2021-09-23 09:23:25
 * @LastEditTime: 2021-09-23 09:39:03
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
const int N = 5e7 + 10;

int cnt[N];

int limit = 5e7;

int main() {
    // getprime();
    for (int a = 1; a < limit; ++a) {
        for (int b = a / 4; b < a && a * (4 * b - a) < limit; ++b) {
            if (4 * b - a < 1) continue;
            cnt[a * (4 * b - a)]++;
        }
    }
    int ans = 0;
    for (int i = 0; i < limit; ++i) {
        ans += cnt[i] == 1;
    }
    cout << ans << endl;
    return 0;
}