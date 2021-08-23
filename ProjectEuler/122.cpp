/*
 * @Author: tusikalanse
 * @Date: 2021-08-20 21:10:46
 * @LastEditTime: 2021-08-20 21:12:39
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

const int N = 220;

int n = 200;

int dp[N], path[N];

void dfs(int power, int depth) {
    if (power > n || depth > dp[power])
        return;
    dp[power] = depth;
    path[depth] = power;
    for (int i = depth; i >= 0; --i) {
        dfs(power + path[i], depth + 1);
    }
}

int main() {
    memset(dp, 0x3f, sizeof(dp));
    dfs(1, 0);
    int sum = 0;
    for (int i = 1; i <= n; ++i)
        sum += dp[i];
    cout << sum << endl;
    return 0;
}