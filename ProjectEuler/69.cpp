/*
 * @Author: tusikalanse
 * @Date: 2021-07-14 22:52:31
 * @LastEditTime: 2021-07-14 22:59:53
 * @LastEditors: tusikalanse
 * @Description: euler sieve to get phi
 * @FilePath: /ProjectEuler/69.cpp
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

const int N = 1e6 + 10;

int prime[N];
bool notprime[N];
int phi[N];

void getprime() {
    memset(prime, 0, sizeof(prime));
    memset(notprime, 0, sizeof(notprime));
    notprime[1] = 1;
    phi[1] = 1;
    for (int i = 2; i < N; ++i) {
        if (!notprime[i]) {
            prime[++prime[0]] = i;
            phi[i] = i - 1;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] < N; ++j) {
            notprime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            else {
                phi[i * prime[j]] = phi[i] * phi[prime[j]];
            }
        }
    }
}

int main() {
    getprime();
    int n = 2, phin = 1;
    for (int i = 2; i <= 1000000; ++i) {
        if (1LL * n * phi[i] < 1LL * i * phin) {
            n = i;
            phin = phi[i];
        }
    }
    cout << n << endl;
    return 0;
}
