#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int fa[30005];
int n, m, k, a, b, ans = 0, t;


int Find(int x){
	return x == fa[x] ? x :fa[x] = Find(fa[x]);
}

void Unite(int x, int y){
	int fx = Find(x), fy = Find(y);
	if(fx != fy)
		fa[fx] = fy;
}

int main(){
	while(~scanf("%d %d", &n, &m) && n){
		for(int i = 0; i<n; i++)
			fa[i] = i;
		ans = 0;
		while(m--){
			scanf("%d", &k);
			for(int i = 0; i<k; i++){
				scanf("%d", &a);
				if(i)
					Unite(a, b);
				b = a;
			}
		}
		t = Find(0);
		for(int i = 0; i<n; i++){
			if(Find(i) == t)
				ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}