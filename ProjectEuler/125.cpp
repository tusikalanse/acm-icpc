/*
 * @Author: tusikalanse
 * @Date: 2021-08-20 10:21:10
 * @LastEditTime: 2021-08-20 20:23:46
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

const int N = 1e8;

bool is_palindrom(string x) {
    string t = x;
    reverse(t.begin(), t.end());
    return x == t;
}

unordered_set<int> s;

int main() {
    for (int start = 1; start * start <= N; ++start) {
        int sum = start * start + (start + 1) * (start + 1);
        for (int j = start + 2; sum <= N; ++j) {
            s.insert(sum);
            sum += j * j;
        }
    }
    LL ans = 0;
    for (int it : s) {
        if (is_palindrom(to_string(it))) {
            ans += it;
        }
    }
    cout << ans << endl;
    return 0;
}