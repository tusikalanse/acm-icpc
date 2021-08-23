/*
 * @Description: 
 * @Version: 2.0
 * @Autor: tusikalanse
 * @Date: 2021-08-21 19:52:19
 * @LastEditors: tusikalanse
 * @LastEditTime: 2021-08-21 20:15:34
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

bool notprime[N];
vector<int> primefactors[N];

void getprime() {
    memset(notprime, 0, sizeof(notprime));
    notprime[1] = 1;
    for (int i = 2; i < N; ++i) {
        if (!notprime[i]) {
            primefactors[i].push_back(i);
            for (int j = i + i; j < N; j += i) {
                notprime[j] = 1;
                primefactors[j].push_back(i);
            }
        }
    }
}

bool notvalid[N], vis[N];
int n, m, a[N], ans;

int main() {
    getprime();
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        if (a[i] == 1) continue;
        for (int x: primefactors[a[i]]) {
            if (vis[x]) continue;
            vis[x] = 1;
            for (int j = x; j <= m; j += x) {
                notvalid[j] = 1;
            }
        }
    }
    for (int i = 1; i <= m; ++i) {
        ans += notvalid[i] == 0;
    }
    printf("%d\n", ans);
    for (int i = 1; i <= m; ++i) {
        if (notvalid[i] == 0) {
            printf("%d\n", i);
        }
    }
    return 0;
}