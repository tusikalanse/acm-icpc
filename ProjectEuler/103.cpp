/*
 * @Author: tusikalanse
 * @Date: 2021-08-16 20:27:53
 * @LastEditTime: 2021-08-17 09:48:29
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

int dp[10][1000];
int a[10], sum, mn_sum = 1e9, mx_sum = 0;

void dfs(int now, int num, int total) {
    if (now == total) {
        if (sum >= mn_sum)
            return;
        mn_sum = sum;
        for (int i = 0; i < now; ++i)
            cout << a[i];
        cout << endl;
        return;
    }
    for (int i = num; i < 50; ++i) {
        bool flag = true;
        if (now > 1) {
            int presum = a[0] + a[1], sufsum = i;
            if (presum <= sufsum)
                flag = false;
            for (int j = 2, k = now - 1; j < k; ++j, --k) {
                presum += a[j];
                sufsum += a[k];
                if (presum <= sufsum)
                    flag = false;
            }
        }
        if (flag == false)
            break;
        for (int j = 0; j <= mx_sum; ++j) {
            dp[now + 1][j] = dp[now][j];
        }
        for (int j = 0; j <= mx_sum - i; ++j) {
            dp[now + 1][j + i] += dp[now][j];
            if (dp[now + 1][j + i] > 1) {
                flag = false;
            }
        }
        if (flag == false)
            continue;
        sum += i;
        mx_sum = max(mx_sum, sum);
        a[now] = i;
        dfs(now + 1, i + 1, total);
        sum -= i;
    }
}

int main() {
    dp[0][0] = 1;
    dfs(0, 1, 7);
    return 0;
}