#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int fa[105], mp[105][105], n, q, x, y, rt[105];

int Find(int x){
	return x == fa[x]? x: fa[x] = Find(fa[x]);
}

void Union(int x, int y){
	int fx = Find(x), fy = Find(y);
	if(fx != fy)
		fa[fx] = fy;
}

struct node
{
	int x, y, len;
	bool operator < (const node &rhs) const{
		return len > rhs.len;
	}
}temp;

int main(){
	scanf("%d", &n);
	for(int i = 1; i<=n; i++)
		fa[i] = i;
	for(int i = 1; i<=n; i++)
		for(int j = 1; j<=n; j++)
			scanf("%d", &mp[i][j]);
	scanf("%d", &q);
	while(q--){
		scanf("%d %d", &x, &y);
		Union(x, y);
	}
	memset(rt, 0, sizeof(rt));
	for(int i = 1; i<=n; i++)
		rt[Find(i)] = 1;
	int ans = 0, cnt = 0;
	for(int i = 1; i<=n; i++)
		if(rt[i])
			cnt++;
	cnt--;
	priority_queue<node> q;
	for(int i = 1; i<n; i++)
		for(int j = i+1; j<=n; j++){
			temp.x = i;
			temp.y = j;
			temp.len = mp[i][j];
			q.push(temp);
		}
	while(cnt){
		node u = q.top();
		q.pop();
		if(Find(u.x) == Find(u.y))
			continue;
		Union(u.x, u.y);
		ans += u.len;
		cnt--;
	}
	printf("%d\n", ans);
	return 0;
}