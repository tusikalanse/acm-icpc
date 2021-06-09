#include <bits/stdc++.h>
using namespace std;

int a[105];

int main() {
    int ans = 0, n, mmax = 0, temp = 0; 
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
            if(a[i]) {
                ans++;
                temp--;
                temp = max(0, temp);
            }
            else {
                temp++;
                mmax = max(mmax, temp);
            }
    }
    printf("%d\n", ans + ((mmax==0)?-1:mmax));
    return 0;
}
