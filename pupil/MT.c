#include <stdio.h>
int mat[8][8] = {0};
int out[64] = {0};
int n, tot = 0;
void MT(int step, int x, int y);
int main(void)
{
	int x, y;
	printf("please input the size of the chessboard:");
	scanf("%d", &n);
	printf("please input the coordinate of the knight(from 0 to size-1):");
	scanf("%d %d", &x, &y);
	mat[x][y]=1;
	out[0]=x*10 + y;
	MT(1, x, y);
	printf("%d\n",tot);
	return 0;
}
void MT(int step, int x, int y)
{
	if (step == n*n)
	{
		for(int i = 0;i < n*n;i++)
			printf("(%d,%d) ",out[i]/10, out[i]%10);
		putchar('\n');
		tot++;
	}
	else
		for(int i = -2;i < 3;i++)
			for (int j = -2;j < 3;j++)
			{
				if((i+j)%2 && i && j)
					if(x+i>=0 && x+i<n && y+j>=0 && y+j<n)
						if(!mat[x+i][y+j])
						{
							out[step] = (x+i)*10 + y+j; 
							mat[x][y] = 1;
							MT(step+1, x+i, y+j);
							mat[x][y] = 0;
						}
 			}
}
