/*
 * @Description:
 * @Version: 2.0
 * @Autor: tusikalanse
 * @Date: 2021-11-21 23:39:43
 * @LastEditors: tusikalanse
 * @LastEditTime: 2021-11-21 23:58:23
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

const int N = 3010;

int a[N], n, T;
int b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        LL ans = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i + 2 <= n; ++i) {
            for (int j = i + 2; j <= n; ++j) {
                int mn = a[i];
                int mx = a[j];
                LL temp = 0;
                int tar = (mx + mn) / 2;
                auto p = lower_bound(a + i + 1, a + j, tar);
                if (p != a + j) {
                    temp = max(temp, 1LL * (mx - *p) * (*p - mn));
                }
                if (p != a + i + 1) {
                    --p;
                    temp = max(temp, 1LL * (mx - *p) * (*p - mn));
                }
                ans += temp;
            }
        }
        cout << ans << endl;
    }
    return 0;
}