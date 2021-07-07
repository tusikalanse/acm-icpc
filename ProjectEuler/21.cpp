/*
 * @Author: tusikalanse
 * @Date: 2021-07-07 21:17:02
 * @LastEditTime: 2021-07-07 21:31:59
 * @LastEditors: tusikalanse
 * @Description: Euler sieve sum of divsor
 * @FilePath: /ProjectEuler/21.cpp
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

const int N = 1e4 + 10;

int prime[N];
bool notprime[N];
int sum_divisor[N];
int small_p[N];

void getprime() {
    memset(prime, 0, sizeof(prime));
    memset(notprime, 0, sizeof(notprime));
    for (int i = 2; i < N; ++i) {
        if (!notprime[i]) {
            prime[++prime[0]] = i;
            small_p[i] = 1 + i;
            sum_divisor[i] = 1 + i;
        } 
        for (int j = 1; j <= prime[0] && i * prime[j] < N; ++j) {
            notprime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                small_p[i * prime[j]] = 1 + small_p[i] * prime[j];
                sum_divisor[i * prime[j]] = sum_divisor[i] / small_p[i] * small_p[i * prime[j]];
                break;
            }
            else {
                sum_divisor[i * prime[j]] = sum_divisor[i] * sum_divisor[prime[j]];\
                small_p[i * prime[j]] = 1 + prime[j];
            }
        }
    }
    for (int i = 2; i < N; ++i) {
        sum_divisor[i] -= i;
    }
}


int main() {
    getprime();
    int ans = 0;
    for (int i = 2; i <= 10000; ++i) {
        if (sum_divisor[i] <= 10000 && i != sum_divisor[i] && i == sum_divisor[sum_divisor[i]]) {
            ans += i;
        }
    }
    cout << ans << endl;
    return 0;
}
