/*
 * @Author: tusikalanse
 * @Date: 2021-06-13 20:10:56
 * @LastEditTime: 2021-06-13 20:14:26
 * @LastEditors: tusikalanse
 * @Description: 
 * @FilePath: /undefined/mnt/e/algo/atcoder/abc/205/d.cpp
 */
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}

const int N = 1e5 + 10;

int n, q;
long long k, a[N];
long long sum[N];

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        sum[i] = sum[i - 1] + a[i] - a[i - 1] - 1;
    }
    while (q--) {
        scanf("%lld", &k);
        int pos = lower_bound(sum + 1, sum + n + 1, k) - sum;
        k -= sum[pos - 1];
        printf("%lld\n", a[pos - 1] + k);
    }

    return 0;
}
