#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 1005;
int fa[MAXN], rt[MAXN];
int Find(int x){
	int i = x;
	while(i != fa[i])
		i = fa[i];
	fa[x] = i;
	return i;
}

void Union(int x, int y){
	int fx = Find(x), fy = Find(y);
	if(fx != fy)
		fa[fx] = fy;
	return;
} 


int main(){
	int t, n, m, u, v, ans;
	scanf("%d", &t);
	while(t--){
		ans = 0;
		memset(rt, 0, sizeof(rt));
		scanf("%d %d", &n, &m);
		for(int i = 1; i<=n; i++) fa[i] = i;
		for(int i = 1; i<=m; i++){
			scanf("%d %d", &u, &v);
			Union(u, v);
		}
		for(int i = 1; i<=n; i++)
			rt[Find(i)] = 1;
		for(int i = 1; i<=n; i++)
			if(rt[i])
				ans++;
		printf("%d\n", ans);	
	}


	return 0;
}