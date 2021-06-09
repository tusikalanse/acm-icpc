#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;
const int MAXN = 105;

int fa[MAXN];
double ans;
double x[MAXN], y[MAXN], z[MAXN], r[MAXN];

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
	int x, y;
	double len;
	bool operator < (const node &rhs)const{
		return len > rhs.len;
	}
}temp;

void init(int n){
	ans = 0;
	for(int i = 1; i<=n; i++)
		fa[i] = i;
}

double dis(double dx, double dy, double dz, double sumr){
	double ans;
	ans = sqrt(dx * dx + dy * dy + dz * dz) - sumr;
	return max(ans, 0.0);
}

int main(){
	int n;
	while(~scanf("%d", &n) && n){
		init(n);
		priority_queue<node> q;
		for(int i = 1; i<=n; i++){
			scanf("%lf %lf %lf %lf", &x[i], &y[i], &z[i], &r[i]);
		}
		for(int i = 1; i<n; i++){
			for(int j = i + 1; j<=n; j++){
				temp.x = i;
				temp.y = j;
				temp.len = dis(x[i]-x[j], y[i]-y[j], z[i]-z[j], r[i]+r[j]);
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
		printf("%.3lf\n", ans);
	}
	return 0;
}