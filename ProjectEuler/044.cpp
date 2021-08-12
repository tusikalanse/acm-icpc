/*
 * @Author: tusikalanse
 * @Date: 2021-07-09 20:43:35
 * @LastEditTime: 2021-07-09 20:53:38
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

int p[10010];
unordered_map<int, int> vis;

int main() {
    for (int i = 1; i <= 3000; ++i) {
        p[i] = i * (3 * i - 1) / 2;
        vis[p[i]] = 1;
    }
    int x = 1e9;
    for (int j = 1; j <= 3000; ++j) {
        for (int k = 2; k <= 3000; ++k) {
            if (vis[p[j] + p[k]] && vis[p[k] - p[j]]) {
                x = min(x, p[k] - p[j]);
                cout << j << " " << k << " " << x << endl;
            }
        }
    }
    return 0;
}