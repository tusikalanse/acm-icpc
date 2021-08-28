/*
 * @Description: 
 * @Version: 2.0
 * @Autor: tusikalanse
 * @Date: 2021-08-22 19:51:09
 * @LastEditors: tusikalanse
 * @LastEditTime: 2021-08-22 21:38:08
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

const int N = 2e5 + 10;

int n, a[N], pre[N];
LL dp[N];

LL c[N];

int lowbit(int x) {
    return x & -x;
}

void update(int x, int v) {
    for (; x < N; x += lowbit(x))
        c[x] += v;
}

LL sum(int x) {
    LL res = 0;
    for (; x; x -= lowbit(x)) {
        res = (res + c[x]) % mod;
    }
    return res;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        if (pre[a[i]] == 0) {
            dp[i] = (sum(i - 1) + 1) % mod;
            update(i, dp[i]);
        }
        else {
            dp[i] = (sum(i - 1) - sum(pre[a[i]] - 1) + mod) % mod;
            update(pre[a[i]], -dp[pre[a[i]]]);
            update(i, dp[i]);
        }
        pre[a[i]] = i;
    }
    cout << sum(n) << endl;
    return 0;
}