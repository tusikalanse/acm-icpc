#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define mst(a, b) memset(a, b, sizeof(a))
using namespace std;
const int MAXN = 10000;

int vis[MAXN], head[MAXN], nxt[MAXN], pnt[MAXN], val[MAXN], dis[MAXN], tm[MAXN];
int cnt, flag;

void init(){
	flag = 0;
	cnt = 0;
	mst(vis, 0);
	mst(head, -1);
	mst(nxt, 0);
	mst(pnt, 0);
	mst(val, 0);
	mst(dis, 0x3f);
	mst(tm, 0);
}


void add(int u, int v, int value){
	pnt[cnt] = v;
	nxt[cnt] = head[u];
	val[cnt] = value;
	head[u] = cnt++;
}



int main(){
	int f, n, w, m, s, e, t;
	scanf("%d", &f);
	while(f--){
		init();
		scanf("%d %d %d", &n, &m, &w);
		while(m--){
			scanf("%d %d %d", &s, &e, &t);
			add(s, e, t);
			add(e, s, t);
		}
		while(w--){
			scanf("%d %d %d", &s, &e, &t);
			add(s, e, -t);
		}
		vis[1] = 1;
		dis[1] = 0;
		queue<int> q;
		q.push(1);
		while(!q.empty()){
			int u = q.front();
			q.pop();
			vis[u] = 0;
			for(int i = head[u]; ~i; i = nxt[i]){
				int j = pnt[i];
				if(dis[j] > dis[u] + val[i]){
					dis[j] = dis[u] + val[i];
					if(!vis[j]){
						vis[j] = 1;
						q.push(j);
					}
					tm[j]++;
					if(tm[j] > n){
						flag = 1;
						goto out;
					}
				}
			}
		}
		out:;
		puts(flag?"YES":"NO");
	}
	return 0;
}