/*
 * @Description: 
 * @Version: 2.0
 * @Autor: tusikalanse
 * @Date: 2021-08-14 19:48:48
 * @LastEditors: tusikalanse
 * @LastEditTime: 2021-08-14 20:49:42
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10; 

struct ball {
    int L, R;
    bool operator<(const ball &rhs) const {
        return R < rhs.R;
    }
}B[N];

bool cmp(const ball &a, const ball &b) {
    return a.L < b.L;
}

int T, n;

unordered_map<int, vector<ball>> bmap; 
int v[N];
multiset<ball> now;

inline int getnext(int i) {
    if (!now.empty()) return i + 1;
    return *upper_bound(v, v + n, i);
}

int main() {
    scanf("%d", &T);
    while (T--) {
        now.clear();
        bmap.clear();
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &B[i].L, &B[i].R);
            bmap[B[i].L].push_back(B[i]);
            v[i] = B[i].L;
        }
        sort(v, v + n);
        sort(B, B + n, cmp);
        int flag = true, cnt = 0;
        for (int i = v[0]; cnt < n && flag; i = getnext(i)) {
            for (ball& x: bmap[i])
                now.insert(x);
            auto x = now.begin();
            if (x->R < i) {
                flag = false;
                break;
            }
            else {
                now.erase(x);
                cnt++;
            }
        }
        puts(flag?"YES":"NO");
    }
    return 0;
}