#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int fa[110], u[5500], v[5500], w[5500], r[5500];
int Find(int x){return fa[x]==x?x:fa[x]=Find(fa[x]);}

bool cmp(int i, int j){ return w[i] < w[j];}
void Unite(int x, int y){
	int fx = Find(x), fy = Find(y);
	if(fx != fy) fa[fx] = fy;
}


int main(){
	int n, sum, line;
	while(~scanf("%d", &n) && n){
		line = sum = 0; 
		int m = n*(n-1)/2;
		memset(u, 0, sizeof(u));
		memset(v, 0, sizeof(v));
		memset(r, 0, sizeof(r));
		memset(w, 0, sizeof(w)); 
		memset(fa, 0, sizeof(fa));
		for(int i = 0; i< m; i++){
			scanf("%d %d %d", u+i, v+i, w+i);
		}
		for(int i = 0; i<n; i++) fa[i] = i;
		for(int j = 0; j<m; j++) r[j] = j;
		sort(r, r+m, cmp);
		for(int j = 0; j<m && line < n; j++){
			if(Find(u[r[j]]) != Find(v[r[j]]))
			{sum += w[r[j]]; Unite(u[r[j]], v[r[j]]); line++;}
		}
		printf("%d\n", sum);
	}
	return 0;
}
