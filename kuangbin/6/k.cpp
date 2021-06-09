#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int fa[110], mark[110], t, n, m, now;
struct node
{
	int x, y, l, id;
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

int kruskal(int ignore, priority_queue<node> q){
	int ans = 0;
	for(int i = 1; i<=n; i++)
		fa[i] = i;
	int cnt = n-1;
	while(cnt && !q.empty()){
		node u = q.top();
		q.pop();
		if(Find(u.x) == Find(u.y) || u.id == ignore)
			continue;
		if(ignore == -1){
			mark[now++] = u.id;
		}
		Union(u.x, u.y);
		ans += u.l;
		cnt--;
	}
	if(cnt) return -1;
	return ans;
}

int main(){
	scanf("%d", &t);
	while(t--){
		priority_queue<node> q;
		now = 0;
		scanf("%d %d", &n, &m);
		for(int i = 0; i<m; i++){
			scanf("%d %d %d", &temp.x, &temp.y, &temp.l);
			temp.id = i;
			q.push(temp);
		}
		int flag = 1, ans = 0;
		ans = kruskal(-1, q);

		for(int i = 0; i<now; i++){
			if(ans == kruskal(mark[i], q)){
				flag = 0;
				break;
			}
		}
		if(flag)
			printf("%d\n", ans);
		else
			puts("Not Unique!");
	}
	return 0;
}