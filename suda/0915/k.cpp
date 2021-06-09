#include <bits/stdc++.h>
using namespace std;


const int mod = 1e9 + 7;
const int MAXN = 10010;
long long dp[MAXN], w[MAXN], cnt[MAXN];
int num, cap = 10001, m;

void ZeroOnePack(long long cost) {
    for(long long v = cap; v >= cost; v--) {
        dp[v] = (dp[v] + dp[v-cost]) % mod;
    }
    return;
}

void CompletePack(long long cost) {
    for(long long v = cost; v <= cap; v++) {
        dp[v] = (dp[v] + dp[v-cost]) % mod;
    }
    return;
}

void MultiplePack(long long cost, long long amount) {
    if(cost * amount >= cap) {
        CompletePack(cost);
        return;
    }
    long long k = 1;
    while(k < amount) {
        ZeroOnePack(cost * k);
        amount -= k;
        k *= 2;
    }
    ZeroOnePack(cost * amount);
    return;
}

long long qp(long long a, long long n) {
    long long res = 1;
    while(n) {
        if(n & 1)
            res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &num, &m);
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(long long i = 1; i <= num; i++) {
            scanf("%lld %lld", &w[i], &cnt[i]);
            cnt[i] = qp(2, cnt[i]) - 1;
        }
        for(long long i = 1; i <= num; i++) {
            MultiplePack(w[i], cnt[i]);
        }
        while(m--) {
            int q;
            scanf("%d", &q);
            printf("%lld\n", dp[q]);
        }
    }
    return 0;
}
