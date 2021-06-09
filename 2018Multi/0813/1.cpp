#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>
#include <iostream>
using namespace std;
using LL = long long;
typedef pair<int, int> pii;
const int N = 1e5 + 10;

struct node {
	int s, id, c, f;
	bool operator<(const node &rhs) const {
		return s > rhs.s;
	}
};

int head[N], nxt[N << 2], val[N << 2], pnt[N << 2], dis[N];
int cnt = 1, n;
void add(int x, int y, int v){
	val[cnt] = v;
	pnt[cnt] = y;
	nxt[cnt] = head[x];
	head[x] = cnt++;
	return;
}

int dijk(int s, int t){
	memset(dis, 0x3f, sizeof(dis));
	dis[s] = 0;
	priority_queue<node> q;
	for(int i = head[s]; ~i; i = nxt[i]) {
		int j = pnt[i];
		dis[j] = 1;
		q.push({1, j, val[i], 1});
	}
	while(!q.empty()){
		node temp = q.top();
		q.pop();
		if(temp.s < dis[temp.id]) continue;
		//cout << temp.s << " " << temp.id << " " << temp.c << " " << temp.f << "FDDD" << endl;
		for(int i = head[temp.id]; ~i; i = nxt[i]){
			int j = pnt[i];
			int p = dis[temp.id];
			if(temp.c == val[i]) 
				p += (0 == temp.f);
			else
				p += 1;
			if(dis[j] > p){
				dis[j] = p;
				if(temp.c == val[i])
					q.push({dis[j], j, val[i], 1});
				else
					q.push({dis[j], j, val[i], 1});
			}
		}
	}
	return dis[t];
}

int main(){
	int t, m, a, b, c;
	while(~scanf("%d%d", &n, &m)){
		cnt = 0;
		memset(nxt, 0, sizeof(nxt));
		memset(pnt, 0 ,sizeof(pnt));
		memset(val, 0, sizeof(val));
		memset(head, -1, sizeof(head));
		while(m--){
			scanf("%d%d%d", &a, &b, &c);
			add(a, b, c);
			add(b, a, c);
		}
		if(dijk(1, n) == 0x3f3f3f3f) 
			puts("-1");
		else
			printf("%d\n", dis[n]);
	}
	return 0;
}

