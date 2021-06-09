#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int dp[MAXN], w[MAXN], v[MAXN];
int num, cap;


void ZeroOnePack(int cost, int weight) {
    for(int v = cap; v >= cost; v--) {
        dp[v] = max(dp[v], dp[v-cost] + weight);
    }
    return;
}

void CompletePack(int cost, int weight) {
    for(int v = cost; v <= cap; v++) {
        dp[v] = max(dp[v], dp[v-cost] + weight);
    }
    return;
}

void MultiplePack(int cost, int weight, int amount) {
    if(cost * amount >= cap) {
        CompletePack(cost, weight);
        return;
    }
    int k = 1;
    while(k < amount) {
        ZeroOnePack(cost * k, weight * k);
        amount -= k;
        k *= 2;
    }
    ZeroOnePack(cost * amount, weight * amount);
    return;
}

int main() {
    scanf("%d %d", &num, &cap);
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= num; i++) {
        scanf("%d", &w[i]);
    }
    for(int i = 1; i <= num; i++) {
        scanf("%d", &v[i]);
    }
    for(int i = 1; i <= num; i++) {
        ZeroOnePack(w[i], v[i]);
    }
    int ans = 0;
    for(int i = 1; i <= cap; i++) {
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
    return 0;
}
