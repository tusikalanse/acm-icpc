#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 150005;

int pnt[MAXN], nxt[MAXN], head[MAXN], val[MAXN], vis[MAXN], dis[MAXN], cnt = 0;
int q[MAXN];
void add(int x, int y, int v){
	pnt[cnt] = y;
	nxt[cnt] = head[x];
	val[cnt] = v;
	head[x] = cnt++;
}


int main(){
	int n, m, x, y, v;
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	memset(head, -1, sizeof(head));
	memset(val, 0 ,sizeof(val));
	memset(pnt, 0, sizeof(pnt));
	memset(nxt, 0, sizeof(nxt));
	scanf("%d %d", &n, &m);
	while(m--){
		scanf("%d %d %d", &x, &y, &v);
		add(x, y, v);
	}
	dis[1] = 0;
	vis[1] = 1;
	int top = 0;
	q[top++] = 1;
	while(top){
		int u = q[--top];
		vis[u] = 0;
		for(int i = head[u]; ~i; i = nxt[i]){
			int j = pnt[i];
			if(dis[j] > dis[u] + val[i]){
				dis[j] = dis[u] + val[i];
				if(!vis[j]){
					vis[j] = 1;
					q[top++] = j;
				}
			}
		}
	}
	printf("%d\n", dis[n]);
	return 0;
}