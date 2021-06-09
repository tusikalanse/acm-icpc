#include <bits/stdc++.h>
using namespace std;

int fa[100006], a[100006], b[100006], vis[100006];

int Find(int x){
	return x == fa[x]? x: fa[x] = Find(fa[x]);
}

void Unite(int x, int y){
	int fx = Find(x), fy = Find(y);
	if(fx != fy)
		fa[fy] = fx;
}

int main(){
	int flag, mmax;
	while(~scanf("%d %d", &a[0], &b[0]) && ~a[0]){
		int cnt = 1;
		if(a[0] == 0){
			puts("Yes");
			continue;
		}
		memset(vis, 0, sizeof(vis));
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
			if(Find(a[i]) == Find(b[i])){
				flag = 0;
				break;
			}
			else Unite(a[i], b[i]);
		}
		for(int i = 1; i<=mmax; i++){
			if(vis[i] && Find(i) == i){
				k++;
			}
		}
		if(k != 1) flag = 0;
		puts(flag?"Yes":"No");
	}
	return 0;
}