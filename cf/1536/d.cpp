/*
 * @Author: tusikalanse
 * @Date: 2021-06-09 21:19:15
 * @LastEditTime: 2021-06-09 21:27:21
 * @LastEditors: tusikalanse
 * @Description: 
 * @FilePath: /algo/cf/1536/d.cpp
 */
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}

const int N = 2e5 + 10;
int t, n;
int a[N];

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
        }
        bool flag = false;
        set<int> s;
        s.insert(a[1]);
        for (int i = 2; i <= n; ++i) {
            s.insert(a[i]);
            if (a[i] != a[i - 1]) {
                if (a[i] > a[i - 1]) {
                    auto it = s.lower_bound(a[i]);
                    if (it == s.begin() || *--it != a[i - 1])
                        flag = true;
                }
                else {
                    auto it = s.lower_bound(a[i]);
                    if (it == s.end() || ++it == s.end() || *it != a[i - 1])
                        flag = true;
                }
            }
            if (flag)
                break;
        }
        puts(flag ? "NO" : "YES");
    }
    return 0;
}
