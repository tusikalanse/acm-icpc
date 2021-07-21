/*
 * @Author: tusikalanse
 * @Date: 2021-07-20 12:32:37
 * @LastEditTime: 2021-07-20 12:34:27
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
LL ans[N];

void getprime() {
    memset(prime, 0, sizeof(prime));
    memset(notprime, 0, sizeof(notprime));
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
    for (int i = 3; i < N; ++i) {
        ans[i] = ans[i - 1] + i;
        if (!notprime[i])
            ans[i] += i;
    }
}


int main() {
    getprime();
    int T, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        printf("%lld\n", ans[n]);
    }
    return 0;
}
