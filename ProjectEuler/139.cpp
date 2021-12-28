/*
 * @Author: tusikalanse
 * @Date: 2021-12-28 15:22:23
 * @LastEditTime: 2021-12-28 15:32:23
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

const int N = 1e8;

// a = m * m - n * n 
// b = 2 * m * n
// c = m * m + n * n

int main() {
    int ans = 0;
    for (int m = 1; m * m * 2 < N; ++m) {
        for (int n = (m & 1) + 1; n < m && 2 * m * (m + n) <= N; n += 2) {
            if (gcd(n, m) != 1)
                continue;
            // cout << m * m - n * n << " " << 2 * m * n << " " << m * m + n * n << endl;
            int s = 2 * m * (m + n);
            if ((m * m + n * n) % abs(m * m - n * n - 2 * m * n) == 0) {
                for (int i = 1; i * s <= N; ++i) {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}