/*
 * @Author: tusikalanse
 * @Date: 2021-06-26 19:48:59
 * @LastEditTime: 2021-06-26 20:09:27
 * @LastEditors: tusikalanse
 * @Description: 
 * @FilePath: /atcoder/abc/207/c.cpp
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

const int N = 2010;

double l[N], r[N];
int t[N], n;
int ans = 0;

bool gao(int x, int y) {
    if (r[x] < l[y]) return false;
    if (r[y] < l[x]) return false;
    return true;
}


int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> t[i] >> l[i] >> r[i];
        if (t[i] == 2)
            r[i] -= 0.1;
        if (t[i] == 3)
            l[i] += 0.1;
        if (t[i] == 4)
            l[i] += 0.1, r[i] -= 0.1;
        for (int j = 1; j < i; ++j) {
            ans += gao(j, i);
        }
    }
    cout << ans << endl;
    return 0;
}
