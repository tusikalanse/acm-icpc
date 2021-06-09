#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
#include <map>
using namespace std;

int c[10010], d[10010];

int main() {
    map<pair<int, int>, bool> vis;
    int n, p, h, r, a, b;
    scanf("%d%d%d%d", &n, &p, &h, &r);
    for(int i = 1; i <= r; i++) {
        scanf("%d%d", &a, &b);
        if(a > b)
            a ^= b ^= a ^= b;
        if(vis[make_pair(a, b)]) 
            continue;
        d[a+1]--;
        d[b]++;
        vis[make_pair(a, b)] = 1;
    }
    for(int i = 1; i <= n; i++) {
        c[i] = c[i-1] + d[i];
        printf("%d\n", h+c[i]);
    }
    return 0;
}
