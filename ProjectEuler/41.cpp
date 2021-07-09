/*
 * @Author: tusikalanse
 * @Date: 2021-07-09 08:54:35
 * @LastEditTime: 2021-07-09 20:57:06
 * @LastEditors: tusikalanse
 * @Description: 
 * @FilePath: /ProjectEuler/41.cpp
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

int main() {
    getprime();
    int ans = 0;
    for (int i = 1; i <= 7; ++i) {
        vector<int> x;
        for (int j = 1; j <= i; ++j) {
            x.push_back(j);
        }
        do {
            int v = 0;
            for (int j = 0; j < i; ++j) {
                v = v * 10 + x[j];
            }
            if (!notprime[v]) {
                ans = max(ans, v);
                cout << v << endl;
            }
        } while (next_permutation(x.begin(), x.end()));
    }
    cout << ans << endl;
    return 0;
}
