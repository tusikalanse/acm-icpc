/*
 * @Author: tusikalanse
 * @Date: 2021-08-17 09:51:34
 * @LastEditTime: 2021-08-17 10:02:38
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

inline int lowbit(int x) {
    return x & -x;
}

int p2[70000];

int main() {
    {
        int x = 1, c = 0;
        do {
            p2[x] = c;
            x *= 2;
            c++;
        } while (x < 70000);
    }
    int ans = 0;
    string s;
    while (getline(cin, s)) {
        unordered_map<int, int> vis;
        unordered_map<int, int> sum;
        istringstream ss(s);
        vector<int> a;
        int x;
        while (ss >> x)
            a.push_back(x);
        sort(a.begin(), a.end());
        bool flag = true;
        int n = a.size(), mask = 1 << n;
        int presum = a[0], sufsum = 0;
        if (presum <= sufsum)
            flag = false;
        for (int j = 1, k = n - 1; j < k; ++j, --k) {
            presum += a[j];
            sufsum += a[k];
            if (presum <= sufsum)
                flag = false;
        }
        if (flag == false) {
            continue;
        }
        for (int i = 1; i < mask; ++i) {
            sum[i] = sum[i ^ lowbit(i)] + a[p2[lowbit(i)]];
            if (vis[sum[i]])
                flag = false;
            vis[sum[i]] = 1;
        }
        if (flag) {
            for (int i : a)
                ans += i;
        }
    }
    cout << ans << endl;
    return 0;
}