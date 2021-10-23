/*
 * @Description: 
 * @Version: 2.0
 * @Autor: tusikalanse
 * @Date: 2021-10-23 14:04:30
 * @LastEditors: tusikalanse
 * @LastEditTime: 2021-10-23 14:07:25
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

int T, n;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        if (n == 2) {
            cout << 0 << endl;
            continue;
        }
        else if (n == 3) {
            cout << min(a[2] - a[1], a[3] - a[2]) << endl;
            continue;
        }
        LL mn = 1e18;
        for (int i = 2; i < n; ++i) {
            int tar = a[n] + a[1] - a[i];
            int pos = lower_bound(a + 2, a + n, tar) - a;
            if (pos != n && (pos < i || pos == i + 1)) 
                mn = min(mn, 0LL + a[pos] - tar);
            if ((pos - 1 < i && pos != 2) || pos == i + 2) 
                mn = min(mn, 0LL + tar - a[pos - 1]);
        }
        LL sum = 0LL;
        int tar = a[n / 2];
        for (int i = 1; i < n; ++i) {
            sum += abs(tar - a[i]);
        }
        mn = min(mn, sum);
        sum = 0;
        tar = a[n / 2 + 1];
        for (int i = 2; i <= n; ++i) {
            sum += abs(tar - a[i]);
        }
        mn = min(mn, sum);
        cout << mn << endl;
    }
    return 0;
}