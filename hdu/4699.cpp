#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+10;
int sum[MAXN], mmax[MAXN], bef[MAXN], aft[MAXN];

int main() {
    int n, t, p = 0, p2 = 0;
    char com[10];
    while(cin >> n) {
        p = p2 = 0;
        while(n--) {
            scanf("%s", com);
            if(com[0] == 'I') {
                scanf("%d", &t);
                bef[p++] = t;
                if(p > 1) {
                    sum[p-1] = sum[p-2] + t;
                    mmax[p-1] = max(mmax[p-2], sum[p-1]);
                }
                else {
                    sum[p-1] = t;
                    mmax[p-1] = t;
                }
            }
            else if(com[0] == 'D')
                p--;
            else if(com[0] == 'L') {
                if(p) {
                    aft[p2++] = bef[--p];
                }
            }
            else if(com[0] == 'R') {
                if(p2) {
                    t = bef[p++] = aft[p2-1];
                    p2--;
                    if(p > 1) {
                        sum[p-1] = sum[p-2] + t;
                        mmax[p-1] = max(mmax[p-2], sum[p-1]);
                    }
                    else {
                        sum[p-1] = t;
                        mmax[p-1] = t;
                    }
                }
            }
            else {
                scanf("%d", &t);
                printf("%d\n", mmax[t-1]);
            }
        }
    }
    return 0;
}
