/*
 * @Description: 
 * @Version: 2.0
 * @Autor: tusikalanse
 * @Date: 2021-08-14 19:48:48
 * @LastEditors: tusikalanse
 * @LastEditTime: 2021-08-14 23:31:31
 */
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

const int N = 2e5 + 10;

int f[N];
char s[N];
int n;

int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    f[1] = 1;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j; --j) {
            f[i + 2] = (f[i + 2] + f[j]) % mod;
            if (j > 1 && s[j - 1] == s[i]) break;
        }
        ans = (ans + f[i + 2]) % mod;
    }
    printf("%d\n", ans);
    return 0;
}