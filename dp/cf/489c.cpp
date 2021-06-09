#include <bits/stdc++.h>
using namespace std;

int mmin[105], mmax[105];

int main() {
    int m, s, s2;
    scanf("%d%d", &m, &s);
    s2 = s;
    if((s == 0 && m != 1) || s > 9*m)
        puts("-1 -1");
    else if(s == 0)
        puts("0 0 ");
    else {
        for(int i = m; i > 0; i--) {
            if(s >= 9) {
                mmax[i] = 9;
                s -= 9;
            }
            else {
                mmax[i] = s;
                s = 0;
            }
        }
        mmin[m] = 1;
        s2--;
        for(int i = 1; i < m; i++) {
            if(s2 >= 9) {
                mmin[i] = 9;
                s2 -= 9;
            }
            else {
                mmin[i] = s2;
                s2 = 0;
            }
        }
        if(s2)
            mmin[m] += s2;
        for(int i = m; i >= 1; i--)
            putchar('0' + mmin[i]);
        putchar(' ');
        for(int i = m; i >= 1; i--)
            putchar('0' + mmax[i]);
        puts("");


    }
    return 0;
}
