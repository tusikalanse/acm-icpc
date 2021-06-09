#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int MAXN = 55;

char pic[MAXN][MAXN];
int vis[MAXN][MAXN], mp[110][110], pos[MAXN][MAXN], n, m, t, cnt, dis[110];
struct node
{
	int x, y, s;
}temp;
int dir[4][2] = {0, -1, 0, 1, 1, 0, -1 ,0};

int bfs(int x, int y){
	memset(vis, 0, sizeof(vis));
	queue<node> q;
	temp.x = x;
	temp.y = y;
	temp.s = 0;
	vis[x][y] = 1;
	q.push(temp);
	while(!q.empty()){
		node u = q.front();
		q.pop();
		if(pic[u.x][u.y] == 'A' || pic[u.x][u.y] == 'S'){
			mp[pos[u.x][u.y]][pos[x][y]] = mp[pos[x][y]][pos[u.x][u.y]] = u.s;
		}
		for(int i = 0; i<4; i++){
			int fx = u.x + dir[i][0], fy = u.y + dir[i][1];
			if(fx >= 0 && fx < m && fy >=0 && fy < n && pic[fx][fy] != '#' && !vis[fx][fy]){
				vis[fx][fy] = 1;
				temp.x = fx;
				temp.y = fy;
				temp.s = u.s + 1;
				q.push(temp);
			}
		}
	}
}

int Prim(){
	int res = 0;
	int min_node, min_egde, now = 0;
	memset(dis, 0x3f, sizeof(dis));
	for(int i = 1; i<cnt; i++){
		dis[now] = 0;
		min_egde = 0x3f3f3f3f;
		for(int j = 0; j<cnt; j++){
			if(j != now && dis[j]){
				dis[j] = min(dis[j], mp[now][j]);
				if(dis[j] < min_egde){
					min_egde = dis[j];
					min_node = j;
				}
			}
		}
		res += min_egde;
		now = min_node;
	}
	return res;
}

int main(){
	scanf("%d", &t);
	char ch;
	while(t--){
		cnt = 0;
		scanf("%d %d", &n, &m);
		memset(pos, -1, sizeof(pos));
		while((ch = getchar()) != '\n');
		for(int i = 0; i<m; i++){
			for(int j = 0; j<n; j++){
				pic[i][j] = getchar();
				if(pic[i][j] == 'A' || pic[i][j] == 'S'){
					pos[i][j] = cnt++;
				}
			}
			while((ch = getchar()) != '\n');
		}
		for(int i = 0; i<m; i++){
			for(int j = 0; j<n; j++)
				if(i == j) mp[i][j] = 0;
				else	   mp[i][j] = 0x3f3f3f3f; 
		}
		for(int i = 0; i<m; i++){
			for(int j = 0; j<n; j++){
				if(pic[i][j] == 'A' || pic[i][j] == 'S'){
					bfs(i, j);
				}
			}
		}
		printf("%d\n", Prim());
	}
	return 0;
}
