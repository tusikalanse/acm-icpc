/*
 * @Author: tusikalanse
 * @Date: 2021-07-18 23:26:53
 * @LastEditTime: 2021-07-18 23:28:46
 * @LastEditors: tusikalanse
 * @Description: Integer partition
 * @FilePath: /ProjectEuler/78.cpp
 */
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e6;
//-------------------end head--------------

const int N = 1e5 + 10;
int f[N], w[N];

void init() {
    int cnt = 0;
    for (int i = 1;; i++) {
        if (1ll * i * (3 * i - 1) / 2 < N)
            w[++cnt] = i * (3 * i - 1) / 2;
        else
            break;
        if (1ll * i * (3 * i + 1) / 2 < N)
            w[++cnt] = i * (3 * i + 1) / 2;
        else
            break;
    }
    f[0] = 1;
    for (int i = 1; i < N; i++) {
        f[i] = 0;
        for (int j = 1; j <= cnt && w[j] <= i; j++) {
            int k = (j + 1) / 2;
            if (k & 1)
                f[i] = (f[i] + f[i - w[j]]) % mod;
            else
                f[i] = (f[i] - f[i - w[j]] + mod) % mod;
        }
    }
}

int main() {
    init();
    for (int i = 1;; ++i)
        if (f[i] == 0) {
            cout << i << endl;
            break;
        }
    return 0;
}
