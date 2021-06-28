/*
 * @Author: tusikalanse
 * @Date: 2021-06-26 19:49:15
 * @LastEditTime: 2021-06-28 23:20:48
 * @LastEditors: tusikalanse
 * @Description: 
 * @FilePath: /atcoder/abc/207/f.cpp
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

LL dp[N][N][3];
//0: takahashi in i
//1: no takahashi in i, i guarded
//2: i not guarded
int n;
vector<int> G[N];
int sz[N];
int temp[N][3];

void dfs(int rt, int fa) {
    dp[rt][0][2] = 1;
    dp[rt][1][0] = 1;
    sz[rt] = 1;
    for (auto son: G[rt]) {
        if (son == fa) continue;
        dfs(son, rt);
        for (int i = 0; i <= sz[rt] + sz[son] + 2; ++i) {
            for (int j = 0; j < 3; ++j)
                temp[i][j] = 0;
        }
        for (int i = 0; i <= sz[rt]; ++i) {
            for (int j = 0; j <= sz[son]; ++j) {
                (temp[i + j][2] += dp[rt][i][2] * dp[son][j][1] % mod) %= mod;
                (temp[i + j][2] += dp[rt][i][2] * dp[son][j][2] % mod) %= mod;
                (temp[i + j][1] += dp[rt][i][1] * dp[son][j][0] % mod) %= mod;
                (temp[i + j][1] += dp[rt][i][1] * dp[son][j][1] % mod) %= mod;
                (temp[i + j][1] += dp[rt][i][1] * dp[son][j][2] % mod) %= mod;
                (temp[i + j + 1][1] += dp[rt][i][2] * dp[son][j][0] % mod) %= mod;
                (temp[i + j][0] += dp[rt][i][0] * dp[son][j][0] % mod) %= mod;
                (temp[i + j][0] += dp[rt][i][0] * dp[son][j][1] % mod) %= mod;
                (temp[i + j + 1][0] += dp[rt][i][0] * dp[son][j][2] % mod) %= mod;
            }
        }
        sz[rt] += sz[son];
        for (int i = 0; i <= sz[rt]; ++i) {
            for (int j = 0; j < 3; ++j) {
                dp[rt][i][j] = temp[i][j];
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);
    for (int k = 0; k <= n; ++k) {
        cout << (dp[1][k][0] + dp[1][k][1] + dp[1][k][2]) % mod << endl; 
    }
    return 0;
}
