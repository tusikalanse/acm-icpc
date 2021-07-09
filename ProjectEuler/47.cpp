/*
 * @Author: tusikalanse
 * @Date: 2021-07-09 21:03:22
 * @LastEditTime: 2021-07-09 21:33:24
 * @LastEditors: tusikalanse
 * @Description: 
 * @FilePath: /ProjectEuler/47.cpp
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

bool gao(int n) {
    int cnt = 0, x = 2;
    while (x * x <= n) {
        if (n % x == 0) {
            while (n % x == 0) n /= x;
            cnt++;
        }
        x++;
    }
    cnt += n != 1;
    return cnt == 4;
}

int main() {
    getprime();
    for (int x = 1; x + 3 < N; ++x) {
        if (!notprime[x]) continue;
        if (!notprime[x + 1]) continue;
        if (!notprime[x + 2]) continue;
        if (!notprime[x + 3]) continue;
        if (x % 100000 == 0)
            cout << x << endl;
        if (!gao(x) || !gao(x + 1) || !gao(x + 2) || !gao(x + 3)) continue;
        cout << x << endl;
        break;
    }
    return 0;
}
