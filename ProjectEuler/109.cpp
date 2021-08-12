/*
 * @Author: tusikalanse
 * @Date: 2021-07-30 15:38:50
 * @LastEditTime: 2021-07-30 16:10:16
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

vector<pair<int, int>> darts;

int cnt[200];
int sum[200];

unordered_map<int, int> vis;

int main() {
    for (int i = 1; i <= 20; ++i) {
        darts.push_back({i, 0});
        darts.push_back({2 * i, 1});
        darts.push_back({3 * i, 0});
    }
    darts.push_back({25, 0});
    darts.push_back({50, 1});
    for (int i = 0; i < darts.size(); ++i) {
        int res1 = darts[i].first;
        if (darts[i].second)
            cnt[res1]++;
        for (int j = 0; j < darts.size(); ++j) {
            int res2 = res1 + darts[j].first;
            if (darts[j].second) {
                cnt[res2]++;
            }
            for (int k = 0; k < darts.size(); ++k) {
                int res3 = res2 + darts[k].first;
                if (darts[k].second && !vis[i * 10000 + j * 100 + k]) {
                    cnt[res3]++;
                    vis[i * 10000 + j * 100 + k] = vis[j * 10000 + i * 100 + k] = 1;
                }
            }
        }
    }
    for (int i = 1; i < 200; ++i) {
        sum[i] = sum[i - 1] + cnt[i];
    }
    cout << sum[99] << " " << sum[170] << endl;
    return 0;
}