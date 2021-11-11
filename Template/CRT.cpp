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

void exgcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1, y = 0;
        return;
    }
    exgcd(b, a % b, y, x);
    y -= (a / b) * x;
}

LL CRT(int k, LL a[], LL r[]) {
    LL n = 1, ans = 0;
    for (int i = 1; i <= k; ++i) n *= r[i];
    for (int i = 1; i <= k; ++i) {
        LL m = n / r[i], b, y;
        exgcd(m, r[i], b, y); // b * m % r[i] = 1
        ans = (ans + a[i] * m * b) % mod;
    }
    return (ans + mod) % mod;
}

int main() {
    
    return 0;
}