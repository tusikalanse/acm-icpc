/*
 * @Author: tusikalanse
 * @Date: 2021-09-17 09:22:39
 * @LastEditTime: 2021-09-17 10:03:30
 * @LastEditors: tusikalanse
 * @Description: exgcd get inverse
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

const int N = 1e6 + 300;

bool notprime[N];
int prime[N];
int rad[N];

void getprime() {
    memset(notprime, 0, sizeof(notprime));
    notprime[1] = 1;
    rad[1] = 1;
    for (int i = 2; i < N; ++i) {
        if (!notprime[i]) {
            rad[i] = i;
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] < N; ++j) {
            notprime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                rad[i * prime[j]] = rad[i];
                break;
            }
            else {
                rad[i * prime[j]] = rad[i] * prime[j];
            }
        }
    }
}

void exgcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1, y = 0;
        return;
        }
    exgcd(b, a % b, y, x);
    y -= a / b * x;
}

int getlen(int x) {
    int ret = 0;
    while (x) {
        x /= 10;
        ret++;
    }
    return ret == 0 ? 1 : ret;
}

LL POW10[15];

int limit = 1e6;
LL ans = 0;

int main() {
    POW10[0] = 1;
    for (int i = 1; i <= 12; ++i) {
        POW10[i] = POW10[i - 1] * 10;
    }
    getprime();
    for (int i = 3; i <= prime[0] && prime[i] <= limit; ++i) {
        int p1 = prime[i], p2 = prime[i + 1];
        int x, y;
        exgcd(p2, POW10[getlen(p1)], x, y);
        // x *= POW10[getlen(p1)] - p1;
        // y *= POW10[getlen(p1)] - p1;
        // cout << p1 << " " << p2 << " " << x << " " << y << " " << ((x * p2) * p1) % (p2 * POW10[getlen(p1)]) + (p2 * POW10[getlen(p1)]) << endl;
        ans += (((1LL * x * p2) * p1) % (p2 * POW10[getlen(p1)]) + (p2 * POW10[getlen(p1)])) % (p2 * POW10[getlen(p1)]);
    }
    cout << ans << endl;
    return 0;
}