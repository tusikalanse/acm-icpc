/*
 * @Author: tusikalanse
 * @Date: 2021-07-08 12:30:30
 * @LastEditTime: 2021-07-08 12:39:54
 * @LastEditors: Please set LastEditors
 * @Description: 
 * @FilePath: /ProjectEuler/29.cpp
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

int mn[105], num[105];

int main() {
    set<pair<int, int>> x;
    for (int i = 2; i <= 100; ++i) {
        if (mn[i] == 0) {
            mn[i] = i;
            num[i] = 1;
        }
        int cnt = 2, x = i * i;
        while (x <= 100) {
            if (mn[x] == 0) {
                mn[x] = i;
                num[x] = cnt;
            }
            cnt++;
            x *= i;
        }
    }
    for (int a = 2; a <= 100; ++a) {
        for (int b = 2; b <= 100; ++b) {
            x.insert(make_pair(mn[a], num[a] * b));
        }
    }
    cout << x.size() << endl;
    return 0;
}
