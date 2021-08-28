/*
 * @Description: 
 * @Version: 2.0
 * @Autor: tusikalanse
 * @Date: 2021-08-22 19:51:02
 * @LastEditors: tusikalanse
 * @LastEditTime: 2021-08-22 22:08:24
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

const int N = 2e5 + 10;

int n, k;
int a[N];
int vis[N];
vector<int> p;
queue<int> q;

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= k; ++i) {
        scanf("%d", &a[i]);
        vis[a[i]] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i])
            q.push(i);
    }
    if (k == 1) {
        for (int i = n; i >= 1; --i) {
            printf("%d%c", i, " \n"[i == 1]);
        }
        return 0;
    }
    for (int i = 1; i < k; ++i) {
        p.push_back(a[i]);
        if(!q.empty() && q.front() < a[i]) {
            p.push_back(q.front());
            vis[q.front()] = 1;
            q.pop();
        }
    }
    for (int i = n; i > a[k]; --i) {
        p.push_back(i);
        vis[i] = 1;
    }
    p.push_back(a[k]);
    for (int i = n; i; --i) {
        if (vis[i]) continue;
        p.push_back(i);
        vis[i] = 1;
    }
    assert((int)p.size() == n);
    for (int i = 0; i < n; ++i) {
        printf("%d%c", p[i], " \n"[i == n - 1]);
    }
    return 0;
}