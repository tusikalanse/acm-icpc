/*
 * @Author: tusikalanse
 * @Date: 2021-06-29 00:16:48
 * @LastEditTime: 2021-06-29 00:34:18
 * @LastEditors: tusikalanse
 * @Description: 
 * @FilePath: /atcoder/agc/054/c.cpp
 */
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
//-------------------end head--------------

const int N = 5010;

int a[N], p[N], inv[N];
int n, k;

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        p[a[i]] = i;
        for (int j = 1; j < i; ++j) 
            inv[i] += a[j] > a[i];
    }
    int ans = 1;
    int maxp = 0;
    for (int i = 1; i <= n; ++i) {
        if (p[i] > maxp && inv[p[i]] == k) {
            ans = 1LL * ans * (n - p[i] + 1) % mod;
            maxp = p[i];
        }
    }
    cout << ans << endl;
    return 0;
}
