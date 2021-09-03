/*
 * @Author: tusikalanse
 * @Date: 2021-09-03 20:45:07
 * @LastEditTime: 2021-09-03 20:47:27
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

int gao(int x) {
    return 3 * x * (x + 1) + 1;
}

int n = 1e6;
int main() {
    getprime();
    int ans = 0;
    for (int i = 1, d; (d = gao(i)) <= n; ++i) {
        if (!notprime[d])
            ans++;
    }
    cout << ans << endl;
    return 0;
}