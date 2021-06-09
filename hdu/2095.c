#include <stdio.h>
int main(void)
{
	int n,i,ans,t;
	while(scanf("%d",&n)&&n)
	{
		ans=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&t);
			ans=ans^t;
		}
		printf("%d\n",ans);
	}
	return 0;
}

