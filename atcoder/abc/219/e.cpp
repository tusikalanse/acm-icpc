/*
 * @Author: tusikalanse
 * @Date: 2021-09-18 19:52:15
 * @LastEditTime: 2021-09-18 21:32:34
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


map<long long, int> vis;
int v[10][10];
int d[10][10];
int dir[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};

long long get(int sx, int sy, int fx, int fy) {
    if (sx == fx) {
        int y = min(sy, fy);
        return 1LL << (y + 4 * sx);
    }
    else {
        int x = min(sx, fx);
        return 1LL << (20 + x + 4 * sy);
    }
}

void dfs(long long state, int posx, int posy, int startx, int starty) {
    v[posx][posy] = 1;
    for (int k = 0; k < 4; ++k) {
        int fx = posx + dir[k][0], fy = posy + dir[k][1];
        if (fx < 0 || fy < 0 || fx > 4 || fy > 4) continue;
        if (fx == startx && fy == starty) {
            if ((state & (get(fx, fy, posx, posy))) != 0) continue;
            vis[state | get(fx, fy, posx, posy)] = 1;
            continue;
        }
        if (v[fx][fy]) continue;
        long long now = get(posx, posy, fx, fy);
        // cout << state << " " << now << endl;
        assert((now & state) == 0);
        dfs(state | now, fx, fy, startx, starty);
    }
    v[posx][posy] = 0;
}

bool can(int i, int j, long long state) {
    cout << i << " " << j << endl;
    int cnt = 0;
    for (int p = 0; p <= j; ++p) {
        cnt += (state & (1LL << (i * 4 + p))) != 0;
    }
    cout << cnt << endl;
    if (cnt % 2 == 0) 
        return false;
    cnt = 0;
    for (int p = 0; p <= i; ++p) {
        cnt += (state & (1LL << (20 + j * 4 + p))) != 0;
    }
    cout << cnt << endl;
    return cnt % 2 == 1;
}

bool valid(long long state) {
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j) {
            if (d[i][j] == 0) continue;
            if (!can(i - 1, j - 1, state)) 
                return false;
        }
    }
    return true;
}

int main() {
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j) 
            cin >> d[i][j];
    }
    for (int sx = 0; sx <= 4; ++sx) {
        for (int sy = 0; sy <= 4; ++sy) {
            // dfs(0, sx, sy, sx, sy);
        }
    }
    vis[1095217184776] = 1;
    cout << vis.size() << endl;
    int ans = 0;
    for (auto s: vis) {
        ans += valid(s.first);
        cout << s.first << endl;
    }
    cout << ans << endl;
    return 0;
}