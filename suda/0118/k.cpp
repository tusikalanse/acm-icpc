#include <cstdio>
#include <algorithm>
#include <queue>
#include <bits/stdc++.h>
using namespace std;


int vis[1005];
int head[1005];
int nxt[1005], point[1005], val[1005];
int cnt;
void add(int u, int v){
	point[cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt++;	
}

struct pii{
	int dis;
	int s;
	bool operator < (const pii x)const{
		return dis > x.dis;
	}
	pii(int a, int b):dis(a), s(b){};
};
bool cmp(pii a, pii b){
	return a.dis > b.dis;
}

priority_queue<pii> a;
void add(int u, int v, int vl){
	point[cnt] = v;
	nxt[cnt] = head[u];
	val[cnt] = vl;
	head[u] = cnt++;	
}

int main(){
	int T, S, D, x, y, v;
	while(~scanf("%d %d %d", &T, &S, &D)){
		for(int i = 1; i<=T; i++){
			scanf("%d %d %d", &x, &y, &v);
			add(x, y, v);			
		}
		
		
		
	}
	
	
	return 0;
}
