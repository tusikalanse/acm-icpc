#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

int fa[10010], r[10010];

int Find(int x){
	if(fa[x] == x) return x;
	int t = fa[x];
	fa[x] = Find(fa[x]);
	r[x] = r[x] ^ r[t];
	return fa[x];
}

int Union(int x, int y, int d){
	int fx = Find(x), fy = Find(y);
	if(fx == fy){
		if(r[x] ^ r[y] != d) return 1;
		return 0;
	}
	fa[fy] = fx;
	r[fy] = r[y] ^ d ^ r[x];
	return 0;
}


int main(){
	map<int, int> mp;
	int n, m, ans = 0, cnt = 1, x, y, d;
	char ch[10];
	scanf("%d %d", &n, &m);
	for(int i = 0; i<10010; i++){
		fa[i] = i;
		r[i] = 0;
	}
	for(int i = 1; i<=m; i++){
		scanf("%d %d %s", &x, &y, ch);
		d = (ch[0] == 'o');
		if(!mp[x-1])
			mp[x-1] = cnt++;
		if(!mp[y])
			mp[y] = cnt++;
		if(Union(mp[x-1], mp[y], d) && !ans)
			ans = i;
	}
	if(!ans)
		ans = m+1;
	printf("%d\n", ans - 1);



	return 0;
}