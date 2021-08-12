/*
 * @Author: tusikalanse
 * @Date: 2021-07-22 16:13:53
 * @LastEditTime: 2021-07-22 16:24:51
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

map<int, int> cnt;

bool check(int prod, int sum, int k) {
    if (k > sum || sum <= 0)
        return false;
    if (prod == 1)
        return k == sum;
    if (k == 1)
        return prod == sum;
    for (int i = 2; i <= prod && sum - i >= k - 1; ++i) {
        if (prod % i == 0 && check(prod / i, sum - i, k - 1))
            return true;
    }
    return false;
}

int gao(int x) {
    for (int i = x + 1;; ++i) {
        if (check(i, i, x))
            return i;
    }
}

int main() {
    int ans = 0;
    for (int i = 2; i <= 12000; ++i) {
        int k = gao(i);
        if (cnt[k] == 0) {
            cnt[k] = 1;
            ans += k;
        }
    }
    cout << ans << endl;
    return 0;
}