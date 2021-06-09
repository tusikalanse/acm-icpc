#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 100010;
 
LL sum[N];
int rt, n, a, b, c;
int nxt[N << 1], head[N], pnt[N << 1], cnt;
int pos[N], dep[N];
vector<LL> res;
void add(int x, int y) {
    nxt[cnt] = head[x];
    pnt[cnt] = y;
    head[x] = cnt++;
}

void dfs(int rt, int fa, int depth) {
    dep[rt] = depth;
    for(int i = head[rt]; ~i; i = nxt[i]) {
        int j = pnt[i];
        if(fa != j) {
        	dfs(j, rt, depth + 1);
        }
    }
    if(pos[rt])
	    res.push_back(depth);
}
 
int main() {
    scanf("%d", &n);
    memset(head, -1, sizeof(head));
    for(int i = 1; i <= n; ++i)
    	scanf("%d", &pos[i]);
    for(int i = 1; i < n; ++i) {
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    dfs(1, 0, 0);
    sort(res.begin(), res.end());
    reverse(res.begin(), res.end());
    LL ans = 0;
 	for(int i = 0; i < res.size(); ++i)
 		ans = max(ans, res[i] + i);
    printf("%lld\n", ans);
    return 0;
}