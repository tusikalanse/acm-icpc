#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

int T, n, a[N], K, sum[N], cas, mx;
multiset<int> s;

bool check(int vol) {
    static multiset<int> s;
    s = ::s;
    int tot = 0, tmp;
    while(!s.empty()) {
        tmp = 0;
        while(tmp < vol) {
            auto p = s.upper_bound(vol - tmp);
            if(p == s.begin()) break;
            --p;
            tmp += *p;
            s.erase(p);
        }
        if(++tot > K)
            return false;
    }
    return true;
}

int main() {
    scanf("%d", &T);
    while(T--) {
        s.clear();
        mx = -1e9;
        scanf("%d%d", &n, &K);
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            s.insert(a[i]);
            sum[i] = sum[i - 1] + a[i];
            mx = max(mx, a[i]);
        }
        int l = max(mx, 1 + (sum[n] - 1) / K), r = sum[n], ans;
        for(int i = l; i <= r; ++i) {
            if(check(i)) {
                ans = i;
                break;
            }
        }
        printf("Case #%d: %d\n", ++cas, ans);
    }
    return 0;
}


for (int i = 1; i <= n; ++i)