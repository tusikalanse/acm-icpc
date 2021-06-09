#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
using namespace std;
const int MAXN = 755;

int mp[MAXN][MAXN], fa[MAXN], ans[MAXN][2], cnt = 0, x[MAXN], y[MAXN];

struct node
{
	int x, y, l;
	bool operator < (const node &rhs) const{
		return l > rhs.l;
	}
}temp;

int Find(int x){
	return x == fa[x]? x: fa[x] = Find(fa[x]);
}

void Union(int x, int y){
	int fx = Find(x), fy = Find(y);
	if(fx != fy) 
		fa[fx] = fy;
}

int n, m, a, b;

int main(){
	scanf("%d", &n);
	priority_queue<node> q;
	for(int i = 1; i<=n; i++){
		fa[i] = i;
		mp[i][i] = 0;
		scanf("%d %d", &x[i], &y[i]);
		for(int j = 1; j<i; j++){
			mp[i][j] = mp[j][i] = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) *(y[i] - y[j]);
			temp.x = i;
			temp.y = j;
			temp.l = mp[i][j];
			q.push(temp);
		}
	}
	scanf("%d", &m);
	for(int i = 1; i<=m; i++){
		scanf("%d %d", &a, &b);
		Union(a, b);
	}
	set<int> rt;
	for(int i = 1; i<=n; i++)
		rt.insert(Find(i));
	n = (int)rt.size() - 1;
	while(n){
		node u = q.top();
		q.pop();
		if(Find(u.x) == Find(u.y))
			continue;
		Union(u.x, u.y);
		n--;
		ans[cnt][0] = u.x;
		ans[cnt][1] = u.y;
		cnt++;
	}
	for(int i = 0; i<cnt; i++){
		printf("%d %d\n", ans[i][0], ans[i][1]);
	}
	return 0;
}