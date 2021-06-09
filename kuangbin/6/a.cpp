#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int fa[30];

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
	int n, m, l, ans;
	char x[10], y[10], ch;
	while(~scanf("%d", &n) && n){
		ans = 0;
		for(int i = 0; i<30; i++) fa[i] = i;
		priority_queue<node> q;
		for(int i = 0; i<n-1; i++){
			scanf("%s %d", x, &m);
			while(m--){
				scanf("%s %d", y, &l);
				temp.x = x[0] - 'A';
				temp.y = y[0] - 'A';
				temp.len = l;
				q.push(temp);
			}
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