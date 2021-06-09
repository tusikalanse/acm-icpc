#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int fa[N][23];
int c[N], a[N], q, op, x, y, z;

int main () {
    scanf("%d %d %d", &q, &a[0], &c[0]);
    for (int i = 1; i <= q; ++i) {
        scanf("%d%d%d", &op, &x, &y);
        if (op == 1) {
            scanf("%d", &z);
            fa[i][0] = x;
            a[i] = y;
            c[i] = z;
            for (int j = 1; j < 22; ++j) {
                fa[i][j] = fa[fa[i][j - 1]][j - 1];
            }
        }
        else {
            long long cost = 0;
            int ans = 0;
            int p = x;
            for (int j = 21; ~j; --j) {
                if (a[fa[p][j]] != 0)
                    p = fa[p][j];
            }
            while (y && a[x] != 0) {
                // cout << "p, y, a[p] = " << p << " " << y << " "<< a[p] << endl;
                if (a[p] >= y) {
                    ans += y;
                    cost += 1LL * c[p] * y;
                    a[p] -= y;
                    y = 0;
                }
                else {
                    ans += a[p];
                    cost += 1LL * c[p] * a[p];
                    y -= a[p];
                    a[p] = 0;
                
                    p = x;
                    for (int j = 21; ~j; --j) {
                        if (a[fa[p][j]] != 0)
                            p = fa[p][j];
                    }
                }
                // cout << "ans, " << ans << endl;
            }
            printf("%d %lld\n", ans, cost);
            fflush(stdout);
        }

    }


    return 0;
}