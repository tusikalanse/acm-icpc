/*
 * @Author: tusikalanse
 * @Date: 2021-06-28 23:45:29
 * @LastEditTime: 2021-06-29 00:02:03
 * @LastEditors: tusikalanse
 * @Description: 
 * @FilePath: /atcoder/agc/054/b.cpp
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

const int N = 110;

int n, sum;
int a[N];
LL ans;

int dp[5010][N];
int fact[N];

int main() {
    fact[0] = 1;
    for (int i = 1; i <= 100; ++i)  
        fact[i] = 1LL * i * fact[i - 1] % mod;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % 2) {
        cout << "0" << endl;
        return 0;
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int cnt = i - 1; ~cnt; --cnt) {
            for (int j = 0; j + a[i] <= 5000; ++j) {
                (dp[j + a[i]][cnt + 1] += dp[j][cnt]) %= mod;         
            }
        }
    }
    for (int cnt = 1; cnt < n; ++cnt) {
        ans += 1LL * dp[sum / 2][cnt] * fact[cnt] % mod * fact[n - cnt] % mod;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
