#include <stdio.h>
int main(void)
{
	int n,a,b,c;
	while(scanf("%d",&n)&&n)
	{
		a=n/1000+(n%1000)/100+(n%100)/10+n%10;
		b=n/4096+(n%4096)/256+(n%256)/16+n%16;
		c=n/1728+(n%1728)/144+(n%144)/12+n%12;
		printf("%d is %sa Sky Number.\n",n,a==b&&b==c?"":"not ");
	}
	return 0;
}

