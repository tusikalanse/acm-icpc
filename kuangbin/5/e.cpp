#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int fa[50010], offset[50010];
int n, k, ans = 0, typ, a, b;

void init(int n) {
    for(int i = 1; i <= n; ++i){
        fa[i] = i;
        offset[i] = 0;
    }
}

int Find(int x) {
    if(x == fa[x]) return x;
    int y = fa[x];
    fa[x] = Find(y);
    offset[x] = (offset[x] + offset[y]) % 3;
    return fa[x];
}

int Unite(int typ, int x, int y) {
    int fx = Find(x), fy = Find(y);
    if(fx == fy){
        if((offset[y] - offset[x] + 3) % 3 == typ - 1)
            return 0;
        return 1;
    }
    fa[fy] = fx;
    offset[fy] = (offset[x] - offset[y] + typ - 1 + 3) % 3;
    return 0;
}

int main(){
    scanf("%d %d", &n, &k);
    init(n);
    while(k--) {
        scanf("%d %d %d", &typ, &a, &b);
        if(a == b && typ == 2) ans++;
        else if(a > n || b > n) ans++;
        else ans += Unite(typ, a, b);
    }
    printf("%d\n", ans);
    return 0;
}