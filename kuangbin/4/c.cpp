#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

int head[1006], nxt[1000006], val[1000006], pnt[1000006], dis[1006];
int size = 1, n;
void add(int x, int y, int v){
	val[size] = v;
	pnt[size] = y;
	nxt[size] = head[x];
	head[x] = size++;
	return;
}

struct cmp{
	bool operator()(pii a, pii b){
		return a.first < b.first;
	}
};

int dijk(int s, int t){
	memset(dis, 0, sizeof(dis));
	dis[s] = 0x3f3f3f3f;
	priority_queue<pii, vector<pii>, cmp> q;
	q.push(make_pair(dis[s], s));
	while(!q.empty()){
		pii temp = q.top();
		q.pop();
		if(temp.first < dis[temp.second]) continue;
		for(int i = head[temp.second]; ~i; i = nxt[i]){
			int j = pnt[i];
			if(dis[j] < min(temp.first, val[i])){
				dis[j] = min(temp.first, val[i]);
				q.push(make_pair(dis[j], j));
			}
		}
	}
	return dis[t];
}

int main(){
	int t, m, a, b, c;
	scanf("%d", &t);
	for(int _ = 1; _ <= t; _++){
		size = 1;
		memset(nxt, 0, sizeof(nxt));
		memset(pnt, 0 ,sizeof(pnt));
		memset(val, 0, sizeof(val));
		memset(head, -1, sizeof(head));
		scanf("%d %d", &n, &m);
		while(m--){
			scanf("%d%d%d", &a, &b, &c);
			add(a, b, c);
			add(b, a, c);
		}
		printf("Scenario #%d:\n%d\n\n", _, dijk(1, n));
	}
	return 0;
}

