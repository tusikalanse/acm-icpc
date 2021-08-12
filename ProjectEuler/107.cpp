/*
 * @Author: tusikalanse
 * @Date: 2021-07-29 11:23:25
 * @LastEditTime: 2021-07-29 11:32:58
 * @LastEditors: tusikalanse
 * @Description: minimum spanning tree kruskal
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

const int N = 1010;

int fa[N];

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

bool unite(int x, int y) {
    int fx = find(x), fy = find(y);
    fa[fx] = fy;
    return fx == fy;
}

struct edge {
    int from, to, weight;
    bool operator<(const edge &rhs) const { return weight < rhs.weight; }
};

vector<edge> G;
int ans = 0, total = 0;

int main() {
    int n = 40;
    for (int i = 0; i < n; ++i) {
        fa[i] = i;
        for (int j = 0; j < n; ++j) {
            int w;
            cin >> w;
            if (j > i && w != 0) {
                G.push_back({i, j, w});
                total += w;
            }
        }
    }
    sort(G.begin(), G.end());
    for (auto e : G) {
        if (!unite(e.from, e.to)) {
            ans += e.weight;
        }
    }
    cout << ans << endl;
    cout << total << endl;
    cout << total - ans << endl;
    return 0;
}