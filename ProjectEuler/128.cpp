/*
 * @Author: tusikalanse
 * @Date: 2021-09-09 09:19:18
 * @LastEditTime: 2021-09-14 09:42:04
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

const int N = 1e7 + 10;

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
    for (int i = 1; i <= prime[0] && 1LL * prime[i] * prime[i] <= x; ++i) {
        if (x % prime[i] == 0)
            return false;
    }
    return true;
}

int limit = 2000;
int cnt = 1; // 1
LL num = 0;

int main() {
    getprime();
    int n = 1;
    while (cnt < limit) {
        if (isprime(6 * n - 1) && isprime(6 * n + 1) && isprime(12 * n + 5)) {
            num = 3LL * n * n - 3 * n + 2;
            if (++cnt >= limit) break;
        }
        if (n != 1 && isprime(6 * n - 1) && isprime(6 * n + 5) && isprime(12 * n - 7)) {
            num = 3LL * n * n + 3 * n + 1;
            cnt++;
        }
        n++;
    }
    cout << cnt << " " << n << " " << num << endl;
    return 0;
}