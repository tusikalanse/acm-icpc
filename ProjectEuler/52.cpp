/*
 * @Author: tusikalanse
 * @Date: 2021-07-10 10:03:15
 * @LastEditTime: 2021-07-10 10:03:15
 * @LastEditors: tusikalanse
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

int num_of_digits(int x) {
    int cnt = 0;
    while (x) {
        cnt++;
        x /= 10;
    }
    return x;
}

bool is_permutation(int x, int y) {
    vector<int> a, b;
    while (x) {
        a.push_back(x % 10);
        x /= 10;
    }
    while (y) {
        b.push_back(y % 10);
        y /= 10;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a == b;
}

int main() {
    for (int i = 1; ; ++i) {
        if (num_of_digits(i) != num_of_digits(6 * i)) continue;
        if (!is_permutation(i, 2 * i)) continue;
        if (!is_permutation(i, 3 * i)) continue;
        if (!is_permutation(i, 4 * i)) continue;
        if (!is_permutation(i, 5 * i)) continue;
        if (!is_permutation(i, 6 * i)) continue;
        cout << i << endl;
        return 0;
    }
    return 0;
}