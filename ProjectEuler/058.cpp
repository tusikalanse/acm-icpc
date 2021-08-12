/*
 * @Author: tusikalanse
 * @Date: 2021-07-12 12:42:39
 * @LastEditTime: 2021-07-12 12:52:51
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

const int N = 1e8 + 10;

LL ans = 0;
int p = 2, x = 1;

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

bool isprime(LL x) {
    if (x < N)
        return !notprime[x];
    for (int i = 1; i <= prime[0]; ++i) {
        if (x % prime[i] == 0)
            return false;
    }
    return true;
}

int main() {
    getprime();
    int total = 1, cnt = 0;
    for (int i = 3;; i += 2) {
        for (int _ = 0; _ < 4; ++_) {
            x += p;
            total++;
            cnt += isprime(x);
            if (cnt * 10 < total) {
                cout << i << endl;
                return 0;
            }
        }
        p += 2;
    }
    return 0;
}
