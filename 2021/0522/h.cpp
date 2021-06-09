#include <bits/stdc++.h>
using namespace std;

const int N = 21;

char s[50002];
char ss[5] = "RULD";

int n = 20, m = 20;
char mp[N][N] = {
    "11111111111111111111",
    "00000000000000000001",
    "11111111111111111111",
    "10000000000000000000",
    "11111111111111111111",
    "00000000000000000001",
    "11111111111111111111",
    "10000000000000000000",
    "11111111111111111111",
    "00000000000000000001",
    "11111111111111111111",
    "10000000000000000000",
    "11111111111111111111",
    "00000000000000000001",
    "11111111111111111111",
    "10000000000000000000",
    "11111111111111111111",
    "00000000000000000001",
    "11111111111111111111",
    "10000000000000000000"
};

bool judge() {
    int x = 0, y = 0;
    bool flag = true;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (mp[i][j] == '0') continue;
            int dx = i, dy = j;
            for (int k = 0; k < 50000; ++k) {
                if (s[k] == 'U') {
                    if (dx >= 2 && mp[dx - 1][dy] == '1')
                        dx--;
                }
                else if (s[k] == 'D') {
                    if (dx < n && mp[dx + 1][dy] == '1')
                        dx++;
                }
                else if (s[k] == 'L') {
                    if (dy >= 2 && mp[dx][dy - 1] == '1')
                        dy--;
                }
                else if (s[k] == 'R') {
                    if (dy < m && mp[dx][dy + 1] == '1')
                        dy++;
                }
            }
            if (x == 0) {
                x = dx, y = dy;
            }
            else {
                if (x != dx || y != dy)
                    flag = false;
            }
        }
    }
    return flag;
}

int main() {
    int ans = 0;
    for (int i = 1; i <= 500; ++i) {
        for (int j = 0; j < 50000; ++j) {
            s[j] = ss[rand() % 4];
        }
        cout << i << " " << ans << endl;
    }
    return 0;
}