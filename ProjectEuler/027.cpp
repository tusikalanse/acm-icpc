/*
 * @Author: tusikalanse
 * @Date: 2021-07-07 22:01:38
 * @LastEditTime: 2021-07-07 22:15:53
 * @LastEditors: tusikalanse
 * @Description: 
 * @FilePath: /ProjectEuler/27.cpp
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

bool isprime(LL x) {
    if (x < 2)
        return false;
    if (x < N)
        return !notprime[x];
    else {
        cout << x << endl;
        for (int i = 1; i <= prime[0]; ++i) 
            if (x % prime[i] == 0)
                return false;
        return true;
    }
}

int main() {
    getprime();
    int mx = 0, ans = 0;
    for (int a = -999; a < 1000; ++a) {
        for (int b = -1000; b <= 1000; ++b) {
            LL cnt = 0;
            while (isprime(cnt * cnt + a * cnt + b))
                cnt++;
            if (cnt > mx) {
                mx = cnt;
                ans = a * b;
                cout << mx << " " << ans << endl;
            }
        }
    }
    cout << mx << " " << ans << endl;
    return 0;
}
