#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int n,m,i;
	while(scanf("%d %d",&n,&m)&&(n||m))
	{
		int *list;
		list=(int*)malloc(n*sizeof(int));
		for(i=0;i<n;i++)
			scanf("%d",(list+i));
		i=0;
		int flag=0;
		while(i<=n)
		{
			if(*(list+i)<m||flag==1)
			{
				printf("%d%s",list[i-flag],i==n?"\n":" ");
			}
			else
			{
				printf("%d%s",m,i==n?"\n":" ");
				flag=1;
			}
			i++;
		}
	}	
	return 0;
}

