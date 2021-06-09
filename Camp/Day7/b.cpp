#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 10;

int vis[N], match[N], tot, mid, ans;
vector<int> edge[N];
int cnt;

int dfs(int s) {
    for(int i = 0; i < edge[s].size(); ++i){
        int j = edge[s][i];
        if((s < mid) + (j < mid) != 1) continue;
        if(!vis[j]){
            vis[j] = 1;
            if(match[j] == -1 || dfs(match[j])){
                match[j] = s;
                return 1;
            }
        }
    }
    return 0;    
}

bool check() {
    memset(match, -1, sizeof(match));
    for(int i = 0; i < mid; ++i) {
        memset(vis, 0, sizeof(vis));
        if(!dfs(i))
            return false;
    }
    return true;
}

int main() {
    int m, n, x, y;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; ++i) {
    	scanf("%d%d", &x, &y);
    	edge[x].push_back(y);
        edge[y].push_back(x);
    }
    int l = 1, r = n / 2;
    while(l <= r) {
        mid = l + r >> 1;
        if(check()) {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    printf("%d\n", ans);
    return 0;
}