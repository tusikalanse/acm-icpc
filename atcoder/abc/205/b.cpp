/*
 * @Author: tusikalanse
 * @Date: 2021-06-13 20:03:11
 * @LastEditTime: 2021-06-13 20:03:58
 * @LastEditors: tusikalanse
 * @Description: 
 * @FilePath: /undefined/mnt/e/algo/atcoder/abc/205/b.cpp
 */
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}

int a[1010], n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
        if (i != a[i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
