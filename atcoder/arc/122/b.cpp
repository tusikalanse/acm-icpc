/*
 * @Author: tusikalanse
 * @Date: 2021-06-12 20:33:13
 * @LastEditTime: 2021-06-12 20:37:22
 * @LastEditors: tusikalanse
 * @Description: 
 * @FilePath: /undefined/mnt/e/algo/atcoder/arc/122/b.cpp
 */
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}

const int N = 1e5 + 10;

int n, a[N];

double check(double x) {
    double ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += x + a[i] - min(0.0 + a[i], 2 * x);
    return ans / n;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    double l = 0, r = 1e9;
    while (r - l > 1e-6) {
        double ll = l + (r - l) / 3;
        double rr = r - (r - l) / 3;
        if (check(ll) > check(rr)) 
            l = ll;
        else
            r = rr;
    }
    printf("%.15f\n", check(l));
    return 0;
}
