#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int mp[101][101];

int main(){
	int n, m, x, y;
	memset(mp, 0, sizeof(mp));
	scanf("%d %d", &n, &m);
	while(m--){
		scanf("%d %d", &x, &y);
		mp[x][y] = 1;
	}
	for(int k = 1; k<=n; k++){
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=n; j++){
				mp[i][j] = mp[i][j] || (mp[i][k] && mp[k][j]);
			}
		}
	}
	int ans = 0, t;
	for(int i = 1; i<=n; i++){
		t = 0;
		for (int j = 1; j<=n; j++)
		{
			if(i == j) continue;
			if(mp[i][j] || mp[j][i])
				t++;
		}
		if(t == n-1)
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}