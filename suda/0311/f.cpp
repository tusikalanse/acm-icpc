#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int n, m, flag, num = 0, s;
int vis[105][105];
char ch;

int main(){
	scanf("%d %d", &n, &m);
	getchar();
	memset(vis, 0, sizeof(vis));
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++){
			ch = getchar();
			if(ch == '-')
				vis[i][j] = -1;
			else 
				num++;
		}
		getchar();
	}
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++){
			if(vis[i][j] == -1)
				putchar('-');
			else{
				if((i+j) & 1)
					putchar('B');
				else
					putchar('W');
			}
		}
		puts("");
	}
	return 0;
}