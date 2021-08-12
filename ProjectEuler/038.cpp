/*
 * @Author: tusikalanse
 * @Date: 2021-07-09 19:07:10
 * @LastEditTime: 2021-07-12 15:06:27
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

bool gao(vector<int> nums) {
    vector<int> vis(10, 0);
    vis[0] = 1;
    int cnt = 0;
    for (int x : nums) {
        while (x) {
            if (vis[x % 10])
                return false;
            vis[x % 10] = 1;
            x /= 10;
            cnt++;
        }
    }
    return cnt == 9;
}

int concatenate(vector<int> nums) {
    string x = "";
    for (int i : nums)
        x += to_string(i);
    return stoi(x);
}

int main() {
    int ans = 0;
    for (int n = 2; n <= 8; ++n) {
        for (int i = 1; i <= 100000; ++i) {
            vector<int> temp;
            for (int j = 1; j <= n; ++j) {
                temp.push_back(i * j);
            }
            if (gao(temp)) {
                ans = max(ans, concatenate(temp));
                cout << ans << endl;
            }
        }
    }
    cout << ans << endl;
    return 0;
}