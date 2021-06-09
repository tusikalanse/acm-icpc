#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 1005;
struct g
{
	int w = 0, v = 0;
}girls[MAXN][MAXN], girl[MAXN];
int father[MAXN], dp[MAXN];
int Find(int x){
	int i = x;
	while(father[i]!=i)
		i = father[i];
	father[x] = i;
	return i;
}

void unite(int x, int y){
	int fx = Find(x), fy = Find(y);
	if (fx != fy) father[fx] = fy;
}

int main(){
	int n, m, w, x, y;
	scanf("%d %d %d", &n, &m, &w);
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i<=n; i++) {father[i] = i; scanf("%d", &girl[i].w);}
	for(int i = 1; i<=n; i++) scanf("%d", &girl[i].v);
	for(int i = 0; i<m; i++) {
		scanf("%d %d", &x, &y);
		unite(x, y);
	}
	for(int i = 1; i<=n; i++) {
		girls[Find(i)][0].w += girl[i].w;
		girls[Find(i)][0].v += girl[i].v;
		girls[Find(i)][i].w = girl[i].w;
		girls[Find(i)][i].v = girl[i].v;
	}
	for (int i = 1; i<=n; i++){
		for(int j = w; j>=0; j--){
			for(int k = 0; k<=n; k++){
				if (j >= girls[i][k].w && dp[j-girls[i][k].w] + girls[i][k].v > dp[j])
					dp[j] = dp[j-girls[i][k].w] + girls[i][k].v;
			}
		}			
	}
	int out = 0;
	for(int i = 0; i<=w; i++) out = max(out, dp[i]); 
	printf("%d\n", out);
	
	return 0;
}
