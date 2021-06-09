#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int fa[106], a[106], b[106], vis[106], in[106];

int Find(int x){
	return x == fa[x]? x: fa[x] = Find(fa[x]);
}

void Unite(int x, int y){
	int fx = Find(x), fy = Find(y);
	if(fx != fy)
		fa[fy] = fx;
}

int main(){
	int flag, mmax, cas = 1;
	while(~scanf("%d %d", &a[0], &b[0]) && ~a[0]){
		int cnt = 1, node = 0;
		if(a[0] == 0){
			printf("Case %d is a tree.\n", cas++);
			continue;
		}
		memset(vis, 0, sizeof(vis));
		memset(in, 0, sizeof(in));
		flag = 1;
		mmax = max(a[0], b[0]);
		vis[a[0]] = vis[b[0]] = 1;
		do{
			scanf("%d %d", &a[cnt], &b[cnt]);
			if(a[cnt] == 0) break;
			vis[a[cnt]] = vis[b[cnt]] = 1;
			mmax = max(max(mmax, a[cnt]), b[cnt]);
			cnt++;
		}while(true);
		for(int i = 1; i<=mmax; i++)
			fa[i] = i;
		int k = 0;
		for(int i = 0; i<cnt; i++){
			in[b[i]]++;
			if(Find(a[i]) == Find(b[i])){
				flag = 0;
				break;
			}
			else Unite(a[i], b[i]);
		}
		for(int i = 1; i<=mmax; i++){
			if(vis[i]){
				node++;
				if(Find(i) == i)
					k++;
				if(in[i] > 1) {
					flag = 0;
					break;
				}
			}
		}
		if(k != 1 || node != cnt+1) flag = 0;
		if(flag)
			printf("Case %d is a tree.\n", cas++);
		else
			printf("Case %d is not a tree.\n", cas++);
	}
	return 0;
}