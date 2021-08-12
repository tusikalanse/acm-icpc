/*
 * @Author: tusikalanse
 * @Date: 2021-07-09 20:20:05
 * @LastEditTime: 2021-07-09 20:22:00
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

int main() {
    int mx = 0, id = 0;
    for (int p = 12; p <= 1000; ++p) {
        int cnt = 0;
        for (int a = 1; a <= p; ++a) {
            for (int b = a + 1; b <= p; ++b) {
                int c = p - a - b;
                if (c <= b)
                    continue;
                if (a * a + b * b == c * c) {
                    cnt++;
                }
            }
        }
        if (cnt > mx) {
            mx = cnt;
            id = p;
            cout << id << " " << cnt << endl;
        }
    }
    return 0;
}