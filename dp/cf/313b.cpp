#include <bits/stdc++.h>
using namespace std;

int ans[1000005];
char s[1000005];

int main() {
    int n, l, r;
    scanf("%s", s);
    for(int i = 1; i < strlen(s); i++) {
        ans[i] = ans[i-1];
        if(s[i] == s[i-1])
            ans[i]++;
    }
    scanf("%d", &n);
    while(n--) {
        scanf("%d %d", &l, &r);
        l--;
        r--;
        printf("%d\n", ans[r] - ans[l]);
    }
    return 0;
}
