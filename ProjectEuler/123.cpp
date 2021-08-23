/*
 * @Author: tusikalanse
 * @Date: 2021-08-20 20:53:49
 * @LastEditTime: 2021-08-20 21:01:28
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
const int mod = 1e9 + 7;
//-------------------end head--------------
const int N = 1e6 + 10;

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

LL n = 1e10;

int main() {
    getprime();
    for (int i = 3; i <= prime[0]; i += 2) {
        LL x = 2LL * i % prime[i] * prime[i];
        if (x > n) {
            cout << i << " " << prime[i] << " " << x << endl;
            break;
        }
    }
    return 0;
}