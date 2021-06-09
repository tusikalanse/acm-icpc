#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int father[1005];
int root[1005];
int Find(int x){
	int i = x;
	while(father[i]!=i)
		i = father[i];
	father[x] = i;
	return i;
}

void unite(int x, int y){
	int fx = Find(x), fy = Find(y);
	if (fx != fy) father[fx] = fy;
}

int main(){
	int n, m, ans, x, y;
	while(scanf("%d", &n) && n && scanf("%d", &m)){
		ans = 0;
		for(int i = 1; i<=n; i++) father[i] = i;
		for(int i = 0; i<m; i++) {
			scanf("%d %d", &x, &y);
			unite(x, y);
		}
		memset(root, 0, sizeof(root));
		for(int i = 1; i<=n; i++) root[Find(i)] = 1;
		for(int i = 1; i<=n; i++) if(root[i]) ans++;
		printf("%d\n", ans-1);	
	}
	return 0;
}
