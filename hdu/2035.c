#include <stdio.h>
int main(void)
{
	int n,m;
	while((scanf("%d %d",&n,&m))&&(m||n))
	{
		int a=n;
		n%=1000;
		while(--m)
		{
			n=n*a;
			n%=1000;
		}
		printf("%d\n",n);
	}
	return 0;
}

