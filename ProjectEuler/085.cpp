/*
 * @Author: tusikalanse
 * @Date: 2021-07-19 20:32:33
 * @LastEditTime: 2021-07-19 20:43:24
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

const int N = 2e6;

int f[5000][5000];

int main() {
    int mindis = 1e9, ans = 0;
    for (int i = 1; i < 5000; i++) {
        f[i][1] = f[1][i] = i * (i + 1) / 2;
    }
    for (int i = 2; i < 5000; ++i) {
        for (int j = 2; j < 5000; ++j) {
            f[i][j] = 2 * f[i][j - 1] - f[i][j - 2] + f[1][i];
            if (abs(N - f[i][j]) < mindis) {
                mindis = abs(N - f[i][j]);
                ans = i * j;
                cout << i << " " << j << " " << f[i][j] << endl;
            }
            if (f[i][j] > N) break;
        }
    }
    cout << ans << endl;
    return 0;
}