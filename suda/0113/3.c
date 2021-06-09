#include <stdio.h>

int main(){
	int mat[121][121] = {0};
	for (int i = 1; i<=120; i++) mat[1][i] = mat[i][1] = 1;
	for (int i = 2; i<=120; i++)
		for (int j = 2; j<=120; j++)
			if(i == j) mat[i][j] = mat[i][j-1] + 1;
			else if(i < j) mat[i][j] = mat[i][i];
			else mat[i][j] = mat[i-j][j] + mat[i][j-1];
	int n;
	while(~scanf("%d", &n)){
		printf("%d\n", mat[n][n]);
	}
	
	return 0;
}
