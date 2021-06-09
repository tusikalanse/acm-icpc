#include <bits/stdc++.h>
#define pii pair<int,int>
#define d first
#define m second
#define LL long long
#define MAXN 2000000
#define MAXP 100
using namespace std;

int T;
LL mod[4];
LL a[4];

LL exgcd(LL a, LL b, LL& x, LL& y) {
    if (a == 0 && b == 0)
        return -1;
    if (b == 0) {
        x = 1; y = 0; return a;
    }
    LL d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

LL CRT(LL a[], LL m[]) {
    int n = 3;
    LL M = 1;
    LL ans = 0;
    for (int i = 1; i <= n; ++i)
        M *= m[i];
    for (int i = 1; i <= n; ++i) {
        LL x, y;
        LL Mi = M / m[i];
        exgcd(Mi, m[i], x, y);
        ans = (ans + Mi * x % M * a[i] % M) % M;
    }
    ans = (ans + M) % M;
    return ans;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%lld %lld %lld", &mod[1], &mod[2], &mod[3]);
        scanf("%lld %lld %lld", &a[1], &a[2], &a[3]);
        LL x = CRT(a, mod);
        cout << x << endl;
    }
}