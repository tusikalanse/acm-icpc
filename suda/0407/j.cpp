#include <cstdio>
using namespace std;

char g[10][30];
int d[4] = {1, 6, 13, 18};
int ans[4];

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		for(int i = 1; i <= 7; i++)
			scanf("%s", &g[i][1]);
		for(int k = 0; k < 4; k++) {
			int i = d[k];
			if(g[7][i+1] == 'X') {
				if(g[4][i+1] == 'X') {
					if(g[2][i] == '.') {
						if(g[5][i] == '.')
							ans[k] = 3;
						else
							ans[k] = 2;
					}
					else if(g[2][i+3] == '.') {
						if(g[5][i] == '.') 
							ans[k] = 5;
						else 
							ans[k] = 6;
					}
					else if(g[5][i] == '.')
						ans[k] = 9;
					else
						ans[k] = 8;
				}
				else
					ans[k] = 0;
			}
			else if(g[1][i+1] == 'X') 
				ans[k] = 7;
			else if(g[2][i] == 'X')
				ans[k] = 4;
			else
				ans[k] = 1;
		}
		printf("%d%d:%d%d\n", ans[0], ans[1], ans[2], ans[3]);
	}


	return 0;
}