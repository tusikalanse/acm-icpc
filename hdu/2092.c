#include <stdio.h>
#include <math.h>
int main(void)
{
	int n,m;
	double delta;
	while(scanf("%d %d",&n,&m)&&(m||n))
	{
		int flag=1;
		if(n*n-4*m<0)
			flag=0;
		if(flag)
		{
			if(n*n==4*m)
			{
				if(n%2!=0)
					flag=0;
			}
			else
			{
				delta=sqrt(n*n-4*m);
				if(fabs((n+delta)/2-(int)((n+delta)/2))>1e-6||fabs((n-delta)/2!=(int)((n-delta)/2))>1e-6)
					flag=0;
			}
		}
		if(flag)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}

