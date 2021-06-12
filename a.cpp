/*
 * @Author: tusikalanse
 * @Date: 2021-06-09 20:28:56
 * @LastEditTime: 2021-06-09 20:36:23
 * @LastEditors: tusikalanse
 * @Description: 
 * @FilePath: /algo/a.cpp
 */
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}

const int N = 110;

int t, n, a[N];

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int neg = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            neg += a[i] < 0;
        }
        if (neg) {
            puts("NO");
        }
        else {
            puts("Yes\n101");
            for (int i = 0; i <= 100; ++i) {
                printf("%d ", i);
            }
            puts("");
        }
    }

    return 0;
}
