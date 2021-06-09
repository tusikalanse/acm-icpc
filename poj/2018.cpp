#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <queue>
using namespace std;

double a[100010], b[100010];

int main() {
    int n, L;
    scanf("%d %d", &n, &L);
    for(int i = 1; i <= n; i++) {
        scanf("%lf", &a[i]);
    }
    double l = -1e6, r = 1e6, eps = 1e-6;
    while(r - l > eps) {
        double mid = (l + r) / 2;
        b[0] = 0;
        for(int i = 1; i <= n; i++)
            b[i] = b[i-1] + a[i] - mid;
        double ans = -1e8, mmin = 1e10;
        for(int i = L; i <= n; i++) {
            mmin = min(mmin, b[i-L]);
            ans = max(ans, b[i] - mmin);
        }
        if(ans >= 0) l = mid;
        else         r = mid;
    }
    printf("%d\n", static_cast<int>(r*1000));
    return 0;
}
