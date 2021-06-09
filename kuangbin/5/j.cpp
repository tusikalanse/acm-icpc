#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int fa[4005];

int Find(int x){
	return x == fa[x] ? x : fa[x] = Find(fa[x]);
}

void Unite(int x, int y){
	int fx = Find(x), fy = Find(y);
	if(fx != fy)
		fa[fx] = fy;
}

bool Judge(int x, int y){
	int fx = Find(x), fy = Find(y);
	return !(fx == fy);
}


int main(){
	int t, n, m, cas = 1, a, b;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &m);
		for(int i = 1; i <= 2 * n; i++){
			fa[i] = i;
		}
		bool flag = 1;
		while(m--){
			scanf("%d %d", &a, &b);
			if(Judge(a, b) || Judge(a + n, b + n)){
				Unite(a, b + n);
				Unite(a + n, b);
			}
			else flag = 0;
		}
		printf("Scenario #%d:\n", cas++);
		if(flag)
			printf("No s");
		else
			printf("S");
		puts("uspicious bugs found!\n");
	}
	return 0;
}