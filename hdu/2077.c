#include <stdio.h>
#include <math.h>
int main(void)
{
	int m,n;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&m);
		printf("%d\n",(int)pow(3,m-1)+1);
	}
	return 0;
}

