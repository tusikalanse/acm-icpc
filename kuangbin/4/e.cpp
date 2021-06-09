#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

double R[105][105], C[105][105], mp[105], d[105];
int n, m, s;
double v;

int floyd(){
	for(int i = 1; i <= n; i++) d[i] = mp[i];
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(mp[j] < (mp[i] - C[i][j]) * R[i][j])
					mp[j] = (mp[i] - C[i][j]) * R[i][j];
			}
		}
	}
	for(int i = 1; i <= n; i++){
		if(d[i] < mp[i]) return 1;
	}
	return 0;
}

int main(){
	scanf("%d%d%d%lf", &n, &m, &s, &v);
	int a, b;
	double c, d, e, f;
	while(m--){
		scanf("%d %d %lf %lf %lf %lf", &a, &b, &c, &d, &e, &f);
		R[a][b] = c;
		C[a][b] = d;
		R[b][a] = e;
		C[b][a] = f;
	}
	mp[s] = v;
	floyd();
	if(floyd()) puts("YES");
	else puts("NO");
	return 0;
}