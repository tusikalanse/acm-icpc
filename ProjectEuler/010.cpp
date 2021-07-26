/*
 * @Author: tusikalanse
 * @Date: 2021-06-25 21:44:26
 * @LastEditTime: 2021-06-25 21:46:17
 * @LastEditors: tusikalanse
 * @Description: 
 * @FilePath: /ProjectEuler/10.cpp
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

const int N = 2e6 + 10;

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
    long long ans = 0;
    for (int i = 1; prime[i] < 2000000; ++i)
        ans += prime[i];
    cout << ans << endl;
    return 0;
}
