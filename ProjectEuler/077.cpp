/*
 * @Author: tusikalanse
 * @Date: 2021-07-18 23:35:19
 * @LastEditTime: 2021-07-18 23:43:49
 * @LastEditors: tusikalanse
 * @Description: Integer partition of primes
 * @FilePath: /ProjectEuler/77.cpp
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

const int N = 1e4 + 10;

int prime[N];
bool notprime[N];

void getprime() {
    memset(prime, 0, sizeof(prime));
    memset(notprime, 0, sizeof(notprime));
    notprime[1] = 1;
    for (int i = 2; i < N; ++i) {
        if (!notprime[i])
            prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && i * prime[j] < N; ++j) {
            notprime[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}

int f[N][N];

int main() {
    getprime();
    for (int i = 2; i < N; ++i) {
        if (!notprime[i])
            f[i][i] = 1;
        for (int j = 1; j <= i; ++j) {
            if (f[i][j] == 0)
                continue;
            for (int k = j; k + i < N; ++k) {
                if (notprime[k])
                    continue;
                f[i + k][k] += f[i][j];
            }
        }
        int ans = 0;
        for (int j = 1; j <= i; ++j)
            ans += f[i][j];
        if (ans >= 5000) {
            cout << i << " " << ans << endl;
            return 0;
        }
    }
    return 0;
}
