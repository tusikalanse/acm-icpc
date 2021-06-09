#include <stdio.h>
int main(void)
{
	int temp,n;
	double a,b,c;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%lf %lf %lf",&a,&b,&c);
		if(a>b)
		{
			temp=a;
			a=b;
			b=temp;
		}
		if(a>c)
		{
			temp=c;
			c=a;
			a=temp;
		}
		if(b>c)
		{
			temp=c;
			c=b;
			b=temp;
		}
		if(a+b>c)
			printf("YES\n");
		else
			printf("NO\n");
	}		
	return 0;
}

