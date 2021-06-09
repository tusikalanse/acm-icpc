#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int list[102][102], a[102][102];
int main(){
	int t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		memset(list, 0, sizeof(list));
		memset(a, 0, sizeof(a));
		for(int i = 1; i<=n; i++)
			for(int j = 1; j<=i; j++)
				scanf("%d", &a[i][j]);
		list[1][1] = a[1][1];
		for(int i = 2; i<=n; i++)
			for(int j = 1; j<=i; j++)
				list[i][j] = max(list[i-1][j-1], list[i-1][j]) + a[i][j];
		int ans = 0;
		for(int i = 1; i<=n; i++) ans = max(ans, list[n][i]);
		printf("%d\n", ans);
	}
	return 0;
}
