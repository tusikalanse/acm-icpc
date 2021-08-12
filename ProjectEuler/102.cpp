/*
 * @Author: tusikalanse
 * @Date: 2021-08-12 20:31:47
 * @LastEditTime: 2021-08-12 20:49:19
 * @LastEditors: tusikalanse
 * @Description: judge point in triangle
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

struct Point {
    int x, y;
};

bool Cross_product(Point p0, Point p1, Point p2) {
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y) >= 0;
}

int main() {
    Point d1, d2, d3, a;
    a.x = a.y = 0;
    int ans = 0;
    while (cin >> d1.x >> d1.y >> d2.x >> d2.y >> d3.x >> d3.y) {
        bool f1 = Cross_product(d1, d2, a), f2 = Cross_product(d2, d3, a), f3 = Cross_product(d3, d1, a);
        ans += f1 == f2 && f2 == f3;
    }
    cout << ans << endl;
    return 0;
}
