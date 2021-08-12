/*
 * @Author: tusikalanse
 * @Date: 2021-07-30 11:34:43
 * @LastEditTime: 2021-07-30 14:52:33
 * @LastEditors: tusikalanse
 * @Description: sieve f[x] = number of factor of x^2, find first f[x] > 2 * 1000 - 1
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

const int N = 1e6;

int prime[N];
bool notprime[N];
int cnt[N];
int small_p[N];

void getprime() {
    memset(prime, 0, sizeof(prime));
    memset(notprime, 0, sizeof(notprime));
    for (int i = 2; i < N; ++i) {
        if (!notprime[i]) {
            prime[++prime[0]] = i;
            small_p[i] = 3;
            cnt[i] = 3;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] < N; ++j) {
            notprime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                small_p[i * prime[j]] = 2 + small_p[i];
                cnt[i * prime[j]] = cnt[i] / small_p[i] * small_p[i * prime[j]];
                break;
            } else {
                cnt[i * prime[j]] = cnt[i] * cnt[prime[j]];
                small_p[i * prime[j]] = 3;
            }
        }
    }
}

int get(int x) {
    for (int i = 2; i < N; ++i) {
        if (cnt[i] > 2 * x - 1)
            return i;
    }
    return -1;
}

int main() {
    getprime();
    cout << get(100) << endl;
    cout << get(1000) << endl;
    return 0;
}
