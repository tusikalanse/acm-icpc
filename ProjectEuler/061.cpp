/*
 * @Author: tusikalanse
 * @Date: 2021-07-12 15:29:10
 * @LastEditTime: 2021-07-12 17:24:40
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

const int N = 1e4 + 10;

int vis[N][10];
int rep[N];

void init(int x, int a, int b, int c) {
    int i = 1, n = 0;
    do {
        vis[n][x] = 1;
        vis[n][6] = 1;
        rep[n] |= 1 << x;
        n = (a * i * i + b * i) / c;
        i++;
    } while (n < 10000);
}

int p[10];
int used[N];

int ans = 0;

bool valid(vector<int> x) {
    sort(x.begin(), x.end());
    do {
        bool flag = true;
        for (int i = 0; i < 6; ++i)
            flag &= (x[i] >> i) & 1;
        if (flag)
            return true;
    } while (next_permutation(x.begin(), x.end()));
    return false;
}

void dfs(int now, int mask) {
    if (__builtin_popcount(mask) < now - 1)
        return;
    if (now == 6) {
        if (vis[p[5] * 100 + p[0]][6]) {
            ans = 0;
            int mask = 0;
            vector<int> v;
            for (int i = 0; i < 6; ++i) {
                mask |= rep[p[i] * 100 + p[(i + 1) % 6]];
                v.push_back(rep[p[i] * 100 + p[(i + 1) % 6]]);
            }
            if (mask != (1 << 6) - 1)
                return;
            if (!valid(v))
                return;
            for (int i = 0; i < 6; ++i) {
                ans += p[i] * 100 + p[(i + 1) % 6];
                cout << p[i] * 100 + p[(i + 1) % 6] << " ";
            }
            cout << ans << endl;
        }
        return;
    }
    for (int i = 10; i <= 99; ++i) {
        if (now == 0) {
            p[now] = i;
            dfs(now + 1, mask);
        } else {
            int x = p[now - 1] * 100 + i;
            if (vis[x][6] == 0 || used[x])
                continue;
            p[now] = i;
            used[x] = 1;
            dfs(now + 1, mask | rep[x]);
            used[x] = 0;
        }
    }
}

int main() {
    init(0, 1, 1, 2);
    init(1, 1, 0, 1);
    init(2, 3, -1, 2);
    init(3, 2, -1, 1);
    init(4, 5, -3, 2);
    init(5, 3, -2, 1);
    dfs(0, 0);
    return 0;
}