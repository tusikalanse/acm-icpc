#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int fa[110];

int Find(int x){
	return fa[x] == x? x: fa[x] = Find(fa[x]);
}

void Union(int x, int y){
	int fx = Find(x), fy = Find(y);
	if(fx != fy)
		fa[fx] = fy;
}

struct node{
	int x, y, len;
	bool operator < (const node &rhs)const{
		return len > rhs.len;
	}
}temp;

int main(){
	int n, m, l, ans, x, y;
	while(~scanf("%d", &n) && n && scanf("%d", &m)){
		ans = 0;
		for(int i = 0; i<110; i++) fa[i] = i;
		priority_queue<node> q;
		while(m--){
			scanf("%d %d %d", &x, &y, &l);
			temp.x = x;
			temp.y = y;
			temp.len = l;
			q.push(temp);
		}
		n--;
		while(n){
			node u = q.top();
			q.pop();
			if(Find(u.x) == Find(u.y))
				continue;
			Union(u.x, u.y);
			ans += u.len;
			n--;
		}
		while(!q.empty()) q.pop();
		printf("%d\n", ans);
	}
	return 0;
}