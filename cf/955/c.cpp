#include <bits/stdc++.h>
using namespace std;

long long s[1000000], s1[10000], s2[10000];
int cnt = 0, cnt1 = 0, cnt2 = 0;

int main() {
    s[cnt++] = 1;
    for(int i = 3; i <= 64; i++) {
        for(int j = 2; j <= 1000000; j++) {
            long long p = 1, pre = 1;
            int flag = 0;
            while(--i) {
                p *= j;
                if(p/j != pre){
                    flag = 1;
                    break;
                }
                pre = p;
            }
            if(flag)
                break;
            s[cnt++] = p;
        }
    }
    sort(s, s + cnt);
    for(int i = 0; i < cnt; i++) {
        if(s[i] != s[i-1] || i == 0)
            s1[cnt1++] = s[i];
    }
    for(int i = 0; i < cnt1 && s1[i] <= 1e9; i++)
        s2[cnt2++] = s1[i];
    int q, l, r;
    scanf("%d", &q);
    while(q--) {
        scanf("%d %d", &l, &r);
        l--;
        int ans = upper_bound(s1, s1+cnt1, r) - upper_bound(s1, s1+cnt1, l);
        ans += upper_bound(s2, s2+cnt2, l) - upper_bound(s2, s2+cnt2, r);
        ans += (int)sqrt(r) - (int)sqrt(l);
        printf("%d\n", ans);
    }
    return 0;
}
