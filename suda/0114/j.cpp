#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int father[1002];
int root[1002];


int Find(int x){
	int i = x; 
	while(father[i] != i) i = father[i];
	father[x] = i;
	return i;
}


void unite(int x, int y){
	int fx = Find(x), fy = Find(y);
	if(fx != fy) father[fx] = fy;
}


int main(){
	int t, n, m, a, b, ans;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		ans = 0;
		for(int i = 1; i<=n; i++) father[i] = i;
		for(int i = 1; i<=m; i++) {
			scanf("%d %d", &a, &b);
			unite(a, b);
		}
		memset(root, 0, sizeof(root));
		for(int i = 1; i<=n; i++) root[Find(i)] = 1;
		for(int i = 1; i<=n; i++) if (root[i]) ans++;
		printf("%d\n", ans);
	}
	return 0;
}
