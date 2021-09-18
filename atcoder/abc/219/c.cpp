/*
 * @Author: tusikalanse
 * @Date: 2021-09-18 19:52:04
 * @LastEditTime: 2021-09-18 20:08:06
 * @LastEditors: tusikalanse
 * @Description: 
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

const int N = 1e5 + 10;

int n;
char X[30];
int val[30];

struct node {
    char s[15];
    bool operator< (const node &rhs) const { 
        for (int i = 0; s[i]; ++i) {
            if (s[i] != rhs.s[i]) {
                return val[s[i] - 'a'] < val[rhs.s[i] - 'a'];
            }
        }
        return true;
    }
}p[N];


int main() {
    scanf("%s%d", X, &n);
    for (int i = 0; i < 26; ++i) {
        val[X[i] - 'a'] = i;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%s", p[i].s);
    }
    sort(p, p + n);
    for (int i = 0; i < n; ++i) {
        printf("%s\n", p[i].s);
    }
    return 0;
}