/*
 * @Description: 
 * @Version: 2.0
 * @Autor: tusikalanse
 * @Date: 2021-08-22 19:51:14
 * @LastEditors: tusikalanse
 * @LastEditTime: 2021-08-22 20:07:49
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

const int N = 2e5 + 10;
int n, m, a[N], b[N];
int ans, mask[2];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        mask[0] |= 1 << a[i];
    }
    for (int i = 1; i <= m; ++i) {
        scanf("%d", &b[i]);
        mask[1] |= 1 << b[i];
    }
    if ((mask[0] & mask[1]) != mask[1]) {
        puts("-1");
        return 0;
    }
    ans = m;
    int d = 1e9;
    for (int i = 2; i <= n; ++i) {
        if (a[i] != a[1]) {
            d = min(d, i - 1);
            d = min(d, n + 1 - i);
        }
    }
    if (mask[1] != (1 << a[1])) {
        ans += d - 1;
    }
    if (a[1] != b[1])
        ans++;
    for (int i = 2; i <= m; ++i) {
        if (b[i] != b[i - 1]) {
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}