/*
 * @Description:
 * @Version: 2.0
 * @Autor: tusikalanse
 * @Date: 2021-10-23 14:11:45
 * @LastEditors: tusikalanse
 * @LastEditTime: 2021-10-23 23:30:35
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

LL T, k, n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n >> k;
        if (k == 0) {
            cout << "YES" << endl << 0 << endl;
        } else if (k % 2 == 0) {
            cout << "NO" << endl;
        } else if (k == 1) {
            cout << "YES" << endl << 1 << endl << 1 << endl;
        } else {
            int lim = 1, cnt = 0;
            while (lim < k)
                lim *= 2, cnt++;
            lim -= 1;
            int delta = (lim - k) / 2;
            int pos = 1, neg = k - (1 << (cnt - 1)) + 1;
            cout << "YES" << endl << cnt << endl;
            for (int i = 0; i < cnt - 1; ++i) {
                if (delta >> i & 1) {
                    cout << neg << endl;
                    neg += 1 << i;
                } else {
                    cout << pos << endl;
                    pos += 1 << i;
                }
            }
            cout << k - (1 << (cnt - 1)) + 1 << endl;
        }
    }
    return 0;
}