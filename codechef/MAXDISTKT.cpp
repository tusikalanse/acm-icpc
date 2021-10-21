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

int T, n;

struct node2 {
    int val, id;
    bool operator<(const node2 &rhs) const {
        return id < rhs.id;
    }
}a[N];

struct node {
    int val, id;
    bool operator<(const node &rhs) const {
        return val < rhs.val;
    }
}b[N];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &b[i].val);
            b[i].id = i;
        }
        sort(b + 1, b + n + 1);
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (b[i].val > cnt) {
                a[i].val = b[i].val + cnt;
                cnt++;
            }
            else {
                a[i].val = b[i].val;
            }
            a[i].id = b[i].id;
        }
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; ++i) {
            printf("%d%c", a[i].val, " \n"[i == n]);
        }
    }
    return 0;
}