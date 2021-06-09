#include <bits/stdc++.h>
using namespace std;
 
int T, n, a[22];

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i = n; ~i; --i)
            scanf("%d", &a[i]);
        if(n <= 1) {
            puts("Yes");
            continue;
        }
        if(n > 2) {
            puts("No");
            continue;
        }
        long long A = a[2], B = a[1], C = a[0];
        if(B * B - 4 * A * C < 0) 
            puts("Yes");
        else 
            puts("No");
    }
    return 0;
}