/*
 * @Author: tusikalanse
 * @Date: 2021-07-09 20:37:12
 * @LastEditTime: 2021-07-09 20:41:50
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
    vector<int> d;
    for (int i = 0; i <= 9; ++i) {
        d.push_back(i);
    }
    LL ans = 0;
    do {
        if (d[0] == 0) continue;
        if (d[3] % 2 != 0) continue;
        if ((d[2] + d[3] + d[4]) % 3 != 0) continue;
        if (d[5] % 5 != 0) continue;
        if ((100 * d[4] + 10 * d[5] + d[6]) % 7 != 0) continue;
        if ((100 * d[5] + 10 * d[6] + d[7]) % 11 != 0) continue;
        if ((100 * d[6] + 10 * d[7] + d[8]) % 13 != 0) continue;
        if ((100 * d[7] + 10 * d[8] + d[9]) % 17 != 0) continue;
        LL x = 0;
        for (int i: d)
            x = x * 10 + i;
        cout << x << endl;
        ans += x;
    } while (next_permutation(d.begin(), d.end()));
    cout << ans << endl;
    return 0;
}