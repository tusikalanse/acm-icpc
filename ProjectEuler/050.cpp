/*
 * @Author: tusikalanse
 * @Date: 2021-07-09 08:54:35
<<<<<<< HEAD
 * @LastEditTime: 2021-07-09 21:56:28
=======
 * @LastEditTime: 2021-07-09 21:47:45
>>>>>>> b8ddcfc9cd50cbf5959e7950e7401b52601bf81f
 * @LastEditors: tusikalanse
 * @Description:
 * @FilePath: /ProjectEuler/50.cpp
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

int s[N];

int main() {
    int ans = 0, cnt = 0;
    getprime();
    for (int i = 1; i <= prime[0]; ++i)
        vis[prime[i]] = 1;
    for (int i = 1; i <= prime[0]; ++i) {
        int sum = prime[i];
        int j = i;
        while (sum < 1000000) {
            if (!notprime[sum]) {
                if (j - i + 1 > cnt) {
                    ans = sum;
                    cnt = j - i + 1;
                }
            }
            sum += prime[++j];
        }
    }
    cout << ans << endl;
    return 0;
}
