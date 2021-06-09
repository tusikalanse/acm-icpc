#include <bits/stdc++.h>
using namespace std;


int main() {
    int d, k;
    cin >> d >> k;
    double tot = 0;
    int x = 100000, p, tmp;
    for(int i = 0; i < x; ++i) {
        tmp = 0;
        p = 0;
        while(p != d) {
            tmp++;
            int stp = 1 + rand() % k;
            if(p + stp <= d)
                p += stp;
            else {
                p = d - (stp - (d - p));
            }
        }
        tot += tmp;
    }
    cout << tot / x << endl;
    return 0;
}