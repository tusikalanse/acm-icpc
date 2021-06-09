#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;

int fa[505];
double x[505], y[505];

struct node{
	int x, y;
	double l;
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

int main(){
	int n, s, p;
	scanf("%d", &n);
	while(n--){
		scanf("%d %d", &s, &p);
		double ans = 0;
		priority_queue<node> q;
		for(int i = 1; i<=p; i++){
			fa[i] = i;
			scanf("%lf %lf", &x[i], &y[i]);
			for(int j = 1; j<i; j++){
				temp.x = i;
				temp.y = j;
				temp.l = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
				q.push(temp);
			}
		}
		p -= s;
		while(p){
			node u = q.top();
			q.pop();
			if(Find(u.x) == Find(u.y))
				continue;
			Union(u.x, u.y);
			p--;
			if(!p)
				ans = u.l;
		}
		printf("%.2lf\n", ans);
	}
	return 0;
}