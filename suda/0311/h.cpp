#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int fa[1005], rt[1005];

int Find(int x){
	int i = x;
	while(fa[i] != i){
		i = fa[i];
	}
	fa[x] = i;
	return i;
}

void Unite(int x, int y){
	int fx = Find(x), fy = Find(y);
	if(fx != fy)
		fa[fx] = fy;
}

int main(){
	int t, n, m, a, b, ans = 0;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &m);
		memset(rt, 0, sizeof(rt));
		ans = 0;
		for(int i = 1; i<=n; i++)
			fa[i] = i;
		for(int i = 1; i<=m; i++){
			scanf("%d %d", &a, &b);
			Unite(a, b);
		}
		for(int i = 1; i<=n; i++){
			rt[Find(i)] = 1;
		}
		for(int i = 1; i<=n; i++)
			if(rt[i])
				ans++;
		printf("%d\n", ans);
	}


	return 0;
}