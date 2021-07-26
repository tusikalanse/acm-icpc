/*
 * @Author: tusikalanse
 * @Date: 2021-07-22 20:00:30
 * @LastEditTime: 2021-07-22 20:22:39
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

vector<int> todo{1, 4, 9, 16, 25, 36, 49, 64, 81};
int ans = 0;
int vis[2][10];
int a[2][10];

bool gao() {
    for (int x: todo) {
        bool f = false;
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 6; ++j) {
                if (a[0][i] * 10 + a[1][j] == x || a[1][j] * 10 + a[0][i] == x)
                    f = true;
                if (a[0][i] == 9) {
                    a[0][i] = 6;
                    if (a[0][i] * 10 + a[1][j] == x || a[1][j] * 10 + a[0][i] == x)
                        f = true;
                    a[0][i] = 9;
                }
                if (a[0][i] == 6) {
                    a[0][i] = 9;
                    if (a[0][i] * 10 + a[1][j] == x || a[1][j] * 10 + a[0][i] == x)
                        f = true;
                    a[0][i] = 6;
                }
                if (a[1][j] == 9) {
                    a[1][j] = 6;
                    if (a[0][i] * 10 + a[1][j] == x || a[1][j] * 10 + a[0][i] == x)
                        f = true;
                    a[1][j] = 9;
                }
                if (a[1][j] == 6) {
                    a[1][j] = 9;
                    if (a[0][i] * 10 + a[1][j] == x || a[1][j] * 10 + a[0][i] == x)
                        f = true;
                    a[1][j] = 6;
                }
            }
        }
        if (!f) 
            return false;
    }
    return true;
}

void dfs(int now, int pos, int p) {
    if (now == 6 && p == 1) {
        ans += gao();
        return;
    }
    if (now == 6) {
        dfs(0, 0, 1);
        return;
    }
    for (int i = pos; i < 10; ++i) {
        vis[p][i] = 1;
        a[p][now] = i;
        dfs(now + 1, i + 1, p);
        vis[p][i] = 0;
    }
}

int main() {
    dfs(0, 0, 0);
    cout << ans / 2 << endl;
    return 0;
}