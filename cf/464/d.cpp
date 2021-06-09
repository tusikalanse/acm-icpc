#include <bits/stdc++.h>
using namespace std;

int fa[27], rt[27];
char lst1[100005], lst2[100005]; 
int ans = 0, cnt = 0, vis[27];


int Find(int x){
	int i = x;
	while(fa[i] != i)
		i = fa[i];
	x = i;
	return i;
}

void Uinte(int x, int y){
	int fx = Find(x), fy = Find(y);
	if(fx != fy)
		fa[fx] = fy;
}

int main(){
	int n;
	memset(rt, 0, sizeof(rt));
	memset(fa, 0, sizeof(fa));
	memset(vis, 0, sizeof(vis));
	scanf("%d %s %s", &n, lst1, lst2);
	for(int i = 0; i<27; i++) fa[i] = i;
	for(int i = 0; i<n; i++){
		Uinte(lst1[i] - 'a', lst2[i] - 'a');
		vis[lst1[i] - 'a'] = 1;
		vis[lst2[i] - 'a'] = 1;
	}
	for(int i = 0; i<26; i++)
		rt[Find(i)] = 1;
	for(int i = 0; i<26; i++){
		if(rt[i] && vis[i]) ans++;
		if(vis[i]) cnt++;
	}
	//printf("%d %d\n", ans, cnt);
	ans = cnt - ans;
	printf("%d\n", ans);
	for(int i = 0; i<26; i++){
		if(Find(i) != i)
			printf("%c %c\n", i+'a', Find(i)+'a');
	}
	return 0;
}