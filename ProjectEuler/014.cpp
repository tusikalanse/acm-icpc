/*
 * @Author: tusikalanse
 * @Date: 2021-06-29 00:50:49
 * @LastEditTime: 2021-06-29 01:05:18
 * @LastEditors: tusikalanse
 * @Description:
 * @FilePath: /atcoder/mnt/e/algo/ProjectEuler/14.cpp
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

int s[N * 100];
unordered_map<LL, int> ss;

int& step(LL x) {
    // cout << x << " " << ss.size() << endl;
    if (x <= 100 * N)
        return s[x];
    return ss[x];
}

int gao(LL x) {
    if (step(x))
        return step(x);
    return step(x) = x % 2 == 0 ? gao(x / 2) + 1 : gao(3 * x + 1) + 1;
}

int main() {
    int ans = 1;
    step(1) = 1;
    for (int i = 2; i <= N; ++i) {
        if (gao(i) > step(ans))
            ans = i;
        // cout << i << " " << ans << " " << step(ans) << " " << ss.size() << endl;
    }
    cout << ans << endl;
    return 0;
}
