/*
 * @Author: tusikalanse
 * @Date: 2021-07-09 20:32:18
 * @LastEditTime: 2021-07-09 20:35:55
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

int vis[11000];

int main() {
    int ans = 0, cnt = 0;
    while (ans < 10000) {
        ans += ++cnt;
        vis[ans] = 1;
    }
    string s;
    cnt = 0;
    while (cin >> s) {
        int d = 0;
        for (char x : s)
            d += x - 'A' + 1;
        cnt += vis[d];
    }
    cout << cnt << endl;
    return 0;
}