#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int mp[10][10];
int vis[10];
int n, k, ans;

void dfs(int id, int num){
	if(num == 0){
		ans++;
		return;
	}
	if(n - id + 1 < num) return;
	for(int j = 1; j<=n; j++){
		if(!mp[id][j] && !vis[j]){
			vis[j] = 1;
			dfs(id + 1, num - 1);
			vis[j] = 0;
		}
	}
	dfs(id + 1, num);
	return;
}

int main()
{
	char ch;
	while(~scanf("%d %d", &n, &k) && ~n){
		ans = 0;
		memset(vis, 0, sizeof(vis));
		memset(mp, 0, sizeof(mp));
		getchar();
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=n; j++){
				ch = getchar();
				if(ch == '.')
					mp[i][j] = -1;
			}
			getchar();
		}
		dfs(1, k);
		printf("%d\n", ans);
	}
	return 0;
}