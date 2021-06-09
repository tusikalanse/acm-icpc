#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int fa[1005], ok[1005], x[1005], y[1005];

int Find(int x){
	return x == fa[x] ? x : fa[x] = Find(fa[x]);
}

void Unite(int x, int y){
	int fx = Find(x), fy = Find(y);
	if(fx != fy)
		fa[fx] = fy;
}

double ht(double a, double b){
	return sqrt(a * a + b * b);
}

int main(){
	int n, d, a, b;
	char ch[5];
	scanf("%d %d", &n, &d);
	memset(ok, 0, sizeof(ok));
	for(int i = 1; i<=n; i++){
		fa[i] = i;
		scanf("%d %d", &x[i], &y[i]);
	}
	while(~scanf("%s", ch)){
		if(ch[0] == 'O'){
			scanf("%d", &a);
			ok[a] = 1;
			for(int i = 1; i<=n; i++){
				if(ok[i] && ht((double)(x[i] - x[a]), (double)(y[i] - y[a]))<=(double)d)
					Unite(i, a);
			}
		}
		else if(ch[0] == 'S'){
			scanf("%d %d", &a, &b);
			if(Find(a) == Find(b)){
				puts("SUCCESS");
			}
			else 
				puts("FAIL");
		}
	}
	return 0;
}