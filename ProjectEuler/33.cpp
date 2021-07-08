/*
 * @Author: tusikalanse
 * @Date: 2021-07-08 21:22:16
 * @LastEditTime: 2021-07-08 21:37:27
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
    for (int x = 1; x <= 9; ++x) {
        for (int y = 0; y <= 9; ++y) {
            for (int a = 1; a <= 9; ++a) {
                for (int b = 0; b <= 9; ++b) {
                    if (x == a && y != b && (10 * x + y) * b == (10 * a + b) * y)
                        cout << x << y << "/" << a << b << endl;
                    else if (x == b && y != a && (10 * x + y) * a == (10 * a + b) * y)
                        cout << x << y << "/" << a << b << endl;
                    else if (y == a && x != b && (10 * x + y) * b == (10 * a + b) * x)
                        cout << x << y << "/" << a << b << endl;
                    else if (y == b && y != 0 && x != a && (10 * x + y) * a == (10 * a + b) * x)
                        cout << x << y << "/" << a << b << endl;
                }
            }
        }
    }
    return 0;
}
/*
16/64
19/95
26/65
49/98

prod = 1/100
*/
