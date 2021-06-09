#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
const int MAXN = 10010;
int fa[MAXN], pw[MAXN];
int ans[MAXN << 3];
struct node
{
	int x, y, flag;
}road[MAXN << 1], query[MAXN << 3];
map<int, bool> vis;

int Find(int x){
	return x == fa[x]? x: Find(fa[x]);
}

void Union(int x, int y){
	int fx = Find(x), fy = Find(y);
	if(fx != fy){
		if(pw[fx] > pw[fy] || (pw[fx] == pw[fy] && fx < fy))
			fa[fy] = fx;
		else
			fa[fx] = fy;
	}
}

int main(){
	int n, m, cnt, q;
	char s[10];
	bool first = 0;
	while(~scanf("%d", &n)){
		if(first) puts("");
		vis.clear();
		first = 1;
		for(int i = 0; i<n; i++){
			fa[i] = i;
			scanf("%d", &pw[i]);
		}
		scanf("%d", &m);
		for(int i = 0; i<m; i++){
			scanf("%d %d", &road[i].x, &road[i].y);
			if(road[i].x > road[i].y)
				swap(road[i].x, road[i].y);
		}
		scanf("%d", &q);
		for(int i = 0; i<q; i++){
			scanf("%s", s);
			if(s[0] == 'd'){
				scanf("%d %d", &query[i].x, &query[i].y);
				query[i].flag = 1;
				if(query[i].x > query[i].y)
					swap(query[i].x, query[i].y);
				vis[query[i].x * MAXN + query[i].y] = 1;
			}
			else{
				scanf("%d", &query[i].x);
				query[i].flag = 0;
			}
		}
		for(int i = 0; i<m; i++){
			if(!vis[road[i].x * MAXN + road[i].y])
				Union(road[i].x, road[i].y);
		}
		for(int i = q-1; i>=0; i--){
			if(query[i].flag) Union(query[i].x, query[i].y);
			else{
				int fx = Find(query[i].x);
				if(pw[fx] > pw[query[i].x]) ans[i] = fx;
				else ans[i] = -1;
			}
		}
		for(int i = 0; i<q; i++){
			if(!query[i].flag)
				printf("%d\n", ans[i]);
		}
	}
	return 0;
}