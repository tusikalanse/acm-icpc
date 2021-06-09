#include <bits/stdc++.h>
using namespace std;

int T, n, a, cnt, nn;

int notprime[33005], prm[33005], ind;

void init() {
    memset(notprime, 0, sizeof(notprime));
    for (int i = 2; i <= 33000; ++i) {
        if (notprime[i] == 0) {
            prm[++ind] = i;
            for (int j = i; j <= 33000; j += i) {
                notprime[j] = 1;
            }
        }        
    }
}

bool canbeodd(int x) {
    if ((x & (x - 1)) == 0) return false;
    if (x % 2 == 0) return true;
    for (int i = 1; prm[i] * prm[i] <= x; ++i) {
        if (x % prm[i] == 0) return true;
    }
    return false;
}

int main() {
    init();
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        nn = n;
        cnt = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a);
            if (a == 1) {
                nn--;
            }
            else {
                cnt += canbeodd(a);
            }
        }
        nn -= cnt;
        if (cnt == 0) {
            if (nn % 2 == 1) {
                puts("W");
            }
            else {
                puts("L");
            }
        }
        else if (nn % 2 == 1) {
            if (cnt % 2 == 1) {
                puts("W");
            }
            else {
                puts("L");
            }
        }
        else {
            if (cnt % 2 == 0) {
                puts("W");
            }
            else {
                puts("L");
            }
        }
    }
    return 0;
}