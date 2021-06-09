#include <stdio.h>
int main(void)
{
	int n,m;
	double t,max;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&m);
		max=0.00;
		while(m--)
		{
			scanf("%lf",&t);
			max=max>t?max:t;
		}
		printf("%.2lf\n",max);
	}
	return 0;
}

