/*
 * @Author: tusikalanse
 * @Date: 2021-07-08 21:11:18
 * @LastEditTime: 2021-07-08 21:17:58
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

bool gao(int x, int y, int z) {
    vector<int> vis(10, 0);
    vis[0] = 1;
    int cnt = 0;
    while (x) {
        if (vis[x % 10])
            return false;
        vis[x % 10] = 1;
        x /= 10;
        cnt++;
    }
    while (y) {
        if (vis[y % 10])
            return false;
        vis[y % 10] = 1;
        y /= 10;
        cnt++;
    }
    while (z) {
        if (vis[z % 10])
            return false;
        vis[z % 10] = 1;
        z /= 10;
        cnt++;
    }
    return cnt == 9;
}

int main() {
    set<int> ans;
    for (int a = 1; a <= 3000; ++a) {
        for (int b = a; b <= 3000; ++b) {
            if (gao(a, b, a * b)) {
                ans.insert(a * b);
            }
        }
    }
    int total = 0;
    for (auto i : ans)
        total += i;
    cout << total << endl;
    return 0;
}
