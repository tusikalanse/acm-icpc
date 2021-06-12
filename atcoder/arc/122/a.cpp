/*
 * @Author: tusikalanse
 * @Date: 2021-06-12 19:37:10
 * @LastEditTime: 2021-06-12 20:29:06
 * @LastEditors: tusikalanse
 * @Description: 
 * @FilePath: /undefined/mnt/e/algo/atcoder/arc/122/a.cpp
 */
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}

const int N = 1e5 + 10, mod = 1e9 + 7;

int n, a[N];
int f[N], p[2][N];
LL ans[2];


int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) 
        cin >> a[i];
    f[0] = f[1] = 1;
    p[0][1] = 1;
    for (int i = 2; i <= 100000; ++i) {
        f[i] = (f[i - 1] + f[i - 2]) % mod;
        p[0][i] = (p[0][i - 1] + p[1][i - 1]) % mod;
        p[1][i] = p[0][i - 1];
    }
    ans[0] = a[1];
    ans[1] = 0;
    for (int i = 2; i <= n; ++i) {
        int temp0 = (ans[0] + 1LL * a[i] * p[0][i - 1] % mod + ans[1] + 1LL * a[i] * p[1][i - 1] % mod) % mod;
        int temp1 = (ans[0] - 1LL * a[i] * p[0][i - 1]) % mod;
        ans[0] = temp0;
        ans[1] = temp1;
        //cout << p[0][i - 1] << " " << p[1][i - 1] << " " << ans[0] << " " << ans[1] << endl;
    }
    cout << ((ans[0] + ans[1]) % mod + mod) % mod << endl;
    return 0;
}
