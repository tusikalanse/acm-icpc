/*
 * @Author: tusikalanse
 * @Date: 2021-06-09 20:09:25
 * @LastEditTime: 2021-06-09 20:49:07
 * @LastEditors: tusikalanse
 * @Description: 
 * @FilePath: /algo/cf/1536/c.cpp
 */

#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}

const int N = 5e5 + 10;

int t, n;
char s[N];
map<pair<int, int>, int> cnt;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        scanf("%s", s + 1);
        int x = 0, y = 0;
        cnt.clear();
        for (int i = 1; i <= n; ++i) {
            if (s[i] == 'D') x++;
            else y++;
            int g = gcd(x, y);
            printf("%d ", ++cnt[{x / g, y / g}]);
        }
        printf("\n");
    }
    return 0;
}
