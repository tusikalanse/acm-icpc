#include <stdio.h>
int main(void)
{
	int n,t;
	while (scanf("%d",&n)&&n)
	{
		int count=0;
		while(n--)
		{
				scanf("%d",&t);
				count+=t/100;
				t%=100;
				count+=t/50;
				t%=50;
				count+=t/10;
				t%=10;
				count+=t/5;
				t%=5;
				count+=t/2;
				t%=2;
				count+=t;
		}
			printf("%d\n",count);
	}
return 0;
}		
