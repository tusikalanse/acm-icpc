#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MOD = 9901;
int cnt = 0, pf[100005], pfn[100005];
int qp(int a, int b) {
    int ans = 1;
    while(b) {
        if(b & 1)
            ans = 1LL * a * ans % MOD;
        a = 1LL * a * a % MOD;
        b >>= 1;
    }
    return ans % MOD;
}

int sum(int p, int c) {
    if(c == 0)
        return 1;
    if(c & 1)
       return (1 + qp(p, (c+1)/2))*sum(p, (c-1)/2)%MOD;
    else
        return (1 + qp(p, c/2))*sum(p, c/2-1)%MOD+qp(p,c)%MOD;
}

void Prime_factor_decomposition(int x) {
    for(int i = 2; i * i <= x; i++) {
        while(x % i == 0) {
            pf[cnt] = i;
            pfn[cnt]++;
            x /= i;
        }
        cnt++;
    }
    if(x != 1) {
        pf[cnt] = x;
        pfn[cnt]++;
        cnt++;
    }
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    int ans = 1;
    Prime_factor_decomposition(a);
    for(int i = 0; i < cnt; i++) 
        ans = 1LL * ans * sum(pf[i], b*pfn[i]) % MOD;
    printf("%d\n", ans);
    return 0;
}
