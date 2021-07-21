/*
 * @Author: tusikalanse
 * @Date: 2021-07-20 17:13:56
 * @LastEditTime: 2021-07-20 17:18:30
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

bool is_square(int x) {
    int d = sqrt(x + 0.5);
    return d * d == x;
}

const int N = 1e6;

int gao(int x) {
    int ans = 0;
    for (int i = 1; i <= x; ++i) {
        for (int j = i; j <= x; ++j) {
            for (int k = j; k <= x; ++k) {
                int d = i * i + j * j + k * k + 2 * i * j;
                ans += is_square(d);
            }
        }
    }
    return ans;
}

int main() {
    int ans = 0, l = 100, r = 2000;
    while (l <= r) {
        int mid = l + r >> 1;
        if (gao(mid) > N) {
            r = mid - 1;
            ans = mid;
        }
        else 
            l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}