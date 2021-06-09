#include <bits/stdc++.h>
using namespace std;

int T;
long long n, m, k;

int main() {
    scanf("%d", &T);
    while(T--) {    
        scanf("%lld%lld%lld", &n, &m, &k);
        printf("%lld\n", m + 1 + (k - 1) * (1 + m / (n - k + 1)));
    }
    return 0;
}
