#include <stdio.h>
int main(void)
{
	int n;
	long long g[36]={0,1,4};
	for(int i=3;i<=35;i++)
		g[i]=3*g[i-1]+1;
	while(~scanf("%d",&n))
		printf("%lld\n",g[n]*2);
	return 0;
}

