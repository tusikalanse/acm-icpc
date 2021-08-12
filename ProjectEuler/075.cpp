/*
 * @Author: tusikalanse
 * @Date: 2021-07-15 19:48:55
 * @LastEditTime: 2021-07-15 19:57:50
 * @LastEditors: tusikalanse
 * @Description: pythagorean triple
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

const int N = 15e5;

map<int, int> cnt;

int main() {
    for (int m = 1; m * m * 2 < N; ++m) {
        for (int n = (m & 1) + 1; n < m && 2 * m * (m + n) <= N; n += 2) {
            if (gcd(n, m) != 1)
                continue;
            // cout << m * m - n * n << " " << 2 * m * n << " " << m * m + n * n << endl;
            int s = 2 * m * (m + n);
            for (int i = 1; i * s <= N; ++i)
                cnt[i * s]++;
        }
    }
    int ans = 0;
    for (auto [x, y] : cnt)
        ans += y == 1;
    cout << ans << endl;

    return 0;
}