#include <bits/stdc++.h>
using namespace std;

int T, n;
int a[2010];
int odd, even;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main () {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        odd = even = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            if (a[i] % 2 == 0)
                even++;
            else 
                odd++;
        }
        int ans = even * odd + even * (even - 1) / 2;
        for (int i = 1; i <= n; ++i) {
            if (a[i] % 2 == 0) continue;
            for (int j = i + 1; j <= n; ++j) {
                if (a[j] % 2 == 0) continue;
                if (gcd(a[i], a[j]) != 1) 
                    ans++;
            }
        }
        printf("%d\n", ans);
    }


    return 0;
}