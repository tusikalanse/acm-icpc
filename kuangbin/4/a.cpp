#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int MAXN = 2005;
const int INF = 0X3f3f3f3f;

int mp[MAXN][MAXN], dis[MAXN], id[MAXN], flag[MAXN];

bool cmp(int i, int j){
	if(flag[i] == 0 && flag[j] == 0)
		return dis[i] < dis[j];
	if(flag[i])
		return false;
	return true;
}


int main(){
	int t, n, a, b, l;
	memset(dis, INF, sizeof(dis));
	memset(mp, 0, sizeof(mp));
	memset(flag, 0, sizeof(flag));
	dis[1] = 0;
	scanf("%d %d", &t, &n);
	while(t--){
		scanf("%d %d %d", &a, &b, &l);
		if(mp[a][b] > l || mp[a][b] == 0)
		mp[a][b] = mp[b][a] = l;
	}
	int cnt = 1;
	for(int i = 1; i<=n; i++)
		id[i] = i;
	sort(id+1, id+n+1, cmp);
	while(flag[id[1]] == 0 && dis[id[1]] != INF){
		int temp = id[1];
		for(int i = 1; i<=n; i++)
			if(mp[temp][i])
				dis[i] = min(dis[i], dis[temp] + mp[temp][i]);
		flag[temp] = 1;
		sort(id+1, id+n+1, cmp);
	}
	printf("%d\n", dis[n]);
	return 0;
}