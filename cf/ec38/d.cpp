#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

int head[200006], nxt[200006],  pnt[200006], vis[200006], ans[200006]; 
long long val[200006], dis[200006], vvv[200006];
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
	memset(dis, 0x3f, sizeof(dis));
	dis[s] = vvv[s];
	priority_queue<pii, vector<pii>, cmp> q;
	q.push(make_pair(dis[s], s));
	while(!q.empty()){
		pii temp = q.top();
		q.pop();
		if(temp.first > dis[temp.second]) continue;
		for(int i = head[temp.second]; ~i; i = nxt[i]){
			int j = pnt[i];
			if(dis[j] > temp.first + 2*dis[i] + vvv[j]){
				dis[j] = temp.first + 2*dis[i] + vvv[j];
				q.push(make_pair(dis[j], j));
			}
		}
	}
	return dis[t];
}

int main(){
	int t, m, a, b, c;
	size = 1;
	memset(nxt, 0, sizeof(nxt));
	memset(pnt, 0 ,sizeof(pnt));
	memset(val, 0, sizeof(val));
	memset(head, -1, sizeof(head));
	memset(vis, 0, sizeof(vis));
	scanf("%d %d", &n, &m);
	while(m--){
		scanf("%d%d%d", &a, &b, &c);
		add(a, b, c);
		add(b, a, c);
	}
	for(int i = 1; i<=n; i++)
		scanf("%d", &vvv[i]);
	for(int i = 1; i<=n; i++)
		if(vis[i] == 0)
			dijk(i, n)
	return 0;
}

