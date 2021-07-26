/*
 * @Author: tusikalanse
 * @Date: 2021-07-20 17:39:37
 * @LastEditTime: 2021-07-20 18:54:28
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

const int N = 1e5;

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

const int x = 5e7;

unordered_set<int> cnt;

int main() {
    getprime();
    for (int i = 1; prime[i] * prime[i] < x; ++i) {
        for (int j = 1; prime[i] * prime[i] + prime[j] * prime[j] * prime[j] < x; ++j) {
            for (int k = 1; prime[i] * prime[i] + prime[j] * prime[j] * prime[j] + prime[k] * prime[k] * prime[k] * prime[k] <= x; ++k) {
                cnt.insert(prime[i] * prime[i] + prime[j] * prime[j] * prime[j] + prime[k] * prime[k] * prime[k] * prime[k]);
            }
        }
    }
    cout << cnt.size() << endl;
    return 0;
}