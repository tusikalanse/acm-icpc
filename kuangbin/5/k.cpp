#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int fa[505], vis[505], r[505];
int n, m;
struct node{
	int u, v, k;
}a[2005];

void init(int n){
	for(int i = 0; i<=n; i++){
		r[i] = 0;
		fa[i] = i;
	}
}

int Find(int x){
	if(x == fa[x]) return x;
	int t = fa[x];
	fa[x] = Find(fa[x]);
	r[x] = (r[x] + r[t]) % 3;
	return fa[x];
}

int main(){
	while(~scanf("%d %d", &n, &m)){
		char ch;
		for(int i = 1; i<=m; i++){
			scanf("%d", &a[i].u);
			while((ch = getchar()) == ' ');
			scanf("%d", &a[i].v);
			a[i].k = (ch == '=')? 0 :(ch == '<' ? 1 : 2);
		}
		memset(vis, -1, sizeof(vis));
		for(int i = 0; i<n; i++){
			init(n);
			for(int j = 1; j<=m; j++){
				if(a[j].u == i || a[j].v == i) continue;
				int fx = Find(a[j].u), fy = Find(a[j].v);
				if(fx == fy){
					if(a[j].k != (r[a[j].v] - r[a[j].u] + 3)%3) {
						vis[i] = j;
						break;
					}
				}
				else{
					fa[fy] = fx;
					r[fy] = (r[a[j].u] - r[a[j].v] + a[j].k + 3) % 3;
				}
			}
		}
		int cnt = 0, a1, a2 = 0;
		for(int i = 0; i<n; i++){
			if(vis[i] == -1){
				cnt++;
				a1 = i;
			}
			a2 = max(a2, vis[i]);
		}
		if(cnt == 0) puts("Impossible");
		else if(cnt > 1) puts("Can not determine");
		else printf("Player %d can be determined to be the judge after %d lines\n", a1, a2);
	}
	return 0;
}