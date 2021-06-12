/*
 * @Author: tusikalanse
 * @Date: 2021-06-09 21:34:19
 * @LastEditTime: 2021-06-09 21:40:21
 * @LastEditors: tusikalanse
 * @Description: 
 * @FilePath: /algo/cf/1536/e.cpp
 */
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}

const int N = 2010, mod = 1e9 + 7;

int t, n, m;
char s[N][N];

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        int ans = 1, flag = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%s", s[i] + 1);
            for (int j = 1; j <= m; ++j) {
                if (s[i][j] == '#') 
                    ans = 2 * ans % mod;
                else 
                    flag = 1;
            }
        }
        if (flag == 0)
            ans = (ans + mod - 1) % mod;
        printf("%d\n", ans);
    }

    return 0;
}