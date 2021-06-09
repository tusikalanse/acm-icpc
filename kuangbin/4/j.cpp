#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN = 1e6 + 5;

int head[2][MAXN], val[2][MAXN], pnt[2][MAXN], nxt[2][MAXN], cnt1, cnt2, vis[MAXN], dis[MAXN];
void init(){
	cnt1 = cnt2 = 0;
	memset(head, -1, sizeof(head));
	memset(val, 0x3f, sizeof(val));
	memset(nxt, 0, sizeof(nxt));
	memset(pnt, 0, sizeof(pnt));
}

void add1(int x, int y, int v){
	nxt[0][cnt1] = head[0][x];
	val[0][cnt1] = v;
	pnt[0][cnt1] = y;
	head[0][x] = cnt1++;
}

void add2(int x, int y, int v){
	nxt[1][cnt2] = head[1][x];
	val[1][cnt2] = v;
	pnt[1][cnt2] = y;
	head[1][x] = cnt2++;
}

void spfa(int c){
	memset(vis, 0, sizeof(vis));
	memset(dis, 0x3f, sizeof(dis));
	vis[1] = 1;
	dis[1] = 0;
	queue<int> q;
	q.push(1);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for(int i = head[c][u]; ~i; i = nxt[c][i]){
			int j = pnt[c][i];
			if(dis[j] > dis[u] + val[c][i]){
				dis[j] = dis[u] + val[c][i];
				if(!vis[j]){
					vis[j] = 1;
					q.push(j);
				}
			}
		}
	}
}

int main(){
	int n, p, q, x, y, v;
	long long ans;
	scanf("%d", &n);
	while(n--){
		ans = 0;
		init();
		scanf("%d %d", &p, &q);
		while(q--){
			scanf("%d %d %d", &x, &y, &v);
			add1(x, y, v);
			add2(y, x, v);
		}
		spfa(0);
		for(int i = 1; i <= p; i++) ans += dis[i];
		spfa(1);
		for(int i = 1; i <= p; i++) ans += dis[i];
		printf("%lld\n", ans);
	}
	return 0;
}