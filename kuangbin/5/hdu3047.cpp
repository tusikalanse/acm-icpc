#include <cstdio>
#include <cstring>
using namespace std;

int fa[50005], rank[50005];
int ans = 0, n, m, s, a, b;

int Find(int x){
	if (fa[x] == x) return x;
	int t = fa[x];
	fa[x] = Find(fa[x]);
	rank[x] += rank[t];
	return fa[x];
}

int Unite(int x, int y, int s){
	int fx = Find(x), fy = Find(y);
	if(fx == fy){
		if(s == rank[y] - rank[x])
			return 0;
		return 1;
	}
	fa[fy] = fx;
	rank[fy] = rank[x] - rank[y] + s;
	return 0;
}

int main(){
	while(~scanf("%d %d", &n, &m)){
		ans = 0;
		for(int i = 0; i<=n; i++){
			fa[i] = i;
			rank[i] = 0;
		}
		while(m--){
			scanf("%d %d %d", &a, &b, &s);
			ans += Unite(a, b, s);
		}
		printf("%d\n", ans);
	}
	return 0;
}