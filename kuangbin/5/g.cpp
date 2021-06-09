#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int fa[10010];

int Find(int x){
	if(fa[x] == -1) return x;
	fa[x] = Find(fa[x]);
	return fa[x];
}

struct node{
	int v, d;
}products[10010];

bool cmp(node a, node b){
	return a.v > b.v;
}

int main(){
	int n, ans;
	while(~scanf("%d", &n)){
		for(int i = 0; i<n; i++){
			scanf("%d %d", &products[i].v, &products[i].d);
		}
		memset(fa, -1, sizeof(fa));
		sort(products, products + n, cmp);
		ans = 0;
		for(int i = 0; i<n; i++){
			int t = Find(products[i].d);
			if(t > 0){
				ans += products[i].v;
				fa[t] = t - 1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}