#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void EightQueens(int);
int out[50]={0},pre[3][50]={{0}, {0}, {0}};
int tot = 0,cur = 1;
int n;
int main(void)
{
	printf("please input n:");
	scanf("%d",&n);
	EightQueens(1);
	printf("%d",tot);
	return 0;
}
void EightQueens(int cur)
{
	if(cur==n+1)
	{
		for(int i = 1;i<n+1;i++)
		{
			for(int j = 1;j<n+1;j++)
			{
				if(out[i]==j) printf("X ");
				else printf("O ");
				if (j==n) putchar('\n');
			}
		}
		putchar('\n');
		tot++;
	}
	else
	{
		for (int i = 1;i<=n;i++)
		{
			if(!pre[0][i] && !pre[1][cur+i] && !pre[2][cur+n-i])
			{
				out[cur] = i;
				pre[0][i] = 1;
				pre[1][cur+i] = 1;
				pre[2][cur+n-i] = 1;
				EightQueens(cur+1);
				pre[0][i] = 0;
				pre[1][cur+i] = 0;
				pre[2][cur+n-i] = 0;
			}
		}
	}
}
