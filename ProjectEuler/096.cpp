/*
 * @Description: SudoKu
 * @Version: 2.0
 * @Autor: tusikalanse
 * @Date: 2021-07-28 22:48:50
 * @LastEditors: tusikalanse
 * @LastEditTime: 2021-07-28 23:11:22
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

inline int getBoxId(int row, int col) {
    return row / 3 * 3 + col / 3;
}

int SuDoku[10][10];
int origin[10][10];
int vis[3][10][10]; //[row/col/box][id][num]

int ans = 0;

void dfs(int row, int col) {
    if (col == 9) {
        dfs(row + 1, 0);
        return;
    }
    if (row == 9) {
        // for (int i = 0; i < 9; ++i) {
        //     for (int j = 0; j < 9; ++j)
        //         cout << SuDoku[i][j] << " ";
        //     cout << endl;
        // }
        ans += SuDoku[0][0] * 100 + SuDoku[0][1] * 10 + SuDoku[0][2];
        return;
    }
    if (origin[row][col] != 0) {
        dfs(row, col + 1);
        return;
    }
    for (int i = 1; i < 10; ++i) {
        if (vis[0][row][i]) continue;
        if (vis[1][col][i]) continue;
        if (vis[2][getBoxId(row, col)][i]) continue;
        vis[0][row][i] = vis[1][col][i] = vis[2][getBoxId(row, col)][i] = 1;
        SuDoku[row][col] = i;
        dfs(row, col + 1);
        vis[0][row][i] = vis[1][col][i] = vis[2][getBoxId(row, col)][i] = 0;
    }
}

int main() {
    string s;
    while (cin >> s) {
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < 9; ++i) {
            cin >> s;
            for (int j = 0; j < 9; ++j) {
                SuDoku[i][j] = origin[i][j] = s[j] - '0';
                if (SuDoku[i][j] != 0) {
                    vis[0][i][SuDoku[i][j]] = vis[1][j][SuDoku[i][j]] = vis[2][getBoxId(i, j)][SuDoku[i][j]] = 1;
                }
            }
        }
        dfs(0, 0);
    }
    cout << ans << endl;
    return 0;
}