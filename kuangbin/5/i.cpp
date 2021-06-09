#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int fa[40010], east[40010], north[40010], ans[10010];
int a[40010], b[40010], l[40010];
char s[40010][3];


struct node{
	int id, x, y, t;
	bool operator < (const node &rhs) const{
		return t < rhs.t;
	}
}query[10010];

int Find(int x){
	if(x == fa[x])
		return x;
	int t = fa[x];
	fa[x] = Find(fa[x]);
	east[x] = east[x] + east[t];
	north[x] = north[x] + north[t];
	return fa[x];
}

void Union(int x, int y, int dis_e, int dis_n){
	int fx = Find(x), fy = Find(y);
	if(fx != fy){
		fa[fy] = fx;
		east[fy] = east[x] - east[y] + dis_e;
		north[fy] = north[x] - north[y] + dis_n;
	}
}

int main(){
	int n, m, k;
	scanf("%d %d", &n, &m);
	for(int i = 1; i<=n; i++){
		fa[i] = i;
		east[i] = north[i] = 0;
	}
	for(int i = 1; i<=m; i++)
		scanf("%d %d %d %s", &a[i], &b[i], &l[i], s[i]);
	scanf("%d", &k);
	for(int i = 1; i<=k; i++){
		scanf("%d %d %d", &query[i].x, &query[i].y, &query[i].t);
		query[i].id = i;
	}
	sort(query + 1, query + 1 + k);
	int pos = 1;
	for(int i = 1; i<=m; i++){
		if 	   (s[i][0] == 'E') Union(a[i], b[i], l[i], 0);
		else if(s[i][0] == 'W') Union(a[i], b[i], -l[i], 0);
		else if(s[i][0] == 'N') Union(a[i], b[i], 0, l[i]);
		else if(s[i][0] == 'S') Union(a[i], b[i], 0, -l[i]);
		while(query[pos].t == i && pos <= k){
			int fx = Find(query[pos].x), fy = Find(query[pos].y);
			if(fx != fy) ans[query[pos].id] = -1;
			else ans[query[pos].id] = abs(east[query[pos].x] - east[query[pos].y]) + abs(north[query[pos].x] - north[query[pos].y]);
				pos++;
		}
	}
	for(int i = 1; i<=k; i++)
		printf("%d\n", ans[i]);
	return 0;
}