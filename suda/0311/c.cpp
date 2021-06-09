#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int g[105], vis[105];
int n, k, s, t;

int main(){
	char ch;
	scanf("%d %d", &n, &k);
	getchar();
	memset(vis, 0, sizeof(vis));
	for(int i = 1; i<=n; i++){
		ch = getchar();
		if(ch == '#')
			vis[i] = 1;
		else if(ch == 'G'){
			vis[i] = 1;
			s = i;
		}	
		else if(ch == 'T'){
			t = i;
		}
	}
	int flag = 0;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		if(u == t){
			flag = 1;
			break;
		}
		if(u + k <= n && !vis[u+k]){
			vis[u+k] = 1;
			q.push(u+k);
		}
		if(u - k > 0 && !vis[u-k]){
			vis[u-k] = 1;
			q.push(u-k);
		}
	}
	puts(flag?"YES":"NO");
	return 0;
}