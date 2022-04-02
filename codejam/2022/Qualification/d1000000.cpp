/*
 * @Author: tusikalanse
 * @Date: 2022-04-02 14:34:58
 * @LastEditTime: 2022-04-02 14:39:32
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

const int N = 1e5 + 10;

int a[N], T, n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    for (int cas = 1; cas <= T; ++cas) {
        cout << "Case #" << cas << ": ";
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i] > ans) {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}