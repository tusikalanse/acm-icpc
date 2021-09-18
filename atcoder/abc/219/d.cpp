/*
 * @Author: tusikalanse
 * @Date: 2021-09-18 19:52:08
 * @LastEditTime: 2021-09-18 20:26:32
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

const int N = 310;

int n, x, y;

struct node {
    int a, b;
}p[N];

int sa = 0, sb = 0;

int dp[N][N];
int ans = 30000;

int gao(int x) {
    return min(x, 300);
}

int main() {
    cin >> n >> x >> y;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i].a >> p[i].b;
        sa += p[i].a;
        sb += p[i].b;
    }
    if (sa < x || sb < y) {
        puts("-1");
        return 0;
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i - 1; j >= 0; --j) {
            for (int k = 0; k <= 300; ++k) {
                if (dp[j][k] != -1)
                    dp[j + 1][gao(k + p[i].a)] = max(dp[j + 1][gao(k + p[i].a)], dp[j][k] + p[i].b);
            }
        }
    }
    for (int j = 0; j <= n; ++j) {
        for (int k = x; k <= 300; ++k) {
            if (dp[j][k] >= y) {
                ans = j;
                printf("%d\n", ans);
                // cout << j << " " << k << " " << dp[j][k] << endl;
                return 0;
            }
        }
    }


    
    return 0;
}