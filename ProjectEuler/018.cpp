/*
 * @Author: tusikalanse
 * @Date: 2021-06-30 22:15:44
 * @LastEditTime: 2021-06-30 22:21:07
 * @LastEditors: tusikalanse
 * @Description: 
 * @FilePath: /ProjectEuler/18.cpp
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

const int N = 16;

LL a[N][N];

int main() {
    int n = 15;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j)
            cin >> a[i][j];
    }
    for (int i = 2; i <= n; ++i) {
        a[i][1] += a[i - 1][1];
        a[i][i] += a[i - 1][i - 1];
        for (int j = 2; j < i; ++j)
            a[i][j] += max(a[i - 1][j - 1], a[i - 1][j]);
    }
    cout << *max_element(a[n] + 1, a[n] + n + 1) << endl;
    return 0;
}
