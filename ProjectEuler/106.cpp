/*
 * @Author: tusikalanse
 * @Date: 2021-08-17 14:30:27
 * @LastEditTime: 2021-08-17 14:38:28
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

int vis[15];
int a[15];
int b[15];
int ans = 0;
int n = 12;

void dfs2(int now, int num, int total) {
    if (now * 2 == total) {
        if (a[now - 1] < b[now - 1])
            return;
        bool flag = false;
        for (int i = 0; i < now; ++i) {
            if (a[i] < b[i])
                flag = true;
        }
        ans += flag;
        return;
    }
    for (int i = num; i <= n; ++i) {
        if (vis[i])
            continue;
        vis[i] = 2;
        b[now] = i;
        dfs2(now + 1, i + 1, total);
        vis[i] = 0;
    }
}

void dfs1(int now, int num, int total) {
    if (now * 2 == total) {
        if (num > total)
            dfs2(0, 1, total);
        return;
    }
    for (int i = num; i <= n; ++i) {
        vis[i] = 1;
        a[now] = i;
        dfs1(now + 1, i + 1, total);
        vis[i] = 0;
    }
}

int main() {
    for (int i = 4; i <= n; i += 2)
        dfs1(0, 1, i);
    cout << ans << endl;
    return 0;
}