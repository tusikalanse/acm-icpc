/*
 * @Author: tusikalanse
 * @Date: 2021-07-09 08:54:35
 * @LastEditTime: 2021-07-09 09:00:19
 * @LastEditors: tusikalanse
 * @Description: 
 * @FilePath: /ProjectEuler/35.cpp
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

int ten[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};

int num(int x) {
    int cnt = 0;
    while (x) {
        cnt++;
        x /= 10;
    }
    return cnt;
}

bool gao(int x) {
    if (notprime[x]) return false;
    int d = x;
    int t = num(x);
    do {
        int p = d % 10;
        d /= 10;
        d += ten[t - 1] * p;
        if (notprime[d]) return false;
    } while (d != x);
    return true;
}

int main() {
    getprime();
    int cnt = 0;
    for (int i = 1; i <= 1000000; ++i) {
        if (gao(i)) {
            cnt++;
            cout << i << endl;
        }
    }
    cout << cnt << endl;
    return 0;
}
