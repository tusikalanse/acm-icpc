/*
 * @Author: tusikalanse
 * @Date: 2021-10-25 19:06:31
 * @LastEditTime: 2021-10-25 19:45:05
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

const int N = 2e5 + 10;

int H, W, n, r, c, a;

struct node {
    int r, c, a;
    bool operator<(const node& rhs) const { return a < rhs.a;};
}p[N], pp[N];

int main() {
    scanf("%d %d %d", &H, &W, &n);
    map<int, map<int, int>> st;
    vector<int> h(H + 1, -1);
    vector<int> w(W + 1, -1);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d %d", &r, &c, &a);
        p[i] = (node){r, c, a};
        pp[i] = p[i];
    }
    sort(p + 1, p + n + 1);
    queue<node> q;
    for (int i = n, j; i > 0; i = j) {
        // cout << p[i].r << " " << p[i].c << " " << p[i].a << endl;
        while (!q.empty()) {
            node u = q.front();
            q.pop();
            h[u.r] = max(h[u.r], st[u.r][u.c]);
            w[u.c] = max(w[u.c], st[u.r][u.c]);
        }
        j = i;
        do {
            st[p[j].r][p[j].c] = 1 + max(h[p[j].r], w[p[j].c]);
            q.push(p[j]);
            j--;
        } while (j > 0 && p[j].a == p[i].a);
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d\n", st[pp[i].r][pp[i].c]);
    }
    return 0;
}