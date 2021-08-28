/*
 * @Description: 
 * @Version: 2.0
 * @Autor: tusikalanse
 * @Date: 2021-08-22 19:50:49
 * @LastEditors: tusikalanse
 * @LastEditTime: 2021-08-22 20:30:40
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

LL n;

LL ans;

vector<LL> square;

LL getans(LL x) {
    LL l = 1, r = x, now = 0;
    while (l <= r) {
        LL mid = l + r >> 1;
        if (mid * (2 * x - mid) <= n) {
            now = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    return now;
}

int main() {
    cin >> n;
    LL x;
    for (x = 1; x * x <= n; ++x) {
        ans += x;
        ans %= mod;
    }
    for (LL now = getans(x), R; x <= n && now != 0; x = R + 1, now--) {
        R = (n + now * now) / (2 * now);
        //cout << now << " " << x << " " << R << endl;
        ans += (R - x + 1) % mod * now % mod;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}