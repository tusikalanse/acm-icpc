#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int fa[605], ans, vis[605], dp[605][605];
int st[605][2], cnt, pre[605][605];
vector<int> num[605][2];
bool val[605];

int Find(int x){
	if (x == fa[x])
		return x;
	int t = fa[x];
	fa[x] = Find(fa[x]);
	val[x] = val[x] ^ val[t];
	return fa[x];
}

void Unite(int x, int y, int c){
	int fx = Find(x), fy = Find(y);
	if(fx != fy){
		fa[fx] = fa[fy];
		val[fx] = val[x] ^ val[y] ^ c;
	}
}

int main(){
	int n, p1, p2, a, b;
	char s[5];
	while(~scanf("%d %d %d", &n, &p1, &p2)){
		if(n == 0 && p1 == 0 && p2 == 0) break;
		for(int i = 0; i<=p1 + p2; i++){
			fa[i] = i;
			val[i] = 0;
		}
		memset(vis, 0, sizeof(vis));
		cnt = 1;
		while(n--){
			scanf("%d %d %s", &a, &b, s);
			if(s[0] == 'y'){
				Unite(a, b, 0);
			}
			else Unite(a, b, 1);
		}
		for(int i = 0; i<605; i++){
			num[i][0].clear();
			num[i][1].clear();
			st[i][0] = st[i][1] = 0;
		}
		memset(vis, 0, sizeof(vis));
		for(int i = 1; i <= p1 + p2; i++){
			if(!vis[i]){
				int tmp = Find(i);
				for(int j = i; j <= p1 + p2; j++){
					if(Find(j) == tmp){
						vis[j] = 1;
						num[cnt][val[j]].push_back(j);
						st[cnt][val[j]]++;
					}
				}
				cnt++;
			}
		}
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for (int i = 1; i < cnt; ++i){
			for(int j = p1; j>=0; j--){
				if(j - st[i][0] >= 0 && dp[i-1][j-st[i][0]]){
					dp[i][j] += dp[i-1][j-st[i][0]];
					pre[i][j] = j - st[i][0];
				}
				if(j - st[i][1] >= 0 && dp[i-1][j-st[i][1]]){
					dp[i][j] += dp[i-1][j-st[i][1]];
					pre[i][j] = j - st[i][1];
				}
			}
		}
		if(dp[cnt-1][p1] != 1 || p1 == p2)
			puts("no");
		else{
			vector<int> res;
			res.clear();
			int t = p1;
			for(int i = cnt - 1; i>=1; i--){
				int tmp = t - pre[i][t];
				if(tmp == st[i][0]){
					for(int j = 0; j<st[i][0]; j++)
						res.push_back(num[i][0][j]);
				}
				else
					for(int j = 0; j<st[i][1]; j++)
						res.push_back(num[i][1][j]);
				t = pre[i][t];
			}
			sort(res.begin(), res.end());
			for(int i = 0; i<res.size(); i++)
				printf("%d\n", res[i]);
			puts("end");
		}
	}
	return 0;
}