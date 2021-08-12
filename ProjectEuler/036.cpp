/*
 * @Author: tusikalanse
 * @Date: 2021-07-09 09:06:59
 * @LastEditTime: 2021-07-09 09:10:35
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

bool is_palindrom(string x) {
    string t = x;
    reverse(t.begin(), t.end());
    return x == t;
}

// return reversed binary presentation of x
string binary(int x) {
    string ans = "";
    while (x) {
        ans += '0' + x % 2;
        x /= 2;
    }
    return ans;
}

bool gao(int x) {
    return is_palindrom(to_string(x)) && is_palindrom(binary(x));
}

int main() {
    LL ans = 0;
    for (int i = 1; i <= 1000000; ++i) {
        if (gao(i)) {
            cout << i << endl;
            ans += i;
        }
    }
    cout << ans << endl;
    return 0;
}