/*
 * @Author: tusikalanse
 * @Date: 2021-06-25 21:47:14
 * @LastEditTime: 2021-06-25 22:10:27
 * @LastEditors: tusikalanse
 * @Description: 
 * @FilePath: /ProjectEuler/11.cpp
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

int a[20][20];


int main() {
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j)
            cin >> a[i][j];
    }
    int ans = 0;
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j + 3 < 20; ++j) {
            int temp = 1;
            for (int k = j; k < j + 4; ++k)
                temp *= a[i][k];
            ans = max(ans, temp);
        }
    }
    for (int i = 0; i + 3 < 20; ++i) {
        for (int j = 0; j + 3 < 20; ++j) {
            int temp = 1;
            for (int ii = i, jj = j; ii < i + 4; ++ii, ++jj)
                temp *= a[ii][jj];
            ans = max(ans, temp);
        }
    }
    for (int i = 0; i + 3 < 20; ++i) {
        for (int j = 19; j - 3 >= 0; --j) {
            int temp = 1;
            for (int ii = i, jj = j; ii < i + 4; ++ii, --jj)
                temp *= a[ii][jj];
            ans = max(ans, temp);
        }
    }
    cout << ans << endl;
    return 0;
}
