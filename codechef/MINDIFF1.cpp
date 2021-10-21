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

const int N = 3e5 + 10;

int T, d[N], n, m, x, y, mx;
int a[N];

vector<int> G[N];

int main() {
    scanf("%d", &T);
    while (T--) {
        mx = 0;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) {
            d[i] = 0;
            a[i] = 0;
            G[i].clear();
        }
        for (int i = 1; i <= m; ++i) {
            scanf("%d%d", &x, &y);
            G[x].push_back(y);
            G[y].push_back(x);
            d[x]++;
            d[y]++;
        }
        set<pair<int, int>> pq;
        for (int i = 1; i <= n; ++i) {
            pq.insert(pair<int, int>(d[i], i));
        }
        while (!pq.empty()) {
            auto u = pq.begin();
            a[u->second] = pq.size();
            pq.erase(u);
            mx = max(mx, u->first);
            for (auto i: G[u->second]) {
                if (a[i] != 0) continue;
                pair<int, int> x(d[i], i);
                pq.erase(x);
                x.first--;
                d[i]--;
                pq.insert(x);
            }
        }
        printf("%d\n", mx);
        for (int i = 1; i <= n; ++i) {
            printf("%d%c", a[i], " \n"[i == n]);
        }
    }
    return 0;
}