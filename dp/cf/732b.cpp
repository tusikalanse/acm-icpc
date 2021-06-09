#include <bits/stdc++.h>
using namespace std;

int a[510], b[510];

int main() {
    int n, m, ans = 0;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    a[0] = b[0] = a[n+1] = m;
    for(int i = 1; i <= n; i++) {
        b[i] = a[i];
        if(a[i] + a[i-1] < m)
            b[i] = m - a[i-1];
        ans += b[i] - a[i];
        a[i] = b[i];
    }
    printf("%d\n", ans);
    for(int i = 1; i <= n; i++) 
        printf("%d%c", b[i], ((i == n) ? '\n' : ' '));
    return 0;
}
