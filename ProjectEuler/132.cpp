/*
 * @Author: tusikalanse
 * @Date: 2021-09-07 09:23:30
 * @LastEditTime: 2021-09-07 10:02:10
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

bool notprime[N];
int prime[N];

void getprime() {
    memset(notprime, 0, sizeof(notprime));
    notprime[1] = 1;
    for (int i = 2; i < N; ++i) {
        if (!notprime[i]) {
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] < N; ++j) {
            notprime[i * prime[j]] = 1;
            if (i % prime[j] == 0) 
                break;
        }
    }
}

int digit = 1e9;
int cnt = 40;
LL ans = 0;

LL qp(LL a, LL n, LL mod) {
    LL res = 1;
    while (n) {
        if (n & 1) 
            res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    getprime();
    for (int i = 1; i <= prime[0] && cnt; ++i) {
        if (qp(10, digit, 9 * prime[i]) == 1) {
            cout << prime[i] << " ";
            ans += prime[i];
            cnt--;
        }
    }
    cout << endl;
    cout << cnt << " " << ans << endl;
    return 0;
}