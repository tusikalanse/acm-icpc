/*
 * @Author: tusikalanse
 * @Date: 2021-07-09 20:47:13
 * @LastEditTime: 2021-07-09 20:55:29
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

unordered_map<LL, int> P, H;

void getP(LL end) {
    static LL n = 1, p = 0;
    do {
        p = n * (3 * n - 1) / 2;
        P[p] = 1;
        n++;
    } while (p < end);
}

void getH(LL end) {
    static LL n = 1, h = 0;
    do {
        h = n * (2 * n - 1);
        H[h] = 1;
        n++;
    } while (h < end);
}

int main() {
    int cnt = 0;
    LL now = 0;
    while (true) {
        now += ++cnt;
        getH(now);
        getP(now);
        if (H[now] && P[now]) {
            cout << now << endl;
            if (now > 40755)
                break;
        }
    }
    return 0;
}