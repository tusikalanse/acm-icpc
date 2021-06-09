#include <stdio.h>
int main(void)
{
	int m,n,t;
	while(scanf("%d %d",&n,&m)&&(n||m))
	{
		int i=0,flag=0;
		while(i<=n)
		{
			scanf("%d",&t);
			if (t<m||flag)
				what:printf("%d%s",t,i==n?"\n":" ");
			else
			{	
				printf("%d%s",m,i==n?"\n":" ");
				flag=1;
				goto what;
			}
			i++;
		}
	}
	return 0;
}
				
