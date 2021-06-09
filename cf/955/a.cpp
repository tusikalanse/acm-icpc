#include <bits/stdc++.h>
using namespace std;

int main () {
    int hh, mm, h, d, c, n;
    scanf("%d %d %d %d %d %d", &hh, &mm, &h, &d, &c, &n);
    double ans1, ans2 = 0;
    ans1 = (h/n + (h%n > 0)) * c;
    if(hh >= 20) {
        ans1 *= 0.8;
        printf("%.4f\n", ans1);
        return 0;
    }
    else {
        int del = (60 - mm) + 60 * (19 - hh);
        h += d * del;
        ans2 = (h/n + (h%n>0)) * c * 0.8;
        printf("%.4f\n", min(ans1, ans2));
        return 0;
    }



    return 0;
}
