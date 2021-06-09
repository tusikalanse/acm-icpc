#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct d{int w, fa;}dp[11][101], ans;
int row, col, c;

void Find(struct d name, int c, int flag){
	if(flag){
		Find(dp[name.fa][c], c, 0);
	}
	else if (c == 1) return;
	else Find(dp[name.fa][c-1], c-1, 0);
	printf("%d", name.fa);
	if (!flag) printf(" ");
	};


int a[11][101];
int main(){
	while(~scanf("%d %d", &row, &col)){
		for(int i = 1; i<=row; i++){
			for(int j = 1; j<=col; j++){
				scanf("%d", &a[i][j]);
				dp[i][j].w = 0;
			}
			dp[i][1].w = a[i][1];
		}
		for(int j = 2; j <= col; j++)
			for(int i = 1; i <= row; i++){
				if (row == 1){
					dp[i][j].w = dp[i][j-1].w + a[i][j];
					dp[i][j].fa = i;			
				}
				else if (i == 1){
					dp[i][j].w = dp[i][j-1].w;
					dp[i][j].fa = i;
					if (dp[i+1][j-1].w < dp[i][j].w){ dp[i][j].w = dp[i+1][j-1].w; dp[i][j].fa = i+1;}
					if (dp[row][j-1].w < dp[i][j].w){ dp[i][j].w = dp[row][j-1].w; dp[i][j].fa = row;}
					dp[i][j].w += a[i][j];
				}
				else if (i == row){
					dp[i][j].w = dp[1][j-1].w;
					dp[i][j].fa = 1;
					if (dp[i-1][j-1].w < dp[i][j].w){ dp[i][j].w = dp[i-1][j-1].w; dp[i][j].fa = i-1;}
					if (dp[i][j-1].w < dp[i][j].w){ dp[i][j].w = dp[i][j-1].w; dp[i][j].fa = i;}
					dp[i][j].w += a[i][j];
				}
				else {
					dp[i][j].w = dp[i-1][j-1].w;
					dp[i][j].fa = i-1;
					if (dp[i][j-1].w < dp[i][j].w){ dp[i][j].w = dp[i][j-1].w; dp[i][j].fa = i;}
					if (dp[i+1][j-1].w < dp[i][j].w){ dp[i][j].w = dp[i+1][j-1].w; dp[i][j].fa = i+1;}
					dp[i][j].w += a[i][j];
				}
			}
			ans.w = dp[1][col].w;
			ans.fa = 1;
			for(int i = 2; i<=row; i++)
				if (dp[i][col].w < ans.w){
					ans.w = dp[i][col].w;
					ans.fa = i;
				}
		c = col;
		Find(ans, c, 1);
		printf("\n%d\n", ans.w);
	}
	
	
	
	
	return 0;
}
