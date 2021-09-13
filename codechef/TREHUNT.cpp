/*
 * @Author: tusikalanse
 * @Date: 2021-09-09 19:08:18
 * @LastEditTime: 2021-09-09 19:48:28
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
const int mod = 998244353;
//-------------------end head--------------

const int N = 2e7 + 10;

int a[N], pow31[N];
int ans, T, n, m;

int d[N], dd[N];

int main() {
    pow31[0] = 1;
    for (int i = 1; i < N; ++i) {
        pow31[i] = 31LL * pow31[i - 1] % mod;
    }
    cin >> T;
    while (T--) {
        cin >> n >> m;
        ans = 0;
        memset(a, 0, sizeof(int) * (n + m));
        memset(d, 0, sizeof(int) * (n + m));
        memset(dd, 0, sizeof(int) * (n + m));

        if (n > m) 
            swap(n, m);

        d[0] = 1LL * n * m % mod;
        d[m] = -1LL * n * m % mod;

        dd[1] = (mod - n) % mod;
        dd[m] = n;
        d[m] = (d[m] + 1LL * n * (m - 1)) % mod;

        for (int i = 1; i < n; ++i) {
            d[i] = (d[i] + 1LL * (n - i) * m) % mod;
            d[i + 1] = (d[i + 1] + 1LL * (n - i) * m) % mod;
            d[i + m] = (d[i + m] - 2LL * (n - i) * m) % mod;

            dd[i + 1] = (dd[i + 1] - 2 * (n - i)) % mod;
            dd[i + m] = (dd[i + m] + 2 * (n - i)) % mod;
            d[i + m] = (d[i + m] + 2LL * (n - i) * (m - 1)) % mod;
        }
        a[0] = d[0];
        int nowd = 0;
        // cout << d[0] << " " << dd[0] << endl;
        for (int i = 1; i <= n + m - 2; ++i) {
            nowd = (nowd + dd[i]) % mod;
            a[i] = (0LL + a[i - 1] + d[i] + nowd) % mod;
            // cout << d[i] << " " << dd[i] << endl;
        }
        // cout << d[n + m - 1] << " " << dd[n + m - 1] << endl;
        for (int i = 1; i <= n + m - 2; ++i) {
            // cout << a[i] << " ";
            ans = (ans + 1LL * a[i] * pow31[i - 1]) % mod;
        }
        cout << (ans + mod) % mod << endl;
    }

    return 0;
}