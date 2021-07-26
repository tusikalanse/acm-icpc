/*
 * @Author: tusikalanse
 * @Date: 2021-07-14 22:18:26
 * @LastEditTime: 2021-07-14 22:48:29
 * @LastEditors: tusikalanse
 * @Description: dfs
 * @FilePath: /ProjectEuler/68.cpp
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

int a[10], vis[12];

LL ans = 0;

LL concatenate(vector<int> nums) {
    string x = "";
    for (int i: nums) {
        x += to_string(i);
    }
    return stoll(x);
}

vector<int> gao() {
    int id = 0;
    vector<int> v;
    for (int i = 1; i < 5; ++i) {
        if (a[i] < a[id])
            id = i;
    }
    for (int i = 0; i < 5; ++i) {
        v.push_back(a[(id + i) % 5]);
        v.push_back(a[(id + i) % 5 + 5]);
        v.push_back(a[((id + i) % 5 + 6) % 5 + 5]);
    }
    return v;
}

void check() {
    a[7] = a[0] + a[5] - a[1];
    if (a[7] < 1 || a[7] > 9 || vis[a[7]]) return;
    vis[a[7]] = 1;

    a[9] = a[2] + a[7] - a[3];
    if (a[9] < 1 || a[9] > 9 || vis[a[9]]) return;
    vis[a[9]] = 1;
    
    a[6] = a[4] + a[9] - a[0];
    if (a[6] < 1 || a[6] > 9 || vis[a[6]]) return;
    vis[a[6]] = 1;
    
    a[8] = a[1] + a[6] - a[2];
    if (a[8] < 1 || a[8] > 9 || vis[a[8]]) return;
    vis[a[8]] = 1;
    
    if (a[5] != a[3] + a[8] - a[4]) return;
    ans = max(ans, concatenate(gao()));
}

void dfs(int now) {
    if (now == 5) {
        if (!vis[10]) return;
        for (int i = 1; i <= 10; ++i) {
            if (!vis[i]) {
                vis[i] = 1;
                a[5] = i;
                check();
                for (int x = 5; x < 10; ++x)
                   vis[a[x]] = 0;
                for (int x = 0; x < 5; ++x)
                   vis[a[x]] = 1;
            }
        }
        return;
    }
    for (int i = 1; i <= 10; ++i) {
        if (!vis[i]) {
            vis[i] = 1;
            a[now] = i;
            dfs(now + 1);
            vis[i] = 0;
        }
    }
}

int main() {
    dfs(0);
    cout << ans << endl;
    return 0;
}
