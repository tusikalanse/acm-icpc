/*
 * @Author: tusikalanse
 * @Date: 2021-06-25 21:22:57
 * @LastEditTime: 2021-06-25 21:34:38
 * @LastEditors: tusikalanse
 * @Description: Euler - sieve
 * @FilePath: /ProjectEuler/7.cpp
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

const int N = 2e5 + 10;

int prime[N];
bool notprime[N];

void getprime() {
    memset(prime, 0, sizeof(prime));
    memset(notprime, 0, sizeof(notprime));
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

int main() {
    getprime();
    cout << prime[0] << endl;
    cout << prime[1] << endl;
    cout << prime[10001] << endl;
    return 0;
}
