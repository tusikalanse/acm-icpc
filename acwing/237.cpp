/*
 * @Description:
 * @Version: 2.0
 * @Autor: tusikalanse
 * @Date: 2021-11-21 23:39:43
 * @LastEditors: tusikalanse
 * @LastEditTime: 2021-12-22 19:35:26
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

const int N = 1e5 + 10;

int sg[N];

int SG(int x) {
    if (sg[x] != -1)
        return sg[x];
    vector<int> v;
    map<int, int> vis;
    for (int i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            v.push_back(i);
            if (i * i != x && i != 1)
                v.push_back(x / i);
        }
    }
    int ans = 0;
    for (int i : v) {
        ans ^= SG(i);
    }
    for (int i : v) {
        vis[ans ^ SG(i)] = 1;
    }
    sg[x] = 0;
    while (vis[sg[x]])
        sg[x]++;
    return sg[x];
}

int n, a[N];

int main() {
    memset(sg, -1, sizeof(sg));
    sg[1] = 0;
    while (~scanf("%d", &n)) {
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            ans ^= SG(a[i]);
        }
        if (ans)
            puts("freda");
        else
            puts("rainbow");
    }
    return 0;
}