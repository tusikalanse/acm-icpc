#include <bits/stdc++.h>
using namespace std;
const int N = 13;
using LL = long long;
LL ans;
int T, n, m, tot;
int x[N], y[N], k[N], t[N];
set<int> xx, yy;
int gcd(int a, int b) {return b ? gcd(b, a % b) : a;}
int lcm(int a, int b) {return a * b / gcd(a, b);}

bool judge(int xi, int yi) {
    for(int i = 1; i <= n; ++i) {
        if((abs(xi - x[i]) + abs(yi - y[i])) % k[i] != t[i])
            return false;
    }
    return true;
}

LL calc(int x1, int x2, int y1, int y2) {
    int cnt = 0;
    LL res = 0;
    for(int x = x1; x < x1 + tot; ++x) {
        for(int y = y1; y < y1 + tot; ++y) {
            cnt += judge(x, y);
        }
    }
    res += 1LL * cnt * ((x2 - x1) / tot) * ((y2 - y1) / tot);
    cnt = 0;
    int x3 = (x2 - x1) % tot;
    for(int x = x2 - x3; x < x2; ++x) {
        for(int y = y1; y < y1 + tot; ++y) {
            cnt += judge(x, y);
        }
    }
    res += 1LL * cnt * ((y2 - y1) / tot);
    int y3 = ((y2 - y1)) % tot;
    cnt = 0;
    for(int x = x1; x < x1 + tot; ++x) {
        for(int y = y2 - y3; y < y2; ++y)
            cnt += judge(x, y);
    }
    res += 1LL * cnt * ((x2 - x1) / tot);
    for(int x = x2 - x3; x < x2; ++x) {
        for(int y = y2 - y3; y < y2; ++y) {
            res += judge(x, y);
        }
    }
    return res;
}

LL calc_x(int x1, int x2) {
    int cnt = 0; LL res = 0;
    for(int x = x1; x < x1 + tot; ++x)
        cnt += judge(x, m);
    res += 1LL * cnt * ((x2 - x1) / tot);
    int x3 = (x2 - x1) % tot;
    for(int x = x2 - x3; x < x2; ++x) 
        res += judge(x, m);
    return res;
}

LL calc_y(int y1, int y2) {
    int cnt = 0; LL res = 0;
    for(int y = y1; y < y1 + tot; ++y)
        cnt += judge(m, y);
    res += 1LL * cnt * ((y2 - y1) / tot);
    int y3 = (y2 - y1) % tot;
    for(int y = y2 - y3; y < y2; ++y) 
        res += judge(m, y);
    return res;
 }

int main() {
    scanf("%d", &T);
    while(T--) {
        tot = 1; xx.clear(); yy.clear(); ans = 0;
        scanf("%d%d", &n, &m);
        xx.insert(0); xx.insert(m);
        yy.insert(0); yy.insert(m); 
        for(int i = 1; i <= n; ++i) {
            scanf("%d%d%d%d", &x[i], &y[i], &k[i], &t[i]);
            xx.insert(x[i]);
            yy.insert(y[i]);
            tot = lcm(tot, k[i]);
        }
        auto p = xx.begin(), q = xx.begin();
        ++q;
        auto i = yy.begin(), j = yy.begin();
        ++j;
        for(; q != xx.end(); ++p, ++q) {
            for(; j != yy.end(); ++i, ++j) {
                ans += calc(*p, *q, *i, *j);
            }
            i = yy.begin(), j = yy.begin();
            ++j;
        }
        p = xx.begin(); q = xx.begin(); ++q;
        for(; q != xx.end(); ++p, ++q)
            ans += calc_x(*p, *q);
        i = yy.begin(); j = yy.begin(); ++j;
        for(; j != yy.end(); ++i, ++j)
            ans += calc_y(*i, *j);
        if(judge(m, m)) ans++;
        printf("%lld\n", ans);
    }
    return 0;
}