/*
 * @Description:
 * @Version: 2.0
 * @Autor: tusikalanse
 * @Date: 2021-11-21 23:39:43
 * @LastEditors: tusikalanse
 * @LastEditTime: 2021-11-21 23:41:40
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

int a[N], n, k, T;
int b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        a[n + 1] = 100000;
        int mx = 1;
        for (int i = 1, j; i <= n; i = j) {
            j = i;
            while (a[i] == a[j])
                j++;
            mx = max(j - i, mx);
        }
        // cout << mx << endl;
        if (mx > k) {
            cout << -1 << endl;
        } else {
            int d = 1;
            for (int j = n - 1;; --j) {
                if (a[j] == a[n])
                    d++;
                else
                    break;
            }
            for (int i = 1; i <= k - d; ++i) {
                b[i] = a[i];
            }
            for (int i = k - d + 1; i <= k; ++i) {
                b[i] = a[n];
            }
            for (int i = k + 1, j = n - d; i <= n; ++i, --j) {
                b[i] = a[j];
            }
            for (int i = 1; i <= n; ++i) {
                cout << b[i] << " \n"[i == n];
            }
        }
    }
    return 0;
}