/*
 * @Author: tusikalanse
 * @Date: 2021-07-23 11:33:04
 * @LastEditTime: 2021-07-23 11:54:40
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

const int N = 1e6;

int prime[N];
bool notprime[N];
int sum_divisor[N];
int small_p[N];
int vis[N];

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
                sum_divisor[i * prime[j]] = sum_divisor[i] * sum_divisor[prime[j]];
                small_p[i * prime[j]] = 1 + prime[j];
            }
        }
    }
    for (int i = 2; i < N; ++i) {
        sum_divisor[i] -= i;
    }
}

bool is_abundant_number(int x) {
    return sum_divisor[x] > x;
}

int main() {
    getprime();
    int ans = 0, len = 0;
    for (int i = 2, x = i; i < N; ++i, x = i) {
        if (vis[x]) continue;
        vector<int> tmp;
        unordered_map<int, int> v;
        int length = 1;
        while (x < N && !v[x] && !vis[x]) {
            tmp.push_back(x);
            v[x] = length;
            ++length;
            x = sum_divisor[x];
        }
        if (x < N) 
            for (int d: tmp)
                vis[x] = 1;
        if (x < N && x >= 2 && v[x] && length - v[x] > len) {
            len = length - v[x];
            int mn = 1e9;
            for (int d: tmp) {
                if (vis[d] >= vis[x])
                    mn = min(mn, d);
            }
            ans = mn;
        }
    }
    cout << ans << endl;
    return 0;
}
