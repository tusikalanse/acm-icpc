#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
const int MAXN = 110;

struct node
{
	int x, y;
	double len;
	bool operator < (const node &rhs) const{
		return len > rhs.len;
	}
}temp;

int fa[MAXN], n;
double x[MAXN], y[MAXN];

int Find(int x){
	return x == fa[x]? x: fa[x] = Find(fa[x]);
}

void Union(int x, int y){
	int fx = Find(x), fy = Find(y);
	if(fx != fy)
		fa[fx] = fy;
}

double Kruskal(priority_queue<node> q){
	double res = 0;
	int cnt = 1;
	while(cnt != n && !q.empty()){
		node u = q.top();
		q.pop();
		if(Find(u.x) == Find(u.y))
			continue;
		cnt++;
		res += u.len;
		Union(u.x, u.y);
	}
	if(cnt != n) return 0.0;
	return res;
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		priority_queue<node> q;
		scanf("%d", &n);
		for(int i = 1; i<=n; i++){
			fa[i] = i;
			scanf("%lf %lf", &x[i], &y[i]);
			for(int j = 1; j<i; j++){
				double dis = sqrt((x[i] -x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
				if(dis >= 10.0 && dis <= 1000.0){
					temp.x = i;
					temp.y = j;
					temp.len = dis;
					q.push(temp);
				}
			}
		}
		double ans = Kruskal(q);
		if(ans == 0.0) puts("oh!");
		else printf("%.1lf\n", ans*100);
	}
	return 0;
}