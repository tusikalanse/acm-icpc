#include <stdio.h>

int mat[1002][1002];
int row[1002], col[1002], sumx[1002], sumy[1002];
int main(){
	int t, n, m, q, c, x, y, temp;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d", &n, &m, &q);
		for(int i = 0; i<1002; i++){
			row[i] = col[i] = i;
			sumx[i] = sumy[i] = 0;
		}
		for(int i = 1; i<=n; i++)
			for(int j = 1; j<=m; j++)
				scanf("%d", &mat[i][j]);
		while(q--){
			scanf("%d %d %d", &c, &x, &y);
			switch(c){
				case 1:
					temp = row[x]; row[x] = row[y]; row[y] = temp;
					temp = sumx[x]; sumx[x] = sumx[y]; sumx[y] = temp;
					break;
				case 2:
					temp = col[x]; col[x] = col[y]; col[y] = temp;
					temp = sumy[x]; sumy[x] = sumy[y]; sumy[y] = temp;
					break;
				case 3:
					sumx[x] += y;
					break;
				case 4:
					sumy[x] += y;
					break;
				}
			}
		for(int i = 1; i<=n; i++)
			for(int j = 1; j<=m; j++)
				printf("%d%c", mat[row[i]][col[j]]+sumx[i]+sumy[j], j==m?'\n':' ');
}			
	return 0;
}
