/*
 * @Author: tusikalanse
 * @Date: 2021-06-13 20:15:57
 * @LastEditTime: 2021-06-13 21:31:49
 * @LastEditors: tusikalanse
 * @Description: 
 * @FilePath: /undefined/mnt/e/algo/atcoder/abc/205/e.cpp
 */
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}

const int mod = 1e9 + 7, N = 2e6 + 10;

LL qp(LL a, LL n) {
    LL res = 1;
    while (n) {
        if (n & 1)
            res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int n, m, k;
int fac[N], invfac[N];

LL C(LL n, LL m) {
    if (n < m || m < 0 || n < 0) return 0;
    return 1LL * fac[n] * invfac[m] % mod * invfac[n - m] % mod;
}



int main() {
    fac[0] = invfac[0] = 1;
    for (int i = 1; i <= 2000000; ++i) {
        fac[i] = 1LL * fac[i - 1] * i % mod;
    }
    invfac[2000000] = qp(fac[2000000], mod - 2);
    for (int i = 1999999; i; --i)
        invfac[i] = 1LL * invfac[i + 1] * (i + 1) % mod;
    cin >> n >> m >> k;
    if (n > m + k) {
        cout << 0 << endl;
        return 0;
    }
    cout << (0LL + C(n + m, m) - C(n + m, m + k + 1) + mod) % mod << endl;
    return 0;
}
